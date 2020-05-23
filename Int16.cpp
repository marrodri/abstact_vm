
#include "Int16.hpp" 

Int16::Int16(short value)
{
	this->int16_val = value;
	this->instance = std::to_string(this->int16_val);
}

Int16::Int16(Int16 const & src)
{
}

Int16::~Int16()
{
}

int Int16::getPrecision(void) const
{
	return (16);
}

eOperandType Int16::getType(void) const
{
	return (int16);
}

IOperand const *Int16::operator+(IOperand const & rhs) const{}
IOperand const *Int16::operator-(IOperand const & rhs) const{}
IOperand const *Int16::operator*(IOperand const & rhs) const{}
IOperand const *Int16::operator/(IOperand const & rhs) const{}
IOperand const *Int16::operator%(IOperand const & rhs) const{}

std::string const &Int16::toString(void) const
{
	return (this->instance);
} 