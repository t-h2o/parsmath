#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "TreeNode.hpp"

class Number : public TreeNode
{
  public:
	Number(int const &number) : _number(number){};
	~Number(void){};

	int
	eval(void)
	{
		return _number;
	}

	void
	set_number(int const number)
	{
		_number = number;
	}

	void
	print(void)
	{
		std::cout << this->_number;
	}

  private:
	int _number;
};

#endif /* NUMBER_HPP */
