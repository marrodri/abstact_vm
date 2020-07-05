
#include "Lexer.hpp" 

Lexer::Lexer(/* args */)
{
}

Lexer::Lexer(Lexer const & src)
{
}

Lexer::~Lexer()
{
}

void print_vector(t_double_vector_string instructions_list)
{
	//print  instructions and values
	std::cout <<  "========printing double vector========" << std::endl;
	for(int i = 0; i < instructions_list.size(); i++)
	{
		std::cout <<  "instruction: " << instructions_list[i][0] << std::endl;
		if (instructions_list[i].size() > 1)
		{
			std::cout <<  "op: " << instructions_list[i][1] << std::endl;
			std::cout <<  "value: " << instructions_list[i][2] << std::endl;
		}
	}
	std::cout <<  "=========================================" << std::endl;

}

void Lexer::delete_comments(std::string &line)
{
	int pos = -1;
	
	if ((pos = line.find(";")) >= 0)
	{
		while (line[pos])
		{
			line[pos] = ' ';
			pos++;
		}
	}
	if (line.find_first_not_of(' ') == line.npos)
		line = "\0";
}

//CHECKPOINT continue here
void Lexer::trim_whitespace_string(std::string &line)
{
	const std::string WHITESPACE = " \t\r\v\f";
	int first_pos = line.find_first_not_of(WHITESPACE);
	int end_pos = line.find_last_not_of(WHITESPACE);
	int range = end_pos - first_pos + 1;
	if (first_pos == line.npos)
		return ;
	line = line.substr(first_pos, range);	
}

std::string Lexer::new_line_concatonate(std::string curr_str, std::string conca_str)
{
	if (curr_str == "\0")
		curr_str = conca_str;
	else
	{			
		curr_str += "\n";
		curr_str += conca_str;
	}
	return (curr_str);
}

std::vector<std::string> Lexer::value_parser(std::string value_str)
{
	// if it matches parse the value, if wrong throw a parsing error
	// that the inputed value wrongly inputted, that the value is inexistent
	// or the syntax is wrong
	std::vector<std::string> parsed_val;
	std::regex rgx_val_1("\\b(int8|int16|int32|float|double)(\\()(\\d*)(\\))");
	std::regex rgx_val_2("\\b(float|double)(\\()(\\d*|\\d*.\\d*)(\\))");
	std::smatch matches;

	if (std::regex_match(value_str, matches, rgx_val_1) ||
		std::regex_match(value_str, matches, rgx_val_2))
	{
		if(matches.str(3) == "")
			throw VM_exceptions("Numeric value is empty, please put a value");
		parsed_val.push_back(matches.str(1));
		parsed_val.push_back(matches.str(3));
	}
	else
	{
		//if regex doesn't pass we could return an error
		// std::cout <<  "Value " << value_str << " Is not properly formatted or operand doesn't exist, throwing error" << std::endl;
		throw VM_exceptions("Inputed value doesn't exist, please input a type value that exists");
	}
	return (parsed_val);
}

std::vector<std::string> Lexer::instruction_parser(std::string instr_str)
{
	std::vector<std::string> new_instruction;
	std::vector<std::string> new_value;
	std::vector<std::string> unparsed_matches;
	
	//NOTE TO CHANGE
	/*
		I could use a second regex patten to separate both, and to check wether 
		one of the both regex passed, it will continue the lexical separation
		one for only one instruction, or the other that needs a value
	*/
	std::regex rgx_pat_1("(pop|dump|add|sub|mul|div|mod|print|exit)");
	// std::regex rgx_pat_2("(push|assert)((?:\\s+)?)(.*)");
	// (push|assert)\\s+(.*)
	std::regex rgx_pat_2("(push|assert)\\s+(.*)");
	std::smatch instr_match;

	if (std::regex_match(instr_str, instr_match, rgx_pat_1) || 
		std::regex_match(instr_str, instr_match, rgx_pat_2))
	{
		new_instruction.push_back(instr_match.str(1));
		if (instr_match.str(1) == "push" || instr_match.str(1) == "assert")
		{
				//if the instruction is push or assert
				//check if there is a second group for parsing, if not throw an error in the parser
				// std::cout <<  instr_match.str(2) << std::endl;
				new_value = value_parser(instr_match.str(2));
				new_instruction.insert(new_instruction.end(), new_value.begin(), new_value.end());
		}
	}
	else
	{
		throw VM_exceptions("Instruction inputed is not lexically correct");
	}
	return (new_instruction);
}

t_double_vector_string Lexer::set_instr_vector(std::string input)
{
	std::string					instruction_line;
	t_double_vector_string		new_double_vector_instr;
	std::vector<std::string>	new_instr;
	std::stringstream			ss_input(input);
	int							i = 0;

	while (std::getline(ss_input, instruction_line, '\n'))
	{
		// std::cout <<  "current line is: |" << instruction_line << "|" << std::endl;	
		if (instruction_line != "")
		{
			new_double_vector_instr.push_back(std::vector<std::string>());
			new_instr = instruction_parser(instruction_line);
			new_double_vector_instr[i] = new_instr;
			i++;
		}
	}
	return (new_double_vector_instr);
}

// file_input_parser
t_double_vector_string Lexer::file_input_parser(char *filename)
{
	std::ifstream							infile;
	std::string								newline_file = "\0";
	std::string								file_str = "\0";
	t_double_vector_string					instructions_list;

	infile.open(filename);

	if(infile.fail())
	{
		throw VM_exceptions("inputed filename doesn't exist, Exiting.");
	}
	while (std::getline(infile, newline_file))
	{
		delete_comments(newline_file);
		std::transform(newline_file.begin(),newline_file.end(), newline_file.begin(), ::tolower);
		trim_whitespace_string(newline_file);
		file_str = new_line_concatonate(file_str, newline_file);
	}

	// here the instruction is parsed, but the value is not parsed
	// regex could be useful for checking if a instruction needs a value or not
	//if wrongly inputed, throw a lexer/syntax error
	instructions_list = set_instr_vector(file_str);
	return (instructions_list);
}

//stdin_parser
t_double_vector_string Lexer::stdin_parser()
{
	std::string				newline_input = "\0";
	std::string				full_stdin_string = "\0";
	t_double_vector_string	instructions_list;

	while (std::getline(std::cin, newline_input))
	{
		if (newline_input == ";;")
			break;
		delete_comments(newline_input);
		std::transform(newline_input.begin(), newline_input.end(), newline_input.begin(), ::tolower);
		trim_whitespace_string(newline_input);
		full_stdin_string = new_line_concatonate(full_stdin_string, newline_input);
	}

	instructions_list = set_instr_vector(full_stdin_string);
	return (instructions_list);
}