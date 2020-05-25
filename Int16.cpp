
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

IOperand const *Int16::operator+(IOperand const & rhs) const
{
	if( rhs.getPrecision() == this->getPrecision())
	{
		std::cout <<  "Both have the same prec, sum normal + 16int" << std::endl;
	}
	if( rhs.getPrecision() > this->getPrecision())
	{
		std::cout <<  "the rhs has a better prec, return the rhs + 16int" << std::endl;
	}
	if( rhs.getPrecision() < this->getPrecision())
	{
		std::cout <<  "the rhs has a worser prec, return this class + 16int" << std::endl;
	}
	return this;
}

IOperand const *Int16::operator-(IOperand const & rhs) const{}
IOperand const *Int16::operator*(IOperand const & rhs) const{}
IOperand const *Int16::operator/(IOperand const & rhs) const{}
IOperand const *Int16::operator%(IOperand const & rhs) const{}

std::string const &Int16::toString(void) const
{
	return (this->instance);
} 