#include "Input.hpp"

Input::Input(char **table) : _input(""), _index(0)
{
	for (size_t i = 0; table[i]; ++i)
		this->_input += table[i];
}

Input::Input(char *str) : _input(""), _index(0) { this->_input = str; }

char
Input::getChar(void)
{
	if (_index >= this->_input.length())
		return 'x';

	return this->_input[_index++];
}

std::string &
Input::getInput(void)
{
	return this->_input;
}
