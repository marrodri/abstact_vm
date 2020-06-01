#include "IOperand.hpp"
#include "Abstract_vm.hpp"
#include "Lexer.hpp"

// IMPORTANT TODO tasks:
//the push function from the stdin or file are not finished, the value is empty when reading it
// -finish  the pop(DONE), dump(done), assert(done), print(done) and exit(not finished) commands


// before parsing
// for parser add a delete comment function, that checks every comment and delete it
// -check that each instruction and value exist, if not return an error(it doesn't display the error yet)


// need to double check:
// -when checking a file or stdin, return an error if an exit is not founded;

// FOR LAST AND IMPORTANT
// -set the error handling class
// -set the operators for each operand(start with sum of Int8, Int32 and float)
// 	and test the operators(if all works, then copy paste)
// -check for any leaks at the very end of the program 


//personal bonus
// -add a n option MAKE THE STDIN that run endless until an exit is founded;
// -add a "help" option that displays how to use the vm_program;

// here's where the program runs
int main(int argc, char **argv)
{
	//this is like the struct app, it has all the instructions this class.
	Abstract_vm virtual_machine;
	Lexer compiler;
	// IOperand *test
	std::vector<std::vector<std::string>> instructions_list;



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

	
	
	// if argc is higher than 1, then check the files, if the syntax of 
	// each files, parse and execute the program, if not throw error, by input help
	if(argc >= 2)
	{
		//if the file has an exit instruction, exit the VM, if not
		//the VM is still active
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
		
	}
	else
	{
		instructions_list = compiler.read_from_stdin();
		for(int i = 0; i < instructions_list.size(); i++)
		{
			virtual_machine.call_instructions(instructions_list[i]);
		}
	}
	return (0);
}
