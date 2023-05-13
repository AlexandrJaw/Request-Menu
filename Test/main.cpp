#include <Windows.h>
#include <iostream>
#include "Console.h"
#include <string>

int main()
{
	while (true)
	{
		Console console(100, 100, "Test");
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);

		int consoleWidth = bufferInfo.dwSize.X;
		int consoleHeight = bufferInfo.dwSize.Y;

		console.clear();

		console << "X: " << std::to_string(consoleWidth).c_str() << "\n";
		console << "Y: " << std::to_string(consoleHeight).c_str() << "\n";
		
	}
}