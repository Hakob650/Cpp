#include <iostream>

constexpr int factorial(int n)
{
	return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main()
{
	constexpr int factorial_of_5 = factorial(5);
	
	constexpr int factorial_of_10 = factorial(10);
	
	std::cout << "Factorial of 5: " << factorial_of_5 << std::endl;
	
	std::cout << "Factorial of 10: " << factorial_of_10 << std::endl;

	return 0;
}