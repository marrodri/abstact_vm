#include "IOperand.hpp"
#include "Abstract_vm.hpp"
#include "Lexer.hpp"


void option_checker(char **argv, int argc)
{
	//todo
	//make a checker that checks an -n option or a -help option

	//if an -n option is added, use it for ignoring the exit flag

	//else if -help, display how to use the abstract_vm
}

// checkpoint for come back:

// finish the trim function on the Lexer class
// -set the error handling class


// tasks:
// -finish the assert, print, exit and all the operators instructions

// need to double check:
// -when checking a file or stdin, return an error if an exit is not founded;

// FOR LAST AND IMPORTANT
// -set the operators for each operand(start with sum of Int8, Int32 and float)
// -check that each instruction and value exist, if not return an error(it doesn't display the error yet)
// 	and test the operators(if all works, then copy paste)
// -check for any leaks at the very end of the program 


//personal bonus
// -add a n option MAKE THE STDIN that run endless until an exit is founded;
// -add a "help" option that displays how to use the vm_program;

// here's where the program runs
int main(int argc, char **argv)
{
	//this is the class that has the main instructions for any operations asked.
	Abstract_vm				virtual_machine;
	Operand_factory			op_builder;
	t_double_vector_string	instructions_list;
	//this is the parser, any proper input it will be parsed, 
	//if not it will be thrown an error
	Lexer					compiler;
	int						i = 1;


	const IOperand *test = op_builder.createOperand(int8,"48");
	const IOperand *test5 = op_builder.createOperand(int16,"48");
	// const IOperand *test2 = op_builder.createOperand(float_class,"3243");
	// std::cout <<  "IOperand created with a val of |" << test->toString() << "|" << std::endl;
	// std::cout <<  "IOperand created with a val of |" << test2->toString() << "|" << std::endl;
	//
	// virtual_machine.push_value("int(1231)");
	// virtual_machine.pop();
							// int16op(int8op)
							// test5(test)
	const IOperand *sum_total = *test5 + *test;
	const IOperand *sum_total2 = *test + *test5;

	// const IOperand *sum_test = test + test2;
	// test = stack.createInt8("3242");
	// std::cout <<  "test val is |" << test << "|" << std::endl;

	virtual_machine.instructionsTypes_map_init();
	virtual_machine.operandTypes_map_init();

	// if argc is higher than 1, then check the files, if the syntax of 
	// each files, parse and execute the program, if not throw error, by input help
	if (argc >= 2)
	{
		//if the file has an exit instruction, exit the VM, if not
		//the VM is still active
		// //if argc is 1; the program runs, and each execution is started
		// // by finding the ";;" as the beggining and end of line
		while (i < argc)
		{
		// 	if (0)
		// 	{

		// 	}
		// 	//for each exit command, get the argc to 0;
		// 	if (0)
		// 	{
		// 		argc--;
		// 	}
			instructions_list = compiler.file_input_parser(argv[i]);
			for (int i = 0; i < instructions_list.size(); i++)
			{
				virtual_machine.call_instructions(instructions_list[i]);
			}
			i++;
		}	
	}
	else
	{
		instructions_list = compiler.stdin_parser();
		for (int i = 0; i < instructions_list.size(); i++)
		{
			virtual_machine.call_instructions(instructions_list[i]);
		}
	}
	return (0);
}
