
#include "Float.hpp" 

Float::Float(float value)
{
	this->float_val = value;
	this->instance = std::to_string(this->float_val);
}

Float::Float(Float const & src)
{
}

Float::~Float()
{
}


int Float::getPrecision(void) const
{
	return (64);
}

eOperandType Float::getType(void) const
{
	return (float_class);
}

IOperand const *Float::operator+(IOperand const & rhs) const
{
	std::cout <<  "Both have the same prec, sum normal + 8i	nt" << std::endl;

	return this;
}

IOperand const *Float::operator-(IOperand const & rhs) const{}
IOperand const *Float::operator*(IOperand const & rhs) const{}
IOperand const *Float::operator/(IOperand const & rhs) const{}
IOperand const *Float::operator%(IOperand const & rhs) const{}

std::string const &Float::toString(void) const
{
	return (this->instance);
}