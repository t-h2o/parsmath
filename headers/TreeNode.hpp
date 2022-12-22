#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>
class TreeNode
{
  public:
	virtual ~TreeNode(void) {}
	virtual int	 eval(void) = 0;
	virtual void print(void) = 0;
};

std::ostream &
operator<<(std::ostream &output, TreeNode &node)
{

	std::cout << node.eval();
	return output;
}

#endif /* TREE_NODE_HPP */
