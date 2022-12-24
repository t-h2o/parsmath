#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#include "Add.hpp"
#include "Input.hpp"
#include "Number.hpp"
#include "Subtract.hpp"

class Tokenizer
{
  public:
	static void create_token(Input &, TreeNode **);
};

#endif /* TOKENISER_HPP */
