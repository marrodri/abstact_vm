
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
	instr_map["add"] = add_val; //weirdly, if it's "add\n", when searching add, it sets the push val
	instr_map["sub"] = sub_val;
	instr_map["mul"] = mul_val;
	instr_map["div"] = div_val;
	instr_map["mod"] = mod_val;
	instr_map["print"] = print_val;
}

void Abstract_vm::call_instructions(std::vector<std::string> instruction)
{
	std::string first_instr = "";
	std::string op_value = "";
	std::string num_value = "";
	// instruction.size();

	// std::cout <<  "INSIDE call_instructions,instructions are:" << std::endl;
	// for (int j = 0; j < instruction.size(); j++)
	// {
	// 	std::cout <<  "INSTRUCTION: |" << instruction[j]<< "|"  << std::endl;
	// 	// std::cout <<  "VALUE: |" << instructions_list[j][1] << "|"  << std::endl;
	// }
	// std::transform(instruction[0].begin(), instruction[0].end(), instruction[0].begin(), ::tolower);
	first_instr = instruction[0];
	if (instruction.size() > 1)
	{
		op_value = instruction[1];
		num_value = instruction[2];

	}
	// std::cout <<  "instruction setted: " << first_instr << std::endl;
	std::cout <<  "==calling instruction==" << std::endl;
	std::cout <<  "instr: |" << first_instr << "|" << std::endl;
	std::cout <<  "op: |" << op_value << "|" << std::endl;
	std::cout <<  "val: |" << num_value << "|" << std::endl;
	std::cout <<  "====================" << std::endl;
	instructionsTypes_map_init(instructionTypes_map);
	switch (instructionTypes_map[first_instr])
	{
		case push_val:
			push_value(op_value, num_value);
			break;
		case pop_val:
			pop();
			break;
		case dump_val:
			dump();
			break;
		case assert_val:
			assert(op_value, num_value);
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

void Abstract_vm::push_value(std::string op_value, std::string num_value)
{
	eOperandType op_type = getOperandType(op_value);
	const IOperand* new_operand = opFactory.createOperand(op_type, num_value);

	this->vm_heap.push(new_operand);
}

void Abstract_vm::pop()
{
	// const IOperand *topval = vm_heap.top();
	if(!vm_heap.empty())
		vm_heap.pop();
	else
	{
		std::cout <<  "stack is empty, cannot pop anymore, ERROR" << std::endl;
	}
	
	// return topval;
}

void Abstract_vm::dump()
{
	//iterate through the stack to print the whole values
	std::cout <<  "DUMPING THE WHOLE STACK TO THE OUTPUT TERMINAL" << std::endl;
	std::stack<const IOperand*> copy_stack = vm_heap;
	const IOperand *top_val = copy_stack.top();
	
	while (copy_stack.size() > 0)
	{
		top_val =  copy_stack.top();
		std::cout <<  top_val->toString() << std::endl; 
		copy_stack.pop();
	}
}

//change to std::string operand_value, std::string value
void Abstract_vm::assert(std::string op_value, std::string num_value)
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
	const IOperand *first_val;
	const IOperand *second_val;
	
	std::cout <<  "ADDING+" << std::endl;
	//MAKE THE ADDITION FOR BOTH CLASSES
	if(!vm_heap.empty())
	{
		std::cout <<  "stack has enugh values, adding++" << std::endl;
		std::cout <<  "vm_heap size is " << vm_heap.size() << std::endl;
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
	}
	else
	{
		std::cout <<  "stack has less than 2 values, throw error" << std::endl;
	}
}

void Abstract_vm::sub()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	first_val = vm_heap.top();
	vm_heap.pop();
	second_val = vm_heap.top();
	vm_heap.pop();
	std::cout <<  "SUBTRACTING-" << std::endl;
}

void Abstract_vm::mul()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	first_val = vm_heap.top();
	vm_heap.pop();
	second_val = vm_heap.top();
	vm_heap.pop();
	std::cout <<  "MULTIPLYING*" << std::endl;
}

//there's an edge case to check with division
void Abstract_vm::div()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	first_val = vm_heap.top();
	vm_heap.pop();
	second_val = vm_heap.top();
	vm_heap.pop();

	std::cout <<  "DIVIDNG/" << std::endl;
}

//there's an edge case to check for mod too
void Abstract_vm::mod()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	first_val = vm_heap.top();
	vm_heap.pop();
	second_val = vm_heap.top();
	vm_heap.pop();

	std::cout <<  "MODULO%" << std::endl;
}

void Abstract_vm::print()
{
	const IOperand *top_val = vm_heap.top();
	char char_value = '\0';
	int dec_code = 0;

	if (top_val->getType() == int8)
	{
		// std::stoi();
		std::cout <<  "the val is int8, printing val in ASCII" << std::endl;
		char_value = std::stoi(top_val->toString());
		std::cout <<  char_value << std::endl;
	}
	else
	{
		std::cout <<  "THROW ERROR HERE BECAUSE IS NOT INT8" << std::endl;
	}
}
