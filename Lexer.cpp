

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

//for the parser, every instruction must be separated by a newline
//if there's more than one instruction in one line, handle error


std::vector<std::vector<std::string>> Lexer::vector_parser(std::string input)
{
	std::string								instruction;
	std::vector<std::vector<std::string>>	instructions;
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

void Lexer::file_instruction_to_string(char *filename)
{
	std::ifstream							infile;
	std::string								instruction = "\0";
	std::string								file_str = "\0";
	std::vector<std::vector<std::string>>	instructions_list;

	infile.open(filename);
	while (std::getline(infile, instruction))
		file_str = new_line_concatonate(file_str, instruction);
	instructions_list = vector_parser(file_str);
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

std::vector<std::vector<std::string>> Lexer::read_from_stdin()
{
	std::string input = "\0";
	std::string instructions_string = "\0";
	std::vector<std::vector<std::string>> instructions_list;

	while (std::getline(std::cin, input))
	{
		if(input == ";;")
			break;
		instructions_string = new_line_concatonate(instructions_string, input);
	}
	instructions_list = vector_parser(instructions_string);
	//iterate through instructions
	// for(int i = 0; i < instructions_list.size(); i++)
	// {
	// 	abstract_vm.call_instructions(instructions_list[i]);
	// }
	return instructions_list;
}