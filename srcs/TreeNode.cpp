#include "TreeNode.hpp"

TreeNode::~TreeNode(void) { ; }

std::ostream &
operator<<(std::ostream &output, TreeNode &node)
{

	std::cout << node.eval();
	return output;
}
