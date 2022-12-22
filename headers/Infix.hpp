#ifndef INFIX_HPP
#define INFIX_HPP

#include "TreeNode.hpp"

class Infix : public TreeNode
{
  public:
	virtual ~Infix(void){};

  private:
	TreeNode *_left;
	TreeNode *_right;
};

#endif /* INFIX_HPP */
