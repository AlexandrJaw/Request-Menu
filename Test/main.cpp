#include <Windows.h>
#include <iostream>

int main()
{
	while (true)
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);

		int consoleWidth = bufferInfo.dwSize.X;
		int consoleHeight = bufferInfo.dwSize.Y;

		std::cout << "X: " << consoleWidth << std::endl;
		std::cout << "Y: " << consoleHeight << std::endl;
		system("cls");
	}
}