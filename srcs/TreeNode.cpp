#include "TreeNode.hpp"
#include "Number.hpp"

TreeNode::TreeNode(void) : _left(0), _right(0) { ; }
TreeNode::~TreeNode(void)
{
	delete this->_left;
	delete this->_right;
}

void
TreeNode::set_left(int const &number)
{
	this->_left = new Number(number);
}

void
TreeNode::set_right(int const &number)
{
	this->_right = new Number(number);
}

TreeNode &
TreeNode::get_left(void)
{
	return *(this->_left);
}

TreeNode &
TreeNode::get_right(void)
{
	return *(this->_right);
}

std::ostream &
operator<<(std::ostream &output, TreeNode &node)
{

	std::cout << node.eval();
	return output;
}
