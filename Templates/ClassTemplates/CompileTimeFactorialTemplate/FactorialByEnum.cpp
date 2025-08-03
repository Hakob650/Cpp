#include <iostream>

template <std::size_t N>
struct Factorial
{
	enum { value = N * Factorial<N -1>::value };
};

template<>
struct Factorial<0>
{
	enum { value = 1 };
};

int main()
{

	std::cout << "Factorial<5>::value = " << Factorial<5>::value << std::endl;
	
	std::cout << "Factorial<10>::value = " << Factorial<10>::value << std::endl;
	
	std::cout << "Factorial<20>::value = " << Factorial<20>::value << std::endl;
	
	std::cout << "Factorial<0>::value = " << Factorial<0>::value << std::endl;

	return 0;
}