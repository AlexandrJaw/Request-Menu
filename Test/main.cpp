#include <windows.h>

#define LENGTH 1000
#define WIDTH 1000
int main() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, WIDTH - 1, LENGTH - 1 }; // ширина = 80, высота = 25
	SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
	COORD bufferSize = { WIDTH, LENGTH };
	SetConsoleScreenBufferSize(consoleHandle, bufferSize);
	return 0;
}