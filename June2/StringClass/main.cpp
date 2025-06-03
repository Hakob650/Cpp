#include <iostream>
#include "string.h"

int main()
{
	String s1;
	String s2("Hello, World!");

	s1.print();
	s2.print();

	std::cout<<"Length of s2: "<<s2.length()<<std::endl;
	std::cout<<"C-string: "<<s2.c_str()<<std::endl;

	return 0;
}
