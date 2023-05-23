#include "MenuField.h"

void MenuField::execute(const std::string &beginTitle, const std::string &endTitle) const
{
	while (true)
	{
		system("cls");
		std::cout << beginTitle << m_name << endTitle << std::endl << std::endl;
		if (m_action())
			break;
	}
}