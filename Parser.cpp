
#include "Parser.hpp" 

Parser::Parser(/* args */)
{
}

Parser::Parser(Parser const & src)
{
}

Parser::~Parser()
{

}

Parser & Parser::operator=(Parser const & rhs)
{

}



// NOTE!!!
//MOVE HERE THE INSTRUCTION_LEXER AND THE VALUE_LEXER, BECAUSE
// THEY WORK TO CHECK THE GRAMMAR PART, THEY DONT DO THE SINTAX PART


std::vector<std::string> Parser::parse_val(std::string value_str)
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
		// std::cout <<  "Value " << value_str << " Is not properly formatted or operand doesn't exist, throwing error" << std::endl;
		throw VM_exceptions("Type value doesn't exist, please input a type value that exists");
	}
	return (parsed_val);
}

std::string Parser::parse_instr(std::string instr_str)
{
	std::vector<std::string> new_instruction;
	std::vector<std::string> new_value;
	std::vector<std::string> unparsed_matches;

	std::regex rgx_pat("(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)");
	std::smatch instr_match;

	if (std::regex_match(instr_str, instr_match, rgx_pat))
	{
		// instructionTypes_map[instr_match.str(1)]		
	}
	else
	{
		throw VM_exceptions("Instruction inputed doesn't exist");
	}
	return "(new_instruction)";
}

