
#ifndef LEXER_HPP
#define LEXER_HPP

#include "Abstract_vm.hpp"
#include "VM_exceptions.hpp"
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
	//empty needed to check every instruction allowed
	std::vector<std::string> instruction_parser(std::string instruction);

	
	t_double_vector_string file_input_parser(char *filename);
	t_double_vector_string stdin_parser();
	
	t_double_vector_string set_instr_vector(std::string input);
	void delete_comments(std::string &line);
	void trim_whitespace_string(std::string &line);
	std::string new_line_concatonate(std::string curr_str, std::string conca_str);
};
#endif