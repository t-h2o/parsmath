#include "Tokenizer.hpp"

void
Tokenizer::create_token(Input &exp, TreeNode **node)
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
	else
		*node = 0;
}
