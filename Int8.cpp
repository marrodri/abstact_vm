

#include "Int8.hpp" 

Int8::Int8(char value)
{
	// this->int8_val = value;
	this->int8_val = (int)value;
	int inst = value;
	this->instance = std::to_string(inst);	
}

void Int8::setValue(char value){}
int Int8::getPrecision(void) const
{
	return (8);
}

eOperandType Int8::getType(void) const
{
	return (int8);
}

IOperand const *Int8::operator+(IOperand const & rhs) const
{
	if( rhs.getPrecision() == this->getPrecision())
	{
		std::cout <<  "Both have the same prec, sum normal + 8i	nt" << std::endl;
	}
	if( rhs.getPrecision() > this->getPrecision())
	{
		std::cout <<  "the rhs has a better prec, return the rhs + 8int" << std::endl;
	}
	if( rhs.getPrecision() < this->getPrecision())
	{
		std::cout <<  "the rhs has a worser prec, return this class + 8int" << std::endl;
	}
	return this;
}

IOperand const *Int8::operator-(IOperand const & rhs) const{}
IOperand const *Int8::operator*(IOperand const & rhs) const{}
IOperand const *Int8::operator/(IOperand const & rhs) const{}
IOperand const *Int8::operator%(IOperand const & rhs) const{}

std::string const &Int8::toString(void) const 
{
	return (this->instance);
}