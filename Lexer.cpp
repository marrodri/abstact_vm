
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
			std::cout <<  "value: " << instructions_list[i][1] << std::endl;
	}
	std::cout <<  "=========================================" << std::endl;

}

void Lexer::delete_comments(std::string &line)
{
	int pos = -1;
	
	if ((pos = line.find(";")) >= 0)
	{
		std::cout <<  "comment founded deleting comments" << std::endl;
		while(line[pos])
		{
			line[pos] = ' ';
			pos++;
		}
	}
	if (line.find_first_not_of(' ') == line.npos)
	{
		line = "\0";
	}
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
	std::regex rgx_val("\\b(int8|int16|int32|float|double)(\\()(\\d*|\\d*.\\d*)(\\))");
	std::smatch matches;

	if (std::regex_match(value_str, matches, rgx_val))
	{
		std::string op = matches.str(1);
		std::string val = matches.str(3);
		parsed_val.push_back(matches.str(1));
		parsed_val.push_back(matches.str(3));
	}
	else
	{
		//if regex doesn't pass we could return an error
		std::cout <<  "Value " << value_str << " Is not properly formatted, throwing error" << std::endl;
	}
	return (parsed_val);
}

std::vector<std::string> Lexer::instruction_parser(std::string instruction_str)
{
	std::vector<std::string> instruction;

	//probably complete pattern
	std::regex rgx_pat("\\b(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)(?: .*)?");
	std::smatch instruction_matches;
	//delete the comments;
	//transform the string to lowercase;
	//if regex is a match continue here
	if(0)
	{
		//use here the switch statements too, if the instruction is push or assert
		//check if there is a second group for parsing, if not throw an error in the parser
		
		//if it's any other instruction and there's a value inputted, throw an error,
		//if not continue as normal
	}
	else
	{
		std::cout <<  "INstruction is not correctly inputed or instruction doesnt exist,\\
		 throw error" << std::endl;
	}
	return (instruction);
}


//CHECKPOINT IMPORTANT TO CONTINUE HERE, 
// implement the instruction_parser and value_parser on this function
t_double_vector_string Lexer::set_instr_vector(std::string input)
{
	std::string				instruction_line;
	t_double_vector_string	new_vector_instr;
	std::stringstream		ss_input(input);
	int						i = 0;

	while (std::getline(ss_input, instruction_line, '\n'))
	{
		// std::cout <<  "current line is: |" << instruction << "|" << std::endl;	
		std::stringstream ss(instruction_line);
		if (instruction_line != "")
		{
			new_vector_instr.push_back(std::vector<std::string>());
			do
			{
				std::string word;
				ss >> word;
				new_vector_instr[i].push_back(word);
			} while (ss);
			i++;
		}
	}
	
	// std::cout <<  "Number of instructions | " << instructions.size() << "|" << std::endl;
	// for (int j = 0; j < instructions.size(); j++)
	// {
	// 	std::cout <<  "INSTRUCTION: |" << instructions[j][0]<< "|"  << std::endl;
	// 	std::cout <<  "VALUE: |" << instructions[j][1] << "|"  << std::endl;
	// }
	return (new_vector_instr);
}

// file_input_parser
t_double_vector_string Lexer::file_input_parser(char *filename)
{
	std::ifstream							infile;
	std::string								newline_file = "\0";
	std::string								file_str = "\0";
	t_double_vector_string					instructions_list;

	infile.open(filename);
	while (std::getline(infile, newline_file))
	{
		//for lowercasing string
		std::transform(newline_file.begin(),newline_file.end(), newline_file.begin(), ::tolower);

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
		if(newline_input == ";;")
			break;
		std::cout <<  "line inputed: " << newline_input << std::endl;
		delete_comments(newline_input);
		//for lowercasing string
		std::transform(newline_input.begin(), newline_input.end(), newline_input.begin(), ::tolower);
		std::cout <<  "line transform: " << newline_input << std::endl;
		full_stdin_string = new_line_concatonate(full_stdin_string, newline_input);
	}

	// here the instruction is parsed, but the value is not parsed
	// regex could be useful for checking if a instruction needs a value or not
	//if wrongly inputed, throw a lexer/syntax error
	instructions_list = set_instr_vector(full_stdin_string);
	print_vector(instructions_list);
	return (instructions_list);
}