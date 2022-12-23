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
TreeNode::set_left(TreeNode *node)
{
	this->_left = node;
}

void
TreeNode::set_right(int const &number)
{
	this->_right = new Number(number);
}

void
TreeNode::set_right(TreeNode *node)
{
	this->_right = node;
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

bool
TreeNode::isOperator(void) const
{
	return this->_isOperator;
}

void
TreeNode::tree(void)
{
	this->_tree(1);
}

void
TreeNode::_tree(size_t indent)
{
	if (this->isOperator())
	{
		std::cout << "+ ─┬─ ";
		this->get_left()._tree(indent + 2);
		std::cout << std::endl;
		for (size_t i = 0; i < indent; ++i)
			std::cout << "   ";
		std::cout << "└─ ";
		this->get_right()._tree(indent + 2);
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->eval();
	}
}

std::ostream &
operator<<(std::ostream &output, TreeNode &node)
{

	std::cout << node.eval();
	return output;
}
