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
test_sum(char *str)
{
	TreeNode *number;
	TreeNode *sum;

	number = create_token(&str);
	sum = create_token(&str);

	sum->set_left(number);
	number = create_token(&str);

	sum->set_right(number);

	sum->print();

	delete sum;
}

static void
test(void)
{
	TreeNode *sum = new Add();
	sum->set_left(32);
	sum->set_right(10);

	sum->print();
	delete sum;
}

int
main(void)
{
	title("Parsmath");

	test();
	test_sum((char *)"1 + 2");

	return 0;
}
