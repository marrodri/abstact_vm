#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "IOperand.hpp"

class Double : public IOperand
{
private:
	double var_double;
public:
	Double();
	Double(Double const & src);
	~Double();

	//get function
	//set function

};
#endif