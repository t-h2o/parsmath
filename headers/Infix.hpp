#ifndef INFIX_HPP
#define INFIX_HPP

#include "Number.hpp"
#include "TreeNode.hpp"

class Infix : public TreeNode
{
  public:
	Infix(void) : _left(0), _right(0) {}
	virtual ~Infix(void)
	{
		delete this->_left;
		delete this->_right;
	}

	void
	set_left(int const &number)
	{
		this->_left = new Number(number);
	}

	void
	set_right(int const &number)
	{
		this->_right = new Number(number);
	}

	TreeNode &
	get_left(void)
	{
		return *(this->_left);
	}

	TreeNode &
	get_right(void)
	{
		return *(this->_right);
	}

  protected:
	TreeNode *_left;
	TreeNode *_right;
};

#endif /* INFIX_HPP */
