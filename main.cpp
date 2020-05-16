#include "IOperand.hpp"
#include "stack.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void get_line_instruction(char *filename)
{
	std::ifstream infile;
	std::string instruction;

	std::vector<std::vector<std::string>> instructions;
	int i = 0;
	int j = 0;

	

	infile.open(filename);
	std::cout <<  "reading fine" << std::endl;
	//TODO, store the line commands in the double vector, instructions;
	//each line is going to be a vector of a vector of words. 
	while (std::getline(infile, instruction))
	{
		std::cout <<  "current line is: |" << instruction << "|" << std::endl;	
		instructions.push_back(std::vector<std::string>());
		std::istringstream ss(instruction);
		do
		{
			std::string word;
			ss >> word;
			instructions[i].push_back(word);
		} while (ss);
		
		std::cout <<  "INSTRUCTION: |" << instructions[i][0]<< "|"  << std::endl;
		if(instructions[i][0] != "")
			std::cout <<  "VALUE: |" << instructions[i][1] << "|"  << std::endl;
		i++;
	}
}

void command_checker()
{
	//TODO
	// define the command_checker for any instruction inputed
	
	//if the instruction exists, run that instruction for the stack and IOperand
	
	//if the instruction doesn't exist, then handle the error 
}

//here's where the program runs
int main(int argc, char **argv)
{
	// initialize an array here that runs as a stack
	//for every new Operand created return a 
	//pointer of the class to the new space
	//of the stack
	std::vector<IOperand> stack;

	// if argc is higher than 1, then check the files, if the
	// files are correctly parsed, then execute the program
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
		if(0)
		{

		}
		//for each exit command, get the argc to 0;
		if(0)
		{
			argc--;
		}
	}
	return 0;
}