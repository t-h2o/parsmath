#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#include "Input.hpp"

#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Subtract.hpp"

#include "Number.hpp"

#include <vector>

class Tokenizer
{
  public:
	static TreeNode *generate_tree(Input);

	class BadExpression : std::exception
	{
	  public:
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
