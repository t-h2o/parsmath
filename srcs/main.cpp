#include "Add.hpp"
#include "Number.hpp"
#include "color.hpp"
#include <iostream>

static void
test(void)
{
	TreeNode *tree = new Add();
	delete tree;
}

int
main(void)
{
	title("Parsmath");

	test();

	return 0;
}
