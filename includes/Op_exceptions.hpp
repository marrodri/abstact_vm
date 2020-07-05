#ifndef OP_EXCEPTIONS_HPP
#define OP_EXCEPTIONS_HPP
#include <iostream>
#include <exception>

class Op_exceptions : public std::exception
{	
private:
	std::string _msg;
public:
	Op_exceptions(const std::string & msg);
	Op_exceptions(Op_exceptions const & src);
	~Op_exceptions();

	virtual const char *what() const noexcept override;
};
#endif