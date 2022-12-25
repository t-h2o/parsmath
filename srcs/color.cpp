#include "color.hpp"

void
title(std::string title)
{
	NEWLINE;
	std::cout << COL_GRE << title << COL_RES;
	NEWLINE;
	NEWLINE;
}

void
section(std::string section)
{
	NEWLINE;
	std::cout << COL_GRE << "\t" << section << "..." << COL_RES;
	NEWLINE;
	NEWLINE;
}

void
message(std::string message)
{
	std::cout << COL_YEL << message << COL_RES << std::endl;
}

void
print_exception(char const *errorMsg)
{
	std::cerr << COL_RED << errorMsg << COL_RES << std::endl;
}
