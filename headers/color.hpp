#ifndef COLOR_HPP
#define COLOR_HPP

#define COL_RED "\033[31;1m"
#define COL_GRE "\033[32;1m"
#define COL_YEL "\033[33m"
#define COL_RES "\033[0m"

#include <iostream>

void title(std::string);
void section(std::string);
void message(std::string);

void print_exception(char const *);

#endif /* COLOR_HPP */
