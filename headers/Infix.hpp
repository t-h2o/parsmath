#ifndef INFIX_HPP
#define INFIX_HPP

#include "Number.hpp"
#include "TreeNode.hpp"

class Infix : public TreeNode
{
  public:
	virtual ~Infix(void);

	virtual char getSymbole(void) const = 0;
	virtual char getPriority(void) const = 0;
};

#endif /* INFIX_HPP */
