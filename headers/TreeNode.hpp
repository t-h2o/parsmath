#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

class TreeNode
{
  public:
	virtual ~TreeNode(void){};
	virtual int eval(void) = 0;
};

#endif /* TREE_NODE_HPP */
