#include "Mult.hpp"

Mult::Mult(void) { ; }
Mult::~Mult(void) { ; }

int
Mult::eval(void)
{
	return this->get_left().eval() * this->get_right().eval();
}

void
Mult::result(void)
{
	this->print();
	std::cout << " = " << this->eval() << std::endl;
}

void
Mult::print(void)
{
	std::cout << "(";
	this->get_left().print();
	std::cout << " x ";
	this->get_right().print();
	std::cout << ")";
}

char
Mult::getSymbole(void) const
{
	return 'x';
}

char
Mult::getPriority(void) const
{
	return 1;
}

std::ostream &
operator<<(std::ostream &output, Mult &node)
{

	std::cout << node.get_left() << " x " << node.get_right();
	return output;
}
