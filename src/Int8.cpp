
#include "Int8.hpp" 
#include "Operand_factory.hpp"


Int8::Int8(double value)
{
	if(value > CHAR_MAX)
	{
		throw Op_exceptions("overflow with the int8 operand");
	}
	else if(value < CHAR_MIN)
	{
		throw Op_exceptions("underflow with the int8 operand");
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
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = "";

	if (first_val == 0 || sec_val == 0)
	{
		delete this;
		delete &rhs;
		throw Op_exceptions("There is a division 0, cannot continue with the operation");
	}
	val_string = std::to_string(first_val / sec_val);
	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int8::operator%(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	double remainder = 0;
	std::string val_string = "";

	if (first_val == 0 || sec_val == 0)
	{
		delete this;
		delete &rhs;
		throw Op_exceptions("There is a modulo by 0, cannot continue with the operation");
	}
	val_string = std::to_string(std::fmod(first_val, sec_val));
	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

std::string const &Int8::toString(void) const 
{
	return (this->instance);
}
