#include "Tokenizer.hpp"
#include "color.hpp"

TreeNode *
Tokenizer::_create_token(Input &expression)
{
	int number;

	while (isspace(expression.getChar()))
		expression.incIndex();

	if (isdigit(expression.getChar()))
	{
		number = expression.getNumber();
		while (isdigit(expression.getChar()))
			expression.incIndex();
		return new Number(number);
	}
	else if (expression.getChar() == '+')
	{
		expression.incIndex();
		return new Add();
	}
	else if (expression.getChar() == '-')
	{
		expression.incIndex();
		return new Subtract();
	}
	else if (expression.getChar() == 'x')
	{
		expression.incIndex();
		return new Mult();
	}
	else if (isalpha(expression.getChar()))
		throw BadExpression();
	else
		return 0;
}

TreeNode *
Tokenizer::generate_tree(Input expression)
{
	std::vector<TreeNode *> _nodes;
	size_t					index;

	do
	{
		try
		{
			_nodes.push_back(_create_token(expression));
		}
		catch (const Tokenizer::BadExpression &error)
		{
			print_exception(error.what());
			std::cout << "'" << expression.getChar() << "' was the problem"
					  << std::endl;
			return 0;
		}
	} while (_nodes.back());
	_nodes.pop_back();

	if (_nodes.size() == 0)
		return 0;

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
