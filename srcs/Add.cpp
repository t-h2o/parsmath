#include "Add.hpp"

Add::Add(void) { ; }
Add::~Add(void) { ; }

int
Add::eval(void)
{
	return this->get_left().eval() + this->get_right().eval();
}

void
Add::result(void)
{
	this->print();
	std::cout << " = " << this->eval() << std::endl;
}

void
Add::print(void)
{
	if (this->getParenthesis())
		std::cout << "(";
	this->get_left().print();
	std::cout << " + ";
	this->get_right().print();
	if (this->getParenthesis())
		std::cout << ")";
}

char
Add::getSymbole(void) const
{
	return '+';
}

char
Add::getPriority(void) const
{
	return 0;
}

std::ostream &
operator<<(std::ostream &output, Add &node)
{

	std::cout << node.get_left() << " + " << node.get_right();
	return output;
}
