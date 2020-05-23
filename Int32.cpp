
#include "Int32.hpp" 

Int32::Int32(int value)
{
	this->int32_val = value;
	this->instance = std::to_string(this->int32_val);
}

Int32::Int32(Int32 const & src)
{
}

Int32::~Int32()
{
}

int Int32::getPrecision(void) const
{
	return (32);
}

eOperandType Int32::getType(void) const
{
	return (int32);
}

IOperand const *Int32::operator+(IOperand const & rhs) const{}
IOperand const *Int32::operator-(IOperand const & rhs) const{}
IOperand const *Int32::operator*(IOperand const & rhs) const{}
IOperand const *Int32::operator/(IOperand const & rhs) const{}
IOperand const *Int32::operator%(IOperand const & rhs) const{}

std::string const &Int32::toString(void) const 
{
	return (this->instance);
}