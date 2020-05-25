
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
	if(rhs.getPrecision() == this->getPrecision())
	{
		std::cout <<  "Both have the same prec, sum normal + float" << std::endl;
	}
	if( rhs.getPrecision() > this->getPrecision())
	{
		std::cout <<  "the rhs has a better prec, return the rhs + float" << std::endl;
	}
	if( rhs.getPrecision() < this->getPrecision())
	{
		std::cout <<  "the rhs has a worser prec, return this class + float" << std::endl;
	}
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