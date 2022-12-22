#include "Add.hpp"
#include "Number.hpp"
#include "color.hpp"
#include <iostream>

static void
test(void)
{
	Infix *sum = new Add();
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

	return 0;
}
