#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

class Input
{
  public:
	Input(char **);
	Input(char const *);
	Input(std::string const &);

	char getChar(void);

	std::string &getInput(void);

	int getNumber(void) const;

	void incIndex(void);

  private:
	std::string _input;
	size_t		_index;
};
#endif /* INPUT_HPP */
