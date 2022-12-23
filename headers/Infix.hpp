#ifndef INFIX_HPP
#define INFIX_HPP

#include "Number.hpp"
#include "TreeNode.hpp"

class Infix : public TreeNode
{
  public:
	Infix(void);
	virtual ~Infix(void);

	void	  set_left(int const &number);
	void	  set_right(int const &number);
	TreeNode &get_left(void);
	TreeNode &get_right(void);

  protected:
	TreeNode *_left;
	TreeNode *_right;
};

#endif /* INFIX_HPP */
