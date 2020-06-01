
#ifndef LEXER_HPP
#define LEXER_HPP

#include "Abstract_vm.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


class Lexer
{
private:
	
public:
	Lexer();
	Lexer(Lexer const & src);
	~Lexer();

	// Lexer & operator=(Lexer const & rhs);
	std::vector<std::string> value_parser(std::string value);

	void file_instruction_to_string(char *filename);
	std::vector<std::vector<std::string>> read_from_stdin();
	
	std::vector<std::vector<std::string>> vector_parser(std::string input);
	void delete_comments(std::string &line);
	std::string new_line_concatonate(std::string curr_str, std::string conca_str);

};
#endif