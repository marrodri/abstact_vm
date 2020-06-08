
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
	this->instructionTypes_map["add"] = add_val; //weirdly, if it's "add\n", when searching add, it sets the push val
	this->instructionTypes_map["sub"] = sub_val;
	this->instructionTypes_map["mul"] = mul_val;
	this->instructionTypes_map["div"] = div_val;
	this->instructionTypes_map["mod"] = mod_val;
	this->instructionTypes_map["print"] = print_val;
}

void	Abstract_vm::operandTypes_map_init()
{
	// this->operandTypes_map
	this->operandTypes_map["int8"] = int8;
	this->operandTypes_map["int16"] = int16;
	this->operandTypes_map["int32"] = int32;
	this->operandTypes_map["float"] = float_class;
	this->operandTypes_map["double"] = double_class;
}

void Abstract_vm::call_instructions(std::vector<std::string> instruction)
{
	std::string first_instr = "";
	std::string op_value = "";
	std::string num_value = "";

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
	// instructionsTypes_map_init(instructionTypes_map);
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
	}
}

//done
void Abstract_vm::push_value(std::string op_value, std::string num_value)
{
	eOperandType op_type = operandTypes_map[op_value];
	const IOperand* new_operand = opFactory.createOperand(op_type, num_value);

	this->vm_heap.push(new_operand);
}

//done
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

//done
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


void Abstract_vm::assert(std::string op_value, std::string num_value)
{
	std::cout <<  "ASSERTING tHE TOP VALUE" << std::endl;
	if(vm_heap.size() > 0)
	{

		const IOperand *top_val = vm_heap.top();
	}
	else
	{
		std::cout <<  "stack is empty, cannot assert error" << std::endl;
	}
	
	//asserting the 
}

//add
//pops the top 2 values, then it makes the sum of those popped values,
//and the result is pushed back to the stack
void Abstract_vm::add()
{
	const IOperand *first_val;
	const IOperand *second_val;
	
	//MAKE THE ADDITION FOR BOTH CLASSES
	//change this if to try
	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		if (first_val->getPrecision() >= second_val->getPrecision())
			vm_heap.push(*first_val + *second_val);
		else
			vm_heap.push(*second_val + *first_val);
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
	
	if (vm_heap.size() >= 2)
	{
		first_val = vm_heap.top();
		vm_heap.pop();
		second_val = vm_heap.top();
		vm_heap.pop();
		if(first_val->getPrecision() >= second_val->getPrecision())
			vm_heap.push(*first_val - *second_val);
		else
			vm_heap.push(*second_val - *first_val);
	}
	else
	{
		std::cout <<  "stack has less than 2 values, throw error" << std::endl;
	}
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
