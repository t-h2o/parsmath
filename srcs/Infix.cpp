#include "Infix.hpp"

Infix::Infix(void) : _parenthesis(0) { ; }

Infix::~Infix(void) { ; }

void
Infix::setParenthesis(void)
{
	this->_parenthesis = true;
}

bool
Infix::getParenthesis(void) const
{
	return this->_parenthesis;
}
