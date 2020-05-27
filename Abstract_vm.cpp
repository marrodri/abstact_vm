
#include "Abstract_vm.hpp" 

Abstract_vm::Abstract_vm(/* args */)
{
}

Abstract_vm::Abstract_vm(Abstract_vm const & src)
{
}

Abstract_vm::~Abstract_vm()
{
}

void Abstract_vm::instructionsTypes_map_init(std::map<std::string, InstructionValue> &instr_map)
{
	instr_map["push"] = push_val;
	instr_map["pop"] = pop_val;
	instr_map["dump"] = dump_val;
	instr_map["assert"] = assert_val;
	instr_map["add\n"] = add_val;
	instr_map["sub"] = sub_val;
	instr_map["mul"] = mul_val;
	instr_map["div"] = div_val;
	instr_map["mod"] = mod_val;
	instr_map["print"] = print_val;
}

void Abstract_vm::call_instructions(std::vector<std::string> instruction)
{
	//
	//TASKS TODO!!!
	//transform to lower case the whole instruction string, and separate to 2 strings
	//one is the instruction, and the other is the value if required 
	std::string first_instr = NULL;
	std::string value = NULL;
	int size = instruction.size();

	instructionsTypes_map_init(instructionTypes_map);
	std::transform(instruction[0].begin(), instruction[0].end(), instruction[0].begin(), ::tolower);
	first_instr = instruction[0];
	if (size == 2)
		value = instruction[1];
	std::cout <<  "instruction setted" << std::endl;
	switch(instructionTypes_map[first_instr])
	{
		case push_val:
			push_value(value);
			break;
		case pop_val:
			break;
		case dump_val:
			dump();
			break;
		case assert_val:
			assert(value);
			break;
		case add_val:
			add();
			break;
		case sub_val:
			sub();
			break;
		case mul_val:
			mul();
			break;
		case div_val:
			div();
			break;
		case mod_val:
			mod();
			break;
		case print_val:
			print();
			break;
		default:
			std::cout <<  "THROW ERROR for call_instructions, instruction doesn't exist" << std::endl;
			break;
	}
}

void	Abstract_vm::operandTypes_map_init(std::map<std::string, eOperandType> &op_map)
{
	op_map["int8"] = int8;
	op_map["int16"] = int16;
	op_map["int32"] = int32;
	op_map["float"] = float_class;
	op_map["double"] = double_class;
}

eOperandType Abstract_vm::getOperandType(std::string operand)
{
	operandTypes_map_init(operandTypes_map);
	switch(operandTypes_map[operand])
	{
		case int8:
			return int8;
			break;
		case int16:
			return int16;
			break;
		case int32:
			return int32;
			break;
		case float_class:
			return float_class;
			break;
		case double_class:
			return double_class;
			break;
		default:
			std::cout <<  "throw error" << std::endl;
			break;
	}
}

void Abstract_vm::push_value(std::string value)
{
	std::regex rgx_val("\\b(int8|int16|int32|float|double)(\\()(\\d*|\\d*.\\d*)(\\))");
	std::transform(value.begin(),value.end(), value.begin(), ::tolower);
	std::smatch matches;

	if (std::regex_match(value, matches, rgx_val))
	{
		std::string op = matches.str(1);
		std::string val = matches.str(3);
		eOperandType op_type = getOperandType(op);
		const IOperand* new_operand = opFactory.createOperand(op_type, val);
		this->vm_heap.push(new_operand);
	}
	else
	{
		//if regex doesn't pass we could return an error
		std::cout <<  "Value " << value << " Is not properly formatted, throwing error" << std::endl;
	}
}

const IOperand *Abstract_vm::pop()
{
	const IOperand *topval = vm_heap.top();

	vm_heap.pop();
	return topval;
}

void Abstract_vm::dump()
{
	std::stack<const IOperand*> copy_stack = vm_heap;
	//iterate through the stack to print the whole values
	std::cout <<  "DUMPING THE WHOLE STACK TO THE OUTPUT TERMINAL" << std::endl;
}

void Abstract_vm::assert(std::string)
{
	const IOperand *top_val = vm_heap.top();
	std::cout <<  "ASSERTING tHE TOP VALUE" << std::endl;
	//asserting the 
}

//add
//pops the top 2 values, then it makes the sum of those popped values,
//and the result is pushed back to the stack
void Abstract_vm::add()
{
	std::cout <<  "ADDING+" << std::endl;
}

void Abstract_vm::sub()
{
	std::cout <<  "SUBTRACTING-" << std::endl;
}

void Abstract_vm::mul()
{
	std::cout <<  "MULTIPLYING*" << std::endl;
}

//there's an edge case to check with division
void Abstract_vm::div()
{
	std::cout <<  "DIVIDNG/" << std::endl;
}

//there's an edge case to check for mod too
void Abstract_vm::mod()
{
	std::cout <<  "MODULO%" << std::endl;
}

void Abstract_vm::print()
{
	const IOperand *top_val = vm_heap.top();
	if (top_val->getType() == int8)
	{
		std::cout <<  "the val is int8, check if the the val is printable char" << std::endl;
	}
	else
	{
		std::cout <<  "THROW ERROR HERE BECAUSE IS NOT INT8" << std::endl;
	}
}
