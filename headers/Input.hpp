#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

class Input
{
  public:
	Input(char **);

	char getChar(void);

  private:
	char **_input;
	size_t _line;
	size_t _index;
};
#endif /* INPUT_HPP */
