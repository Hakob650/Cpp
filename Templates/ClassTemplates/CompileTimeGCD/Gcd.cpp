#include <iostream>

#include <cstddef>

template <std::size_t N, std::size_t M>
struct GCD
{
	enum { value = GCD<M % N, N>::value };
};

template <std::size_t M>
struct GCD<0, M>
{
	enum { value = M };
};

int main()
{
	std::cout << "GCD<18,6>::value = " << GCD<18, 6>::value << std::endl;

	return 0;
}