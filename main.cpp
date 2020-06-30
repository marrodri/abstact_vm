#include "IOperand.hpp"
#include "Abstract_vm.hpp"
#include "Lexer.hpp"
#include "VM_exceptions.hpp"
#include "Op_exceptions.hpp"

// checkpoint for come back:
// update the regex pattern in the instruction_parser function and error management for input
// -test mod and div operators with the exceptions almost done

// FOR LAST AND IMPORTANT
// -check that each instruction and value exist, if not return an error(it doesn't display the error yet)
// 	and test the operators(if all works, then copy paste)
// -check for any leaks at the very end of the program 


// here's where the program runs
int main(int argc, char **argv)
{
	Abstract_vm				virtual_machine;
	t_double_vector_string	instructions_list;
	Lexer					compiler;
	int						i = 1;

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
			try
			{	
				instructions_list = compiler.file_input_parser(argv[i]);
				for (int i = 0; i < instructions_list.size(); i++)
					virtual_machine.call_instructions(instructions_list[i]);
				if (virtual_machine.get_exit() == false)
					throw VM_exceptions("Exit instruction has not been found.");
			}
			catch (VM_exceptions &e)
			{
				std::cout <<  "VM ERROR: " << e.what() << std::endl;
			}
			catch (Op_exceptions &e)
			{
				std::cout <<  "OPERAND ERROR: " << e.what() << std::endl;
			}
			i++;
		}	
	}
	else
	{
		try
		{
			instructions_list = compiler.stdin_parser();
			for (int i = 0; i < instructions_list.size(); i++)
				virtual_machine.call_instructions(instructions_list[i]);
			if (virtual_machine.get_exit() == false)
				throw VM_exceptions("Exit instruction has not been found.");
		}
		catch (VM_exceptions &e)
		{
			std::cout <<  "VM ERROR: " << e.what() << std::endl;
		}
		catch (Op_exceptions &e)
		{
			std::cout <<  "OPERAND ERROR: " << e.what() << std::endl;
		}
	}
	return (0);
}
