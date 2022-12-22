#ifndef ADD_HPP
#define ADD_HPP

#include "Infix.hpp"

class Add : public Infix
{
  public:
	~Add(void){};

	int
	eval(void)
	{
		return this->_left->eval() + this->_right->eval();
	}
};

#endif /* ADD_HPP */
