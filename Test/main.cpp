#include <functional>
#include <iostream>

auto mylambda = [&](int i = 0) { std::cout << i << std::endl; };

void exe()
{
	mylambda();
}

void exe2()
{
	mylambda(1);
}

int main()
{
	exe();
	exe2();
	return 0;
}