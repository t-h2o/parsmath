#include "Add.hpp"
#include "Subtract.hpp"
#include "Input.hpp"
#include "Number.hpp"
#include "color.hpp"
#include <cctype>
#include <iostream>

static void
create_token(Input &exp, TreeNode **node)
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

static int
qwer(TreeNode **parent, Input &exp, TreeNode **number)
{
	TreeNode *operation;

	create_token(exp, number);
	create_token(exp, &operation);

	if (operation == 0)
		return 1;

	operation->set_left(*number);
	if (parent && *parent)
		(*parent)->set_right(operation);

	*parent = operation;

	return 2;
}

static void
test_sum(Input exp)
{
	TreeNode *tree;
	TreeNode *next;
	TreeNode *number;

	message(exp.getInput().c_str());
	tree = 0;
	if (qwer(&tree, exp, &number) == 2)
	{
		next = tree;
		while (qwer(&next, exp, &number) == 2)
			;
	}
	else
		next = tree;

	next->set_right(number);

	section("tree");
	tree->tree();

	tree->result();
	delete tree;
}

int
main(int argc, char **argv)
{
	title("Parsmath");

	if (argc >= 2)
	{
		Input input(argv + 1);
		std::cout << input.getChar();
		std::cout << input.getChar();
		std::cout << input.getChar();
		std::cout << input.getChar();
		std::cout << input.getInput();
		return (0);
	}
	title("Sum");
	test_sum("1 + 2 + 3 + 4");
	test_sum("1 + 2 + 3 + 4 + 5");
	test_sum("1 + 2 + 3 + 4 + 5 + 6");
	test_sum("100 - 5");

	return 0;
}
