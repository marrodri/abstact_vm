
#ifndef LEXER_HPP
#define LEXER_HPP

#include "Abstract_vm.hpp"
#include "VM_exceptions.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

typedef std::vector<std::vector<std::string>> t_double_vector_string;

class Lexer
{
private:
	
public:
	Lexer();
	Lexer(Lexer const & src);
	~Lexer();

	std::vector<std::string> value_lexer(std::string value);
	//empty needed to check every instruction allowed
	std::vector<std::string> instruction_lexer(std::string instruction);

	
	std::vector<std::string> get_file_input(char *filename);
	std::vector<std::string> get_stdin();
	
	t_double_vector_string set_instr_vector(std::string input);
	void delete_comments(std::string &line);
	void trim_whitespace_string(std::string &line);
	std::string new_line_concatonate(std::string curr_str, std::string conca_str);
};
#endif