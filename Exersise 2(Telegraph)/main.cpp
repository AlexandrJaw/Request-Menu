#include <iostream>
#include <string>
#include "Timer.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "¬ведите сообщение: ";
	std::string str = "";
	std::getline(std::cin, str);

	for (const auto &s : str)
	{
		std::cout << s;
		sleep(50);
	}
	std::cout << std::endl;
	
	getchar();
	return 0;
}