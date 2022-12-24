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
	virtual void result(void) = 0;

	void set_left(int const &);
	void set_left(TreeNode *);
	void set_right(int const &);
	void set_right(TreeNode *);

	TreeNode &get_left(void);
	TreeNode &get_right(void);
	bool	  isOperator(void) const;

	void tree(void);

	class NodeAlreadyDefine : public std::exception
	{
	  public:
		const char *
		what() const throw()
		{
			return "Node already define";
		}
	};

	class NullPointerNode : public std::exception
	{
	  public:
		const char *
		what() const throw()
		{
			return "Node null pointer";
		}
	};

  protected:
	bool _isOperator;

  private:
	TreeNode *_left;
	TreeNode *_right;

	void _tree(size_t);
};

std::ostream &operator<<(std::ostream &output, TreeNode &node);

#endif /* TREE_NODE_HPP */
