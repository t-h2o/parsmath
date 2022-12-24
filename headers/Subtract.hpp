#ifndef SUBTRACT_HPP
#define SUBTRACT_HPP

#include "Infix.hpp"

class Subtract : public Infix
{
  public:
	Subtract(void);
	~Subtract(void);

	int eval(void);

	void print(void);
	void result(void);

	char getSymbole(void) const;
	char getPriority(void) const;
};

std::ostream &operator<<(std::ostream &output, Subtract &node);

#endif /* SUBTRACT_HPP */
