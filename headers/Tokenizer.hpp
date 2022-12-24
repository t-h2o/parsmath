#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#include "Add.hpp"
#include "Input.hpp"
#include "Number.hpp"
#include "Subtract.hpp"

class Tokenizer
{
  public:
	static TreeNode *generate_tree(Input);

	class BadExpression : std::exception
	{
		char const *
		what() const throw()
		{
			return "Bad expression";
		}
	};

  private:
	static void _first(Input &, TreeNode **);
	static int	_second(Input &, TreeNode **);
	static void _create_token(Input &, TreeNode **);
};

#endif /* TOKENISER_HPP */
