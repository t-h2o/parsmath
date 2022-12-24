#ifndef MULT_HPP
#define MULT_HPP

#include "Infix.hpp"

class Mult : public Infix
{
  public:
	Mult(void);
	~Mult(void);

	int eval(void);

	void print(void);
	void result(void);

	char getSymbole(void) const;
	char getPriority(void) const;
};

std::ostream &operator<<(std::ostream &output, Mult &node);

#endif /* MULT_HPP */
