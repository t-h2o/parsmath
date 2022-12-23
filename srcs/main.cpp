#include "Add.hpp"
#include "Number.hpp"
#include "color.hpp"
#include <cctype>
#include <iostream>
#include <stdlib.h>

static TreeNode *
create_token(char **str)
{
	int number;

	while (isspace(**str))
		++(*str);

	if (isdigit(**str))
	{
		number = atoi(*str);
		while (isdigit(**str))
			++(*str);
		return new Number(number);
	}
	if (**str == '+')
	{
		++(*str);
		return new Add();
	}
	return 0;
}

static int
qwer(TreeNode **parent, char **str, TreeNode **number)
{
	TreeNode *operation;

	*number = create_token(str);
	operation = create_token(str);

	if (operation == 0)
		return 1;

	operation->set_left(*number);
	if (parent && *parent)
		(*parent)->set_right(operation);

	*parent = operation;

	return 2;
}

static void
test_sum(char *str)
{
	TreeNode *tree;
	TreeNode *next;
	TreeNode *number;

	message(str);
	tree = 0;
	if (qwer(&tree, &str, &number) == 2)
	{
		next = tree;
		while (qwer(&next, &str, &number) == 2)
			;
	}
	else
		next = tree;

	next->set_right(number);

	section("tree");
	tree->tree();

	tree->print();
	delete tree;
}

int
main(void)
{
	title("Parsmath");

	title("Sum");
	test_sum((char *)"1 + 2");
	test_sum((char *)"1 + 2 + 3 + 4");
	test_sum((char *)"1 + 2 + 3 + 4 + 5");
	test_sum((char *)"1 + 2 + 3 + 4 + 5 + 6");

	return 0;
}
