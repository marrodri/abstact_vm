
#include "IOperand.hpp"
#include "stack.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
void parser(std::vector<IOperand> stack)
{

}

void command_checker()
{

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
		std::ifstream infile;
		infile.open(argv[1]);
		std::cout << infile.rdbuf() << std::endl;
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