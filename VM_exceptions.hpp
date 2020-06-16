#ifndef VM_EXCEPTIONS_HPP
#define VM_EXCEPTIONS_HPP
#include <iostream>
#include <exception>

class VM_exceptions : public std::exception
{
private:
	std::string _msg;
public:
	VM_exceptions(const std::string & msg);
	VM_exceptions(VM_exceptions const & src);
	~VM_exceptions();

	virtual const char *what() const noexcept override;
};
#endif