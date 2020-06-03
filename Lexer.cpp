
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


void Lexer::delete_comments(std::string &line)
{

}

void print_vector(t_double_vector_string instructions_list)
{
	//print  instructions and values
	for(int i = 0; i < instructions_list.size(); i++)
	{
		std::cout <<  "instruction: " << instructions_list[i][0] << std::endl;
		if (instructions_list[i].size() > 1)
			std::cout <<  "value: " << instructions_list[i][1] << std::endl;
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

std::vector<std::string> Lexer::value_parser(std::string value)
{
	std::vector<std::string> parsed_val;
	std::regex rgx_val("\\b(int8|int16|int32|float|double)(\\()(\\d*|\\d*.\\d*)(\\))");
	std::transform(value.begin(),value.end(), value.begin(), ::tolower);
	std::smatch matches;

	if (std::regex_match(value, matches, rgx_val))
	{
		std::string op = matches.str(1);
		std::string val = matches.str(3);
		parsed_val.push_back(matches.str(1));
		parsed_val.push_back(matches.str(3));
	}
	else
	{
		//if regex doesn't pass we could return an error
		std::cout <<  "Value " << value << " Is not properly formatted, throwing error" << std::endl;
	}
	return (parsed_val);
}

std::vector<std::string> Lexer::instruction_parser(std::string instruction_str)
{
	std::vector<std::string> instruction;
	std::regex rgx_pat("");

	//delete the comments;
	//transform the string to lowercase;



} 


//for the parser, every instruction must be separated by a newline
//if there's more than one instruction in one line, handle error

//IMPORTANT: it needs to rechange some name variables to make it more
// understandable, and some rework needs to be done for storing the value
t_double_vector_string Lexer::vector_parser(std::string input)
{
	std::string								instruction;
	t_double_vector_string	instructions;
	std::stringstream						ss_input(input);
	int										i = 0;

	while (std::getline(ss_input, instruction, '\n'))
	{
		// std::cout <<  "current line is: |" << instruction << "|" << std::endl;	
		std::stringstream ss(instruction);
		if (instruction != "")
		{
			instructions.push_back(std::vector<std::string>());
			do
			{
				std::string word;
				ss >> word;
				instructions[i].push_back(word);
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
	return (instructions);
}

// file_input_parser
t_double_vector_string Lexer::file_input_parser(char *filename)
{
	std::ifstream							infile;
	std::string								instruction = "\0";
	std::string								file_str = "\0";
	t_double_vector_string	instructions_list;

	infile.open(filename);
	while (std::getline(infile, instruction))
		file_str = new_line_concatonate(file_str, instruction);
	
	
	// here the instruction is parsed, but the value is not parsed
	// regex could be useful for checking if a instruction needs a value or not
	//if wrongly inputed, throw a lexer/syntax error
	instructions_list = vector_parser(file_str);

	return instructions_list;
}


//stdin_parser

t_double_vector_string Lexer::stdin_parser()
{
	std::string input = "\0";
	std::string instructions_string = "\0";
	t_double_vector_string instructions_list;

	while (std::getline(std::cin, input))
	{
		if(input == ";;")
			break;
		instructions_string = new_line_concatonate(instructions_string, input);
	}

	// here the instruction is parsed, but the value is not parsed
	// regex could be useful for checking if a instruction needs a value or not
	//if wrongly inputed, throw a lexer/syntax error
	instructions_list = vector_parser(instructions_string);

	print_vector(instructions_list);
	return (instructions_list);
}