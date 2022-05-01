#include <iostream>

namespace cgq
{
	std::string msg = "Hello, world!";
}

int main()
{
	std::cout << cgq::msg << std::endl;
	std::cin.get();
}
