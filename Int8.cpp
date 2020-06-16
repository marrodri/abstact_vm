


#include "Int8.hpp" 
#include "Operand_factory.hpp"

Int8::Int8(double value)
{
	// this->int8_val = value;

	if(value > CHAR_MAX)
	{
		throw std::overflow_error("OVERFLOW of int8");
	}
	else if(value < CHAR_MIN)
	{
		throw std::invalid_argument("underflow of int8");
	}
	else
	{
		this->int8_val = (char)value;
		this->instance = std::to_string((int)this->int8_val);	
	}
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
	std::cout <<  "returning sum char value" << std::endl;
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val + sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int8::operator-(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val - sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int8::operator*(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val * sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int8::operator/(IOperand const & rhs) const
{
	return NULL;
}

IOperand const *Int8::operator%(IOperand const & rhs) const
{
	return NULL;
}


std::string const &Int8::toString(void) const 
{
	return (this->instance);
}