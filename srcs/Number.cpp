#include "Number.hpp"
Number::Number(int const &number) : _number(number) { ; }
Number::~Number(void){};

int
Number::eval(void)
{
	return _number;
}

void
Number::set_number(int const number)
{
	_number = number;
}

void
Number::result(void)
{
	this->print();
	std::cout << " = " << this->eval() << std::endl;
}

void
Number::print(void)
{
	std::cout << this->_number;
}

std::ostream &
operator<<(std::ostream &output, Number &number)
{
	std::cout << number.eval();
	return output;
}
