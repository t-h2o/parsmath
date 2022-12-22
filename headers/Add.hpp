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

std::ostream &
operator<<(std::ostream &output, Add &node)
{

	std::cout << node.get_left() << " + " << node.get_right() << std::endl;
	return output;
}

#endif /* ADD_HPP */
