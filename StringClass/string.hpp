#include <cstddef>

#ifndef STRING_HPP
#define STRING_HPP

class String
{	
private:
	char* data_;
	size_t size;
public:
	String(); 
	String(const char* str); 
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(String&& other);
	~String(); 
		
	size_t length() const; 
	const char* c_str() const; 
	void print() const; 
};

#endif