#ifndef FLOAT_HPP
#define FLOAT_HPP
#include "IOperand.hpp"
#include "Op_exceptions.hpp"
#include <float.h>

class Float : public IOperand
{
private:
	float float_val;
	std::string instance;
public:
	Float();
	Float(double value);
	Float(Float const & src);
	~Float();

	char const getValue();
	void setValue(char value);

	int	getPrecision(void) const override; 
	eOperandType getType(void) const override;
	IOperand const *operator+(IOperand const & rhs) const override;
	IOperand const *operator-(IOperand const & rhs) const override;
	IOperand const *operator*(IOperand const & rhs) const override;
	IOperand const *operator/(IOperand const & rhs) const override;
	IOperand const *operator%(IOperand const & rhs) const override;
	std::string const &toString(void) const override;
};
#endif