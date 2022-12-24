#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#include "Add.hpp"
#include "Input.hpp"
#include "Number.hpp"
#include "Subtract.hpp"

#include <vector>

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
	static TreeNode *_create_token(Input &);
};

#endif /* TOKENISER_HPP */
