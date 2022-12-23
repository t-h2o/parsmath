#include "Add.hpp"

Add::Add(void) { this->_isOperator = 1; }
Add::~Add(void) { ; }

int
Add::eval(void)
{
	return this->get_left().eval() + this->get_right().eval();
}

void
Add::print(void)
{
	this->get_left().print();
	std::cout << " + ";
	this->get_right().print();
	std::cout << " = " << this->eval() << std::endl;
}

std::ostream &
operator<<(std::ostream &output, Add &node)
{

	std::cout << node.get_left() << " + " << node.get_right();
	return output;
}
