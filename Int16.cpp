
#include "Int16.hpp" 

Int16::Int16(/* args */)
{
}

Int16::Int16(short value)
{
	this->int16_val = value;
}

Int16::Int16(Int16 const & src)
{
}

Int16::~Int16()
{
}

int Int16::getPrecision(void) const{}
eOperandType Int16::getType(void) const{}
IOperand const *Int16::operator+(IOperand const & rhs) const{}
IOperand const *Int16::operator-(IOperand const & rhs) const{}
IOperand const *Int16::operator*(IOperand const & rhs) const{}
IOperand const *Int16::operator/(IOperand const & rhs) const{}
IOperand const *Int16::operator%(IOperand const & rhs) const{}

std::string const &Int16::toString(void) const
{
	return NULL;
} 