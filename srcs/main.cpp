#include "Tokenizer.hpp"
#include "color.hpp"

static void
test(Input expression)
{
	section(expression.getInput());

	TreeNode *tree = Tokenizer::generate_tree(expression);

	if (tree == 0)
		return;
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
	test("1 + 2 + 3 + 4 + 5 - 6 - 7 + 9");
	test("20 x 5 + 3");
	test("2 + 5 x 3");
	test("2 + 5 x 3 - 7");
	test("2 + 5 - 3 x 7");
	test("2 + 5 - 15 / 7");

	return 0;
}
