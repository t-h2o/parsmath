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
		return 0;
	}
};

#endif /* ADD_HPP */
