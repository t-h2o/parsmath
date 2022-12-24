#include "Input.hpp"
#include <stdlib.h>

Input::Input(char **table) : _input(""), _index(0)
{
	for (size_t i = 0; table[i]; ++i)
		this->_input += table[i];
}

Input::Input(char const *str) : _input(""), _index(0) { this->_input = str; }

Input::Input(std::string const &str) : _input(str), _index(0) { ; }

char
Input::getChar(void)
{
	if (_index >= this->_input.length())
		return 0;

	return this->_input[_index];
}

int
Input::getNumber(void) const
{
	return atoi(&(this->_input[_index]));
}

std::string &
Input::getInput(void)
{
	return this->_input;
}

void
Input::incIndex(void)
{
	if (_index >= this->_input.length())
		return;
	++this->_index;
}
