
#include "Int32.hpp" 

Int32::Int32(/* args */)
{
}

Int32::Int32(int value)
{
	this->int32_val = value;
}

Int32::Int32(Int32 const & src)
{
}

Int32::~Int32()
{
}

int Int32::getPrecision(void) const{}
eOperandType Int32::getType(void) const{}
IOperand const *Int32::operator+(IOperand const & rhs) const{}
IOperand const *Int32::operator-(IOperand const & rhs) const{}
IOperand const *Int32::operator*(IOperand const & rhs) const{}
IOperand const *Int32::operator/(IOperand const & rhs) const{}
IOperand const *Int32::operator%(IOperand const & rhs) const{}

std::string const &Int32::toString(void) const 
{
	std::string const output = std::to_string(this->int32_val);
	return output;
}