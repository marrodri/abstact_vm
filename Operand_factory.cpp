
#include "Operand_factory.hpp" 

//THIS IS DONE
Operand_factory::Operand_factory(/* args */)
{
}

Operand_factory::Operand_factory(Operand_factory const & src)
{
}

Operand_factory::~Operand_factory()
{
}


IOperand const * Operand_factory::createInt8(std::string const & value) const
{
	// std::cout <<  "creating Int8 class" << std::endl;
	int int_conv = std::stoi(value);
	// std::cout <<  "val is: " << int_conv << std::endl;
	char val = (char)int_conv;
	return (new Int8(val));
}

IOperand const * Operand_factory::createInt16(std::string const & value) const
{
	short val = std::stoi(value);
	return (new Int16(val));
}

IOperand const * Operand_factory::createInt32(std::string const & value) const
{
	int val = std::stoi(value);
	return (new Int32(val));
}

IOperand const * Operand_factory::createFloat(std::string const & value) const
{
	float val = std::stod(value);
	return (new Float(val));
}

IOperand const * Operand_factory::createDouble(std::string const & value) const
{
	double val = std::stod(value);
	return (new Double(val));
}

IOperand const * Operand_factory::createOperand(eOperandType type, std::string const & value) const
{
	IOperand const * (Operand_factory::*operandCreators[5])(std::string const &) const = 
	{
		&Operand_factory::createInt8,
		&Operand_factory::createInt16,
		&Operand_factory::createInt32,
		&Operand_factory::createFloat,
		&Operand_factory::createDouble
	};

	//NOTE: the 'this' is the object required to call the pointer-to-member function
	//the this pointer address, I can get the method from the current object
	return ((this->*operandCreators[type])(value));
}