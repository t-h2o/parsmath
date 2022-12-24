#include "Tokenizer.hpp"
#include "color.hpp"

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
	test("2 x 5 + 3");
	test("2 + 5 x 3");

	return 0;
}
