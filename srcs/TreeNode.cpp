#include "TreeNode.hpp"
#include "Infix.hpp"
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
	if (this->_left)
		throw NodeAlreadyDefine();
	this->_left = new Number(number);
}

void
TreeNode::set_left(TreeNode *node)
{
	if (this->_left)
		throw NodeAlreadyDefine();
	this->_left = node;
}

void
TreeNode::set_right(int const &number)
{
	if (this->_right)
		throw NodeAlreadyDefine();
	this->_right = new Number(number);
}

void
TreeNode::set_right(TreeNode *node)
{
	if (this->_right)
		throw NodeAlreadyDefine();
	this->_right = node;
}

TreeNode &
TreeNode::get_left(void)
{
	if (this->_left == 0)
		throw NullPointerNode();
	else
		return *(this->_left);
}

TreeNode &
TreeNode::get_right(void)
{
	if (this->_right == 0)
		throw NullPointerNode();
	else
		return *(this->_right);
}

void
TreeNode::tree(void)
{
	this->_tree(0, 0);
	std::cout << std::endl;
}

void
TreeNode::_tree(size_t indent, size_t horiBar)
{
	Infix *operation;
	Infix *childOp;

	operation = dynamic_cast<Infix *>(this);

	if (operation)
	{
		childOp = dynamic_cast<Infix *>(&(this->get_left()));
		std::cout << operation->getSymbole() << " ─┬─ ";
		if (childOp)
		{
			this->get_left()._tree(indent + 1, horiBar + 1);
			std::cout << std::endl;
			for (size_t i = 0; i < indent; ++i)
			{
				if (i < horiBar)
					std::cout << "   │  ";
				else
					std::cout << "      ";
			}
			std::cout << "   └─ ";
			this->get_right()._tree(indent + 1, horiBar);
		}
		else
		{
			this->get_right()._tree(indent + 1, horiBar + 1);
			std::cout << std::endl;
			for (size_t i = 0; i < indent; ++i)
			{
				if (i < horiBar)
					std::cout << "   │  ";
				else
					std::cout << "      ";
			}
			std::cout << "   └─ ";
			this->get_left()._tree(indent + 1, horiBar);
		}
	}
	else
	{
		std::cout << this->eval(); // << std::endl;
	}
}

std::ostream &
operator<<(std::ostream &output, TreeNode &node)
{

	std::cout << node.eval();
	return output;
}
