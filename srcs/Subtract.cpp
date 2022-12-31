#include "Subtract.hpp"

Subtract::Subtract(void) { ; }
Subtract::~Subtract(void) { ; }

int
Subtract::eval(void)
{
	return this->get_left().eval() - this->get_right().eval();
}

void
Subtract::result(void)
{
	this->print();
	std::cout << " = " << this->eval() << std::endl;
}

void
Subtract::print(void)
{
	if (this->getParenthesis())
		std::cout << "(";
	this->get_left().print();
	std::cout << " - ";
	this->get_right().print();
	if (this->getParenthesis())
		std::cout << ")";
}

char
Subtract::getSymbole(void) const
{
	return '-';
}

char
Subtract::getPriority(void) const
{
	return 0;
}

std::ostream &
operator<<(std::ostream &output, Subtract &node)
{

	std::cout << node.get_left() << " - " << node.get_right();
	return output;
}
