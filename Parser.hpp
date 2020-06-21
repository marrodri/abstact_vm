

#ifndef PARSER_HPP
#define PARSER_HPP
#include "Abstract_vm.hpp"
#include "IOperand.hpp"
class Parser
{
private:
	struct instr_list
	{
		eInstructionValue	instr_type;
		eOperandType		op_type;
		double				num_value;
		struct instr_list	*next;
	};

public:
	Parser();
	Parser(Parser const & src);
	~Parser();

	Parser & operator=(Parser const & rhs);


	void read_instr();
	void execute_instr();
	std::string get_next_token();
	void instruction_check();	
	void value_check();	

	//get function
	//set function
};
#endif