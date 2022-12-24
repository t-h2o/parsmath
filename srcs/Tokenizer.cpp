#include "Tokenizer.hpp"

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
		_nodes.push_back(_create_token(exp));
	} while (_nodes.back());
	_nodes.pop_back();

	_nodes.at(1)->set_left(_nodes.at(0));
	_nodes.at(1)->set_right(_nodes.at(2));

	index = 3;

	while (index < _nodes.size() && _nodes.at(index)->isOperator() == 1
		   && _nodes.at(index + 1)->isOperator() == 0)
	{
		_nodes.at(index)->set_left(_nodes.at(index - 2));
		_nodes.at(index)->set_right(_nodes.at(index + 1));
		index += 2;
	}

	return _nodes.at(index - 2);
}
