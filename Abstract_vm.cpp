
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

void Abstract_vm::instructionsTypes_map_init()
{
	this->instructionTypes_map["push"] = push_val;
	this->instructionTypes_map["pop"] = pop_val;
	this->instructionTypes_map["dump"] = dump_val;
	this->instructionTypes_map["assert"] = assert_val;
	this->instructionTypes_map["add"] = add_val;
	this->instructionTypes_map["sub"] = sub_val;
	this->instructionTypes_map["mul"] = mul_val;
	this->instructionTypes_map["div"] = div_val;
	this->instructionTypes_map["mod"] = mod_val;
	this->instructionTypes_map["print"] = print_val;
	this->instructionTypes_map["exit"] = exit_val;
}

void	Abstract_vm::operandTypes_map_init()
{
	this->operandTypes_map["int8"] = int8;
	this->operandTypes_map["int16"] = int16;
	this->operandTypes_map["int32"] = int32;
	this->operandTypes_map["float"] = float_class;
	this->operandTypes_map["double"] = double_class;
}

void Abstract_vm::call_instruction(std::vector<std::string> instruction)
{
	std::string first_instr = "";
	std::string op_value = "";
	std::string num_value = "";

	first_instr = instruction[0];
	if (instruction.size() > 1)
	{
		op_value = instruction[1];
		num_value = instruction[2];
	}
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
		case exit_val:
			exit();
			break;	
	}
}

void Abstract_vm::run_instructions(t_double_vector_string instructions)
{
	for (int i = 0; i < instructions.size(); i++)
		call_instruction(instructions[i]);
	if (this->exit_bool == false)
		throw VM_exceptions("Exit instruction has not been found.");
}

void Abstract_vm::push_value(std::string op_value, std::string num_value)
{
	eOperandType op_type = operandTypes_map[op_value];
	const IOperand* new_operand = opFactory.createOperand(op_type, num_value);

	this->vm_heap.push(new_operand);
}

void Abstract_vm::pop()
{
	if (!vm_heap.empty())
		vm_heap.pop();
	else
	{
		throw VM_exceptions("stack is empty, cannot pop anymore");
	}
}

void Abstract_vm::dump()
{
	if(vm_heap.empty())
	{
		throw VM_exceptions("stack is empty, cannot dump to the terminal");
	}
	else
	{
		std::stack<const IOperand*> copy_stack = vm_heap;
		const IOperand *top_val = copy_stack.top();
		while (copy_stack.size() > 0)
		{
			top_val =  copy_stack.top();
			std::cout <<  top_val->toString() << std::endl; 
			copy_stack.pop();
		}
	}
}

// Doesnt work properly with float or double. There's a bug with precission;
void Abstract_vm::assert(std::string op_value, std::string num_value)
{
	if (vm_heap.size() > 0)
	{
		const IOperand *top_val = vm_heap.top();
		eOperandType op_type = operandTypes_map[op_value];
		if ((top_val->getType() == op_type) && (top_val->toString() == num_value)) 
		{
			;
		}
		else
		{
			throw VM_exceptions("Asserted value is incorrect");
		}
	}
	else
	{
		throw VM_exceptions("stack is empty, can't assert");
	}	
}

void Abstract_vm::add()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		vm_heap.push(*first_val + *second_val);
	}
	else
	{
		throw VM_exceptions("stack has less than 2 values, can't add");
	}
}

void Abstract_vm::sub()
{
	const IOperand *first_val;
	const IOperand *second_val;

	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		vm_heap.push(*first_val - *second_val);
	}
	else
	{
		throw VM_exceptions("stack has less than 2 values, can't sub");
	}
}

void Abstract_vm::mul()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		vm_heap.push(*first_val * *second_val);
	}
	else
	{
		throw VM_exceptions("stack has less than 2 values, can't mul");
	}
}

//edge case div added, TEST!!
void Abstract_vm::div()
{
	const IOperand *first_val;
	const IOperand *second_val;

	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		vm_heap.push(*first_val / *second_val);
	}
	else
	{
		throw VM_exceptions("stack has less than 2 values, can't div");
	}
}

//edge case mod added, TEST!!
void Abstract_vm::mod()
{
	const IOperand *first_val;
	const IOperand *second_val;

	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		vm_heap.push(*first_val % *second_val);
	}
	else
	{
		throw VM_exceptions("stack has less than 2 values, can't mod");
	}
}

void Abstract_vm::print()
{
	const IOperand *top_val = vm_heap.top();
	char char_value = '\0';
	int dec_code = 0;

	if(vm_heap.empty())
	{
		throw VM_exceptions("stack is empty, cannot get the top value");
	}
	else if(top_val->getType() != int8)
	{
		throw VM_exceptions("top stack value is not an int8 type, cannot print to ASCII character");
	}
	else
	{
		char_value = std::stoi(top_val->toString());
		std::cout <<  char_value << std::endl;
	}
}

void Abstract_vm::exit()
{
	this->exit_bool = true;
}
