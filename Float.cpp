
#include "Float.hpp" 
#include "Operand_factory.hpp"

Float::Float(float value)
{
	//here set the overflow and underflow exceptions
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
	return NULL;
}

IOperand const *Float::operator%(IOperand const & rhs) const
{
	return NULL;
}


std::string const &Float::toString(void) const
{
	return (this->instance);
}