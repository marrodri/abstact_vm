
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




IOperand const * Abstract_vm::createOperand(eOperandType type, std::string const & value) const
{
	// IOperand const *(operandFactory[5])() = {};

	// checkpoint
}

IOperand const * Abstract_vm::createInt8(std::string const & value) const
{
	char val = std::stoi(value);
	return (new Int8(val));
}

IOperand const * Abstract_vm::createInt16(std::string const & value) const
{

	short val = std::stoi(value);
	return (new Int16(val));
}

IOperand const * Abstract_vm::createInt32(std::string const & value) const
{
	int val = std::stoi(value);
	return (new Int32(val));
}

IOperand const * Abstract_vm::createFloat(std::string const & value) const
{
	float val = std::stod(value);
	return (new Float(val));
}


IOperand const * Abstract_vm::createDouble(std::string const & value) const
{
	double val = std::stod(value);
	return (new Double(val));
}

void Abstract_vm::call_instructions(std::vector<std::string> instruction)
{
	//TODO define the method that calls the instructions from the vector
	//if the instruction needs a value check the next 
}

void Abstract_vm::push_value(std::string value)
{

}

IOperand *Abstract_vm::pop()
{

}

void Abstract_vm::dump()
{
	
}

void Abstract_vm::assert(std::string)
{

}

void Abstract_vm::add()
{

}

void Abstract_vm::sub()
{

}

void Abstract_vm::mul()
{

}

void Abstract_vm::div()
{

}

void Abstract_vm::mod()
{

}

void Abstract_vm::print()
{
	
}


