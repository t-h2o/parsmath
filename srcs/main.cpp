#include "Add.hpp"
#include "Input.hpp"
#include "Number.hpp"
#include "Subtract.hpp"
#include "Tokenizer.hpp"
#include "color.hpp"
#include <cctype>
#include <iostream>

static void
first(Input &exp, TreeNode **operation)
{
	TreeNode *number;

	Tokenizer::create_token(exp, &number);
	Tokenizer::create_token(exp, operation);
	(*operation)->set_left(number);

	Tokenizer::create_token(exp, &number);
	(*operation)->set_right(number);
}

static int
second(Input &exp, TreeNode **child)
{
	TreeNode *number;
	TreeNode *operation;

	Tokenizer::create_token(exp, &operation);
	if (operation == 0)
		return 0;
	Tokenizer::create_token(exp, &number);

	operation->set_left(*child);
	operation->set_right(number);

	*child = operation;
	return 1;
}

static void
test(Input exp)
{
	section(exp.getInput());

	TreeNode *tree;
	first(exp, &tree);
	while (second(exp, &tree))
		;

	tree->result();
	tree->tree();
	delete tree;
}

int
main(int argc, char **argv)
{
	title("Parsmath");

	if (argc >= 2)
	{
		test(argv + 1);
		return (0);
	}
	title("Sum");
	test("100 - 5 - 25");
	test("100 - 5 + 25");
	test("100 + 5 - 25");
	test("100 + 5 + 25");
	test("100 + 5 + 25 + 30 + 40");
	test("100 + 5 + 25 + 30 -2 + 40 -3");

	return 0;
}
