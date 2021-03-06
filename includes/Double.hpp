#ifndef DOUBLE_HPP
#define DOUBLE_HPP
#include "Op_exceptions.hpp"
#include "IOperand.hpp"
#include <float.h>

class Double : public IOperand
{
private:
	double double_val;
	std::string instance;
public:
	Double();
	Double(long double val);
	Double(Double const & src);
	~Double();

	char const getValue();
	void setValue(char value);

	//override functions from the IOperands
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