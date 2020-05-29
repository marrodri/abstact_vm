#include "IOperand.hpp"
#include "Abstract_vm.hpp"
#include "parser.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

// void command_checker(std::vector<std::vector<std::string>> instructions)
// {
// 	//TODO
// 	// define the command_checker for any instruction inputed

// 	//if the instruction exists, run that instruction for the stack and IOperand

// 	//if the instruction doesn't exist, then handle the error 
// 	do
// 	{

// 	} while(0);
// }

std::string new_line_concatonate(std::string curr_str, std::string conca_str)
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

std::vector<std::vector<std::string>> vector_parser(std::string input)
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

void file_instruction_to_string(char *filename)
{
	std::ifstream							infile;
	std::string								instruction = "\0";
	std::string								file_str = "\0";
	std::vector<std::vector<std::string>>	instructions_list;

	infile.open(filename);
	while (std::getline(infile, instruction))
		file_str = new_line_concatonate(file_str, instruction);
	// std::cout <<  "==============INSTRUCTIONS FROM FILE==============" << std::endl;
	// std::cout <<  file_str << std::endl;
	// std::cout <<  "=============================================" << std::endl;
	instructions_list = vector_parser(file_str);
}

void read_from_stdin(Abstract_vm &abstract_vm)
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
	for(int i = 0; i < instructions_list.size(); i++)
	{
		abstract_vm.call_instructions(instructions_list[i]);
	}
}	

// IMPORTANT TODO tasks:
// -finish  the pop(DONE), dump(done), assert(done), print(done) and exit(not finished) commands
// -move the parser to a new file
// -MAKE THE STDIN that run endless until an exit is founded;
// -check that each instruction and value exist, if not return an error(it doesn't display the error yet)
// 


// need to double check:
// -when checking a file or stdin, return an error if an exit is not founded;

// FOR LAST AND IMPORTANT
// -set the error handling class
// -set the operators for each operand(start with sum of Int8, Int32 and float)
// 	and test the operators(if all works, then copy paste)
// -check for any leaks at the very end of the program 

// here's where the program runs
int main(int argc, char **argv)
{
	//this is like the struct app, it has all the instructions this class.
	Abstract_vm virtual_machine;

	// IOperand *test
	Operand_factory op_builder;


	const IOperand *test = op_builder.createOperand(int8,"48");
	const IOperand *test2 = op_builder.createOperand(float_class,"3243");

	// std::cout <<  "IOperand created with a val of |" << test->toString() << "|" << std::endl;
	
	// std::cout <<  "IOperand created with a val of |" << test2->toString() << "|" << std::endl;

	virtual_machine.push_value("inT32(1231)");

	virtual_machine.pop();


	// const IOperand *sum_test = test + test2;
	// test = stack.createInt8("3242");

	// std::cout <<  "test val is |" << test- << "|" << std::endl;

	// if argc is higher than 1, then check the files, if the
	// files are correctly parsed, then execute the program
	
	read_from_stdin(virtual_machine);
	
	// virtual_machine.dump();
	// if (argc >= 2)
	// {
	// 	//if the file has an exit instruction, exit the VM, if not
	// 	//the VM is still active
		
	// 	file_instruction_to_string(argv[1]);
	// 	argc = 0;
	// }
	// else
	// {
	// 	std::cout <<  "NO FILE, GETTING FROM STDIN" << std::endl;
	// 	argc = 0;
	// }
	// //if argc is 1; the program runs, and each execution is started
	// // by finding the ";;" as the beggining and end of line
	// while (argc)
	// {
	// 	if (0)
	// 	{

	// 	}
	// 	//for each exit command, get the argc to 0;
	// 	if (0)
	// 	{
	// 		argc--;
	// 	}
	// }
	return (0);
}
