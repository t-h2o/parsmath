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
	std::cout << sum->eval() << std::endl;
	delete sum;
}

int
main(void)
{
	title("Parsmath");

	test();

	return 0;
}
