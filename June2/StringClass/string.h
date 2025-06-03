#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String
{	
private:
	char* data_;
	size_t size;
public:
	String(); 
	String(const char* str); 
	~String(); 
		
	size_t length() const; 
	const char* c_str() const; 
	void print() const; 
};

#endif

