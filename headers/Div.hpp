#ifndef DIV_HPP
#define DIV_HPP

#include "Infix.hpp"

class Div : public Infix
{
  public:
	Div(void);
	~Div(void);

	int eval(void);

	void print(void);
	void result(void);

	char getSymbole(void) const;
	char getPriority(void) const;
};

std::ostream &operator<<(std::ostream &output, Div &node);

#endif /* DIV_HPP */
