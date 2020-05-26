
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

void Abstract_vm::call_instructions(std::vector<std::string> instruction)
{
}

eOperandType Abstract_vm::getOperandType(std::string operand)
{
	std::transform(operand.begin(),operand.end(), operand.begin(), ::tolower);
	if (operand == "int8"){ return (int8); }
	else if (operand == "int16"){ return (int16); }
	else if (operand == "int32"){ return (int32); }
	else if (operand == "float"){ return (float_class); }
	else if (operand == "double"){ return (double_class); }
	else
	{
		std::cout <<  "OPERAND TYPE DOESNT EXIST, HANDLE ERROR" << std::endl;
	}
}

void Abstract_vm::push_value(std::string value)
{	
	//TODO 
	//separate the instruction list, the first string transform it to enum
	//the second string should be the value, use regex to parse the string
	
	//regex pattern, the part left is the number regex that accepts as intgers of floats/doubles
	//regex pattern to seu
	// \b(int8|int16|int32|float|double)(\()(\d*|\d*.\d*)(\))
	
	std::string segment;
	std::cout <<  "pushing value: " << value << std::endl;
	// while(std::getline(value, segment, '('))
	// {

	// }
	//if regex doesn't pass we could return an error
	eOperandType op_type = getOperandType("int8");
	const IOperand* new_operand = opFactory.createOperand(op_type, "1231");
	this->vm_heap.push(new_operand);
}

const IOperand *Abstract_vm::pop()
{
	std::cout <<  "returning a popped value from the stack" << std::endl; 
	const IOperand * popped_val = vm_heap.top();
	vm_heap.pop();
	return popped_val;
}

void Abstract_vm::dump()
{
	std::stack<const IOperand*> copy_stack = vm_heap;
	//iterate through the stack to print the whole values
	std::cout <<  "DUMPING THE WHOLE STACK TO THE TERMINAL" << std::endl;
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
	if(top_val->getType() == int8)
	{
		std::cout <<  "the val is int8, check if the the val is printable char" << std::endl;
	}
	else
	{
		std::cout <<  "THROW ERROR HERE BECAUSE IS NOT INT8" << std::endl;
	}
}
