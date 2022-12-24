#ifndef ADD_HPP
#define ADD_HPP

#include "Infix.hpp"

class Add : public Infix
{
  public:
	Add(void);
	~Add(void);

	int eval(void);

	void print(void);
	void result(void);

	char getSymbole(void) const;
	char getPriority(void) const;
};

std::ostream &operator<<(std::ostream &output, Add &node);

#endif /* ADD_HPP */
