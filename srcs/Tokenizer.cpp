#include "Tokenizer.hpp"
#include "color.hpp"

TreeNode *
Tokenizer::_create_token(Input &exp)
{
	int number;

	while (isspace(exp.getChar()))
		exp.incIndex();

	if (isdigit(exp.getChar()))
	{
		number = exp.getNumber();
		while (isdigit(exp.getChar()))
			exp.incIndex();
		return new Number(number);
	}
	else if (exp.getChar() == '+')
	{
		exp.incIndex();
		return new Add();
	}
	else if (exp.getChar() == '-')
	{
		exp.incIndex();
		return new Subtract();
	}
	else if (exp.getChar() == 'x')
	{
		exp.incIndex();
		return new Mult();
	}
	else if (isalpha(exp.getChar()))
		throw BadExpression();
	else
		return 0;
}

TreeNode *
Tokenizer::generate_tree(Input exp)
{
	std::vector<TreeNode *> _nodes;
	size_t					index;

	do
	{
		try
		{
			_nodes.push_back(_create_token(exp));
		}
		catch (const Tokenizer::BadExpression &error)
		{
			print_exception(error.what());
			return 0;
		}
	} while (_nodes.back());
	_nodes.pop_back();

	index = 0;
	while (index < _nodes.size())
	{
		Infix *operation = dynamic_cast<Infix *>(_nodes.at(index));
		if (operation == 0)
			;
		else if (operation->getPriority() == 1)
		{
			operation->set_left(_nodes.at(index - 1));
			operation->set_right(_nodes.at(index + 1));
			_nodes.erase(_nodes.begin() + index-- - 1);
			_nodes.erase(_nodes.begin() + index + 1);
		}
		++index;
	}

	index = 0;
	while (index < _nodes.size())
	{
		Infix *operation = dynamic_cast<Infix *>(_nodes.at(index));
		if (operation == 0)
			;
		else if (operation->getPriority() == 0)
		{
			operation->set_left(_nodes.at(index - 1));
			operation->set_right(_nodes.at(index + 1));
			_nodes.erase(_nodes.begin() + index-- - 1);
			_nodes.erase(_nodes.begin() + index + 1);
		}
		++index;
	}
	return _nodes.at(index - 1);
}
