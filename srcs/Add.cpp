#include "Add.hpp"

Add::~Add(void) { ; }

int
Add::eval(void)
{
	return this->get_left().eval() + this->get_right().eval();
}

void
Add::print(void)
{
	std::cout << this->get_left() << " + " << this->get_right() << std::endl;
}

std::ostream &
operator<<(std::ostream &output, Add &node)
{

	std::cout << node.get_left() << " + " << node.get_right() << std::endl;
	return output;
}
