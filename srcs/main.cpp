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

static TreeNode *
asdf(TreeNode *parent, char **str)
{
	TreeNode *operation;
	TreeNode *number;

	number = create_token(str);
	operation = create_token(str);

	operation->set_left(number);
	if (parent)
		parent->set_right(operation);

	return operation;
}

static void
test_sum_3_2(char *str)
{
	TreeNode *tree;
	TreeNode *number;

	tree = asdf(0, &str);

	asdf(tree, &str);

	number = create_token(&str);

	tree->get_right().set_right(number);

	section("print");
	tree->print();
	section("tree");
	tree->tree();

	delete tree;
}

static void
test_sum_5(char *str)
{
	section(str);
	TreeNode *tree;
	TreeNode *number;
	TreeNode *sum1;
	TreeNode *sum2;
	TreeNode *sum3;

	number = create_token(&str);
	tree = create_token(&str);
	tree->set_left(number);

	number = create_token(&str);
	sum1 = create_token(&str);
	sum1->set_left(number);

	number = create_token(&str);
	sum2 = create_token(&str);
	sum2->set_left(number);

	number = create_token(&str);
	sum3 = create_token(&str);
	sum3->set_left(number);

	number = create_token(&str);

	sum3->set_right(number);

	sum2->set_right(sum3);

	sum1->set_right(sum2);

	tree->set_right(sum1);

	section("print");
	tree->print();
	section("tree");
	tree->tree();

	delete tree;
}

static void
test_sum_4(char *str)
{
	section(str);
	TreeNode *tree;
	TreeNode *number;
	TreeNode *sum1;
	TreeNode *sum2;

	number = create_token(&str);
	tree = create_token(&str);
	tree->set_left(number);

	number = create_token(&str);
	sum1 = create_token(&str);
	sum1->set_left(number);

	number = create_token(&str);
	sum2 = create_token(&str);
	sum2->set_left(number);

	number = create_token(&str);

	sum2->set_right(number);

	sum1->set_right(sum2);

	tree->set_right(sum1);

	section("print");
	tree->print();
	section("tree");
	tree->tree();

	delete tree;
}

static void
test_sum_3(char *str)
{
	section(str);
	TreeNode *tree;
	TreeNode *number;
	TreeNode *sum;

	number = create_token(&str);
	tree = create_token(&str);
	tree->set_left(number);

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
	section(str);
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
	test_sum_3((char *)"1+2+3");
	test_sum_3((char *)"123+431+111");

	test_sum_4((char *)"1+2+3+4");

	test_sum_5((char *)"1+2+3+4+5");

	test_sum_3_2((char *)"1 + 2 + 3");

	return 0;
}
