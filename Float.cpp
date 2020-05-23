
#include "Float.hpp" 

Float::Float(/* args */)
{
}

Float::Float(float value)
{
	this->float_val = value;
}

Float::Float(Float const & src)
{
}

Float::~Float()
{
}


int Float::getPrecision(void) const{}
eOperandType Float::getType(void) const{}
IOperand const *Float::operator+(IOperand const & rhs) const{}
IOperand const *Float::operator-(IOperand const & rhs) const{}
IOperand const *Float::operator*(IOperand const & rhs) const{}
IOperand const *Float::operator/(IOperand const & rhs) const{}
IOperand const *Float::operator%(IOperand const & rhs) const{}
std::string const &Float::toString(void) const {return NULL;}