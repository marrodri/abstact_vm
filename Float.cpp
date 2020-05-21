
#include "Float.hpp" 

Float::Float(/* args */)
{
}

Float::Float(Float const & src)
{
}

Float::~Float()
{
}


int IOperand::getPrecision(void) const{}
eOperandType IOperand::getType(void) const{}
IOperand const *IOperand::operator+(IOperand const & rhs) const{}
IOperand const *IOperand::operator-(IOperand const & rhs) const{}
IOperand const *IOperand::operator*(IOperand const & rhs) const{}
IOperand const *IOperand::operator/(IOperand const & rhs) const{}
IOperand const *IOperand::operator%(IOperand const & rhs) const{}