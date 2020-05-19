#include "IOperand.hpp"
#include "stack.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>

//for the parser, every instruction must be separated by a newline
//if there's more than one instruction in one line, handle error

std::vector<std::vector<std::string>> vector_parser(std::ifstream infile)
{
	std::string instruction;
	std::vector<std::vector<std::string>> instructions;
	int i = 0;
	//transform this from getline, to newlines;
	while (std::getline(infile, instruction))
	{
		std::cout <<  "current line is: |" << instruction << "|" << std::endl;	
		std::istringstream ss(instruction);
		if (instruction != "" && instruction != "\0")
		{
			//move this to another function for using both, the file, and the stdin
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
	return instructions;
}

void get_line_instruction(char *filename)
{
	std::ifstream infile;
	std::string instruction;

	std::vector<std::vector<std::string>> instructions;
	int i = 0;

	infile.open(filename);
	std::cout <<  "reading fine" << std::endl;
	while (std::getline(infile, instruction))
	{
		std::cout <<  "current line is: |" << instruction << "|" << std::endl;	
		std::istringstream ss(instruction);
		if (instruction != "" && instruction != "\0")
		{
			//move this to another function for using both, the file, and the stdin
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

	std::cout <<  "Number of instructions | " << instructions.size() << "|" << std::endl;
	for (int i = 0; i < instructions.size(); i++)
	{
		std::cout <<  "INSTRUCTION: |" << instructions[i][0]<< "|"  << std::endl;
		std::cout <<  "VALUE: |" << instructions[i][1] << "|"  << std::endl;
		i++;
	}
	//TODO, get an app that runs
}

void command_checker()
{
	//TODO
	// define the command_checker for any instruction inputed
	
	//if the instruction exists, run that instruction for the stack and IOperand
	
	//if the instruction doesn't exist, then handle the error 
}

void read_from_stdin()
{
	std::string input = "\0";
	std::string instructions_string = "\0";
	int str_length;
	//while running the getline, keep inputing, if a ;; is founded, break
	//and start parsing the whole input stream
	while (std::getline(std::cin, input))
	{
		if(input == ";;")
			break;
		if(instructions_string == "\0")
		{
			instructions_string = input;
			//initialize the input string from the getline
		}
		else
		{
			str_length = instructions_string.length();
			instructions_string[str_length - 1] = '\n';
			instructions_string += input;
			//if already initialize, then change last char with a newline,
			//  and then concatonate both string for the parser
		}
	}
	std::cout <<  "==============INSTRUCTIONS FROM STDIN==============" << std::endl;
	std::cout <<  instructions_string << std::endl;
	std::cout <<  "=============================================" << std::endl;
}	

//here's where the program runs
int main(int argc, char **argv)
{
	// initialize an array here that runs as a stack
	//for every new Operand created return a 
	//pointer of the class to the new space
	//of the stack
	std::stack<IOperand> VM_heap;

	// if argc is higher than 1, then check the files, if the
	// files are correctly parsed, then execute the program
	read_from_stdin();
	if (argc >= 2)
	{
		//if the file has an exit instruction, exit the VM, if not
		//the VM is still active
		
		get_line_instruction(argv[1]);
		argc = 0;
	}
	else
	{
		std::cout <<  "NO FILE, GETTING FROM STDIN" << std::endl;
		argc = 0;
	}
	//if argc is 1; the program runs, and each execution is started
	// by finding the ";;" as the beggining and end of line
	while (argc)
	{
		if (0)
		{

		}
		//for each exit command, get the argc to 0;
		if (0)
		{
			argc--;
		}
	}
	return (0);
}
