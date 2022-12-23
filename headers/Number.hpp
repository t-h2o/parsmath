#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "TreeNode.hpp"

class Number : public TreeNode
{
  public:
	Number(int const &number);
	~Number(void);

	int	 eval(void);
	void set_number(int const number);
	void print(void);

  private:
	int _number;
};

#endif /* NUMBER_HPP */
