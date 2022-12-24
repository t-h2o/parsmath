#include "Add.hpp"
#include "Input.hpp"
#include "Number.hpp"
#include "Subtract.hpp"
#include "Tokenizer.hpp"
#include "color.hpp"
#include <cctype>
#include <iostream>

static void
test(Input exp)
{
	section(exp.getInput());

	TreeNode *tree = Tokenizer::generate_tree(exp);

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
