
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
	//TODO define the method that calls the instructions from the vector
	//if the instruction needs a value check the next 
}


IOperand const * Abstract_vm::createInt8(std::string const & value) const
{
	Int8 *pInt8 = new Int8();
}


void Abstract_vm::push_value(std::string value)
{

}

//ask how can we return a popped IOperand value class
// IOperand Abstract_vm::pop()
// {

// }

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


