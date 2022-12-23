#include "Infix.hpp"
Infix::Infix(void) : _left(0), _right(0) { ; }
Infix::~Infix(void)
{
	delete this->_left;
	delete this->_right;
}

void
Infix::set_left(int const &number)
{
	this->_left = new Number(number);
}

void
Infix::set_right(int const &number)
{
	this->_right = new Number(number);
}

TreeNode &
Infix::get_left(void)
{
	return *(this->_left);
}

TreeNode &
Infix::get_right(void)
{
	return *(this->_right);
}
