#include "IOperand.hpp"
#include "Abstract_vm.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void command_checker(std::vector<std::vector<std::string>> instructions)
{
	//TODO
	// define the command_checker for any instruction inputed

	//if the instruction exists, run that instruction for the stack and IOperand

	//if the instruction doesn't exist, then handle the error 
	do
	{

	} while(0);
}

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

void read_from_stdin()
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
	// std::cout <<  "==============INSTRUCTIONS FROM STDIN==============" << std::endl;
	// std::cout <<  instructions_string << std::endl;
	// std::cout <<  "=============================================" << std::endl; 
	instructions_list = vector_parser(instructions_string);
}	

//TODO tasks
//move the parser functions to the abstract_vm function or to a new class
//set precision
//set the operators for each operand(start with sum of Int8 and Int16)
//test the operators(if all works, then copy paste)
//set the error handling class

//here's where the program runs
int main(int argc, char **argv)
{
	//this is like the struct app, it has all the instructions this class.
	Abstract_vm virtual_machine;
	// IOperand *test
	Operand_factory op_builder;


	const IOperand *test = op_builder.createOperand(int8,"48");
	const IOperand *test2 = op_builder.createOperand(float_class,"3243");


	std::cout <<  "IOperand created with a val of |" << test->toString() << "|" << std::endl;
	std::cout <<  "IOperand created with a val of |" << test2->toString() << "|" << std::endl;
	
	// const IOperand *sum_test = test + test2;
	// test = stack.createInt8("3242");

	// std::cout <<  "test val is |" << test- << "|" << std::endl;

	// if argc is higher than 1, then check the files, if the
	// files are correctly parsed, then execute the program
	// read_from_stdin();
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
