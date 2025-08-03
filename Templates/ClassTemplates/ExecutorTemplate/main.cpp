#include <iostream>
#include "Executor.hpp"

void hello()
{
	std::cout << "Hello!" << std::endl;
}

void bye()
{
	std::cout << "Bye!" << std::endl;
}

int main()
{
	Executor<hello> executorHello;
	executorHello.run();

	Executor<bye> executorBye;
	executorBye.run();

	return 0;
}