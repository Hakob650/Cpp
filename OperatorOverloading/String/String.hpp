#include <cstddef>
#include <iostream>

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

        friend bool operator==(const String& lhs,const String& rhs);
		
        friend bool operator!=(const String& lhs,const String& rhs);

        friend bool operator<(const String& lhs,const String& rhs);

        friend bool operator>(const String& lhs,const String& rhs);

        friend bool operator<=(const String& lhs,const String& rhs);

        friend bool operator>=(const String& lhs,const String& rhs);

        friend String operator+(const String& lhs,const String& rhs);

        String& operator+=(const String& rhs);

        char& operator[](size_t index);

        const char& operator[](size_t index) const;

        friend std::istream& operator>>(std::istream& is,String& rhs);

        friend std::ostream& operator<<(std::ostream& os,const String& rhs);

	    size_t length() const; 
 	    
        const char* c_str() const; 
 	    
        void print() const; 
};

#endif