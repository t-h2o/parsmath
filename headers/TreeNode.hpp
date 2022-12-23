#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>

class TreeNode
{
  public:
	TreeNode(void);
	virtual ~TreeNode(void);
	virtual int	 eval(void) = 0;
	virtual void print(void) = 0;

	void	  set_next(int const &);
	void	  set_left(int const &number);
	void	  set_right(int const &number);
	TreeNode &get_left(void);
	TreeNode &get_right(void);

  private:
	TreeNode *_left;
	TreeNode *_right;
};

std::ostream &operator<<(std::ostream &output, TreeNode &node);

#endif /* TREE_NODE_HPP */
