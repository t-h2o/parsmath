#include "Div.hpp"

Div::Div(void) { ; }
Div::~Div(void) { ; }

int
Div::eval(void)
{
	return this->get_left().eval() / this->get_right().eval();
}

void
Div::result(void)
{
	this->print();
	std::cout << " = " << this->eval() << std::endl;
}

void
Div::print(void)
{
	std::cout << "(";
	this->get_left().print();
	std::cout << " / ";
	this->get_right().print();
	std::cout << ")";
}

char
Div::getSymbole(void) const
{
	return '/';
}

char
Div::getPriority(void) const
{
	return 1;
}

std::ostream &
operator<<(std::ostream &output, Div &node)
{

	std::cout << node.get_left() << " / " << node.get_right();
	return output;
}
