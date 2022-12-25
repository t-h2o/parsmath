#include "color.hpp"

void
title(std::string title)
{
	std::cout << std::endl
			  << COL_GRE << title << COL_RES << std::endl
			  << std::endl;
}

void
section(std::string section)
{
	std::cout << std::endl
			  << COL_GRE << "\t" << section << "..." << COL_RES << std::endl
			  << std::endl;
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
