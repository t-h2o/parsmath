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

static void
test_sum_3(char *str)
{
	TreeNode *tree;
	TreeNode *number;
	TreeNode *sum;

	number = create_token(&str);
	sum = create_token(&str);
	sum->set_left(number);

	tree = sum;

	number = create_token(&str);
	sum = create_token(&str);
	sum->set_left(number);
	number = create_token(&str);
	sum->set_right(number);

	tree->set_right(sum);

	section("print");
	tree->print();
	section("tree");
	tree->tree();

	delete tree;
}

static void
test_sum_2(char *str)
{
	TreeNode *number;
	TreeNode *sum;

	number = create_token(&str);
	sum = create_token(&str);

	sum->set_left(number);
	number = create_token(&str);

	sum->set_right(number);

	section("print");
	sum->print();
	section("tree");
	sum->tree();

	delete sum;
}

int
main(void)
{
	title("Parsmath");

	test_sum_2((char *)"1 + 2");
	test_sum_2((char *)"42 + 34");
	test_sum_2((char *)"123456+654321");

	test_sum_3((char *)"1 + 2 + 3");

	return 0;
}
