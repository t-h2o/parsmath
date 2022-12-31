#ifndef INFIX_HPP
#define INFIX_HPP

#include "Number.hpp"
#include "TreeNode.hpp"

class Infix : public TreeNode
{
  public:
	Infix(void);
	virtual ~Infix(void);

	virtual char getSymbole(void) const = 0;
	virtual char getPriority(void) const = 0;

	void setParenthesis(void);
	bool getParenthesis(void) const;

  private:
	bool _parenthesis;
};

#endif /* INFIX_HPP */
