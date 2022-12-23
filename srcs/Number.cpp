#include "Number.hpp"
Number::Number(int const &number) : _number(number){};
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
Number::print(void)
{
	std::cout << this->_number;
}
