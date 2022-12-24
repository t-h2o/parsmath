#include "Tokenizer.hpp"

void
Tokenizer::_create_token(Input &exp, TreeNode **node)
{
	int number;

	while (isspace(exp.getChar()))
		exp.incIndex();

	if (isdigit(exp.getChar()))
	{
		number = exp.getNumber();
		while (isdigit(exp.getChar()))
			exp.incIndex();
		*node = new Number(number);
	}
	else if (exp.getChar() == '+')
	{
		exp.incIndex();
		*node = new Add();
	}
	else if (exp.getChar() == '-')
	{
		exp.incIndex();
		*node = new Subtract();
	}
	else if (isalpha(exp.getChar()))
		throw BadExpression();
	else
		*node = 0;
}

void
Tokenizer::_first(Input &exp, TreeNode **operation)
{
	TreeNode *number;

	_create_token(exp, &number);
	_create_token(exp, operation);
	(*operation)->set_left(number);

	_create_token(exp, &number);
	(*operation)->set_right(number);
}

int
Tokenizer::_second(Input &exp, TreeNode **child)
{
	TreeNode *number;
	TreeNode *operation;

	_create_token(exp, &operation);
	if (operation == 0)
		return 0;
	_create_token(exp, &number);

	operation->set_left(*child);
	operation->set_right(number);

	*child = operation;
	return 1;
}

TreeNode *
Tokenizer::generate_tree(Input exp)
{
	TreeNode *tree;

	_first(exp, &tree);
	while (_second(exp, &tree))
		;

	return tree;
}
