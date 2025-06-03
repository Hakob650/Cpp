#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String
{	
private:
	char* data_;
	size_t size;
public:
	String(); // default constructor
	String(const char* str); // parameterized constructor
	~String(); // destructor
		
	size_t length() const; // get length of the string
	const char* c_str() const; // access at const char*
	void print() const; // print the string
};

#endif

