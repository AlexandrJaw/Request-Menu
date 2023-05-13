#pragma once
#include <iostream>
#include <Windows.h>

enum ConsoleColor {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	YELLOW = 6,
	WHITE = 7,
};

class Console {
public:
	Console(int width, int height, const std::string& title)
		: m_width(width), m_height(height), m_title(title)
	{
		// Получение дескриптора окна консоли
		m_console = GetStdHandle(STD_OUTPUT_HANDLE);

		// Установка размеров окна консоли
		SMALL_RECT windowSize = { 0, 0, m_width - 1, m_height - 1 };
		SetConsoleWindowInfo(m_console, TRUE, &windowSize);

		// Установка размеров буфера экрана
		COORD bufferSize = { m_width, m_height };
		SetConsoleScreenBufferSize(m_console, bufferSize);

		// Установка заголовка окна консоли
		SetConsoleTitleA(m_title.c_str());
	}

	void clear() const {
		COORD topLeft = { 0, 0 };
		DWORD length = m_width * m_height;
		DWORD written;

		FillConsoleOutputCharacter(m_console, ' ', length, topLeft, &written);
		FillConsoleOutputAttribute(m_console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, length, topLeft, &written);

		setCursorPosition(0, 0);
	}

	void setCursorPosition(int x, int y) const {
		COORD position = { x, y };
		SetConsoleCursorPosition(m_console, position);
	}

	void setBackgroundColor(ConsoleColor color) {
		m_backgroundColor = color;
		updateConsoleAttributes();
	}

	void setForegroundColor(ConsoleColor color) {
		m_foregroundColor = color;
		updateConsoleAttributes();
	}

	Console& operator<<(const char* text) {
		std::cout << text;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Console& console);

private:
	void updateConsoleAttributes() const {
		WORD attributes = m_backgroundColor << 4 | m_foregroundColor;
		SetConsoleTextAttribute(m_console, attributes);
	}

private:
	int m_width;
	int m_height;
	std::string m_title;
	ConsoleColor m_backgroundColor = BLACK;
	ConsoleColor m_foregroundColor = WHITE;
	HANDLE m_console;
};

std::ostream& operator<<(std::ostream& os, const Console& console) {
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(console.m_console, &bufferInfo);

	WORD attributes = bufferInfo.wAttributes;
	os << std::hex << attributes << std::dec;

	return os;
}
