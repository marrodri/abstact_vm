
#include "Float.hpp" 
#include "Operand_factory.hpp"

Float::Float(double value)
{
	if (value > FLT_MAX)
	{
		throw Op_exceptions("overflow with the float operand");
	}
	else if (value < FLT_MIN)
	{
		throw Op_exceptions("underflow with the float operand");
	}
	else
	{
		this->float_val = value;
		this->instance = std::to_string(this->float_val);
	}
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
	std::cout <<  "setting sum float value" << std::endl;
	Operand_factory 	factory;
	double				first_val = std::stod(this->toString());
	double				sec_val = std::stod(rhs.toString());
	std::string			val_string = std::to_string(first_val + sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Float::operator-(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val - sec_val);

	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Float::operator*(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val * sec_val);

	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Float::operator/(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = "";

	if(first_val == 0 || sec_val == 0)
		throw Op_exceptions("There is a division 0, cannot continue with the operation");
	val_string = std::to_string(first_val / sec_val);
	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Float::operator%(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	double remainder = 0;
	std::string val_string = "";

	if(first_val == 0 || sec_val == 0)
		throw Op_exceptions("There is a modulo by 0, cannot continue with the operation");
	val_string = std::to_string(std::fmod(first_val, sec_val));
	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}


std::string const &Float::toString(void) const
{
	return (this->instance);
}