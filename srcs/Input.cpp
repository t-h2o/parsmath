#include "Input.hpp"

Input::Input(char **table) : _input(table), _line(0), _index(0) { ; }

char
Input::getChar(void)
{
	if (this->_input[this->_line] == 0)
		return 'x';
	if (this->_input[this->_line][this->_index] == 0)
	{
		if (this->_input[++this->_line] == 0)
			return 'y';
		this->_index = 0;
	}
	return this->_input[this->_line][this->_index++];
}
