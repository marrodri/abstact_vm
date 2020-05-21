#ifndef FLOAT_HPP
#define FLOAT_HPP

#include "IOperand.hpp"
class Float : public IOperand
{
private:
	float var_float;
public:
	Float();
	Float(Float const & src);
	~Float();

	//get function
	//set function

};
#endif