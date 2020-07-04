#include "IOperand.hpp"
#include "Abstract_vm.hpp"
#include "Lexer.hpp"
#include "VM_exceptions.hpp"
#include "Op_exceptions.hpp"

// checkpoint for come back:
// update the regex pattern in the instruction_parser function and error management for input

// fix the assert function x
// for the last clear any leaks!!! x


int main(int argc, char **argv)
{
	Abstract_vm				virtual_machine;
	t_double_vector_string	instructions_list;
	Lexer					compiler;
	int						i = 1;

	virtual_machine.instructionsTypes_map_init();
	virtual_machine.operandTypes_map_init();
	try
	{
		if (argc >= 2)
		{
			while (i < argc)
			{
				instructions_list = compiler.file_input_parser(argv[i]);
				virtual_machine.run_instructions(instructions_list);
				i++;
			}
		}
		else
		{
			instructions_list = compiler.stdin_parser();
			virtual_machine.run_instructions(instructions_list);
		}
	}
	catch (VM_exceptions &e)
	{
		std::cout <<  "VM ERROR: " << e.what() << std::endl;
	}
	catch (Op_exceptions &e)
	{
		std::cout <<  "OPERAND ERROR: " << e.what() << std::endl;
	}
	virtual_machine.clear_stack();
	return (0);
}
