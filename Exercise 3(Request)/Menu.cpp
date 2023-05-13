#include "Menu.h"
#include <assert.h>

void Menu::run()
{
	setName2centr();
	while (true)
	{
		std::cout << m_name << std::endl;
		for (int i(0); i < m_fields.size(); ++i)
		{
			std::cout << i << ". " << m_fields[i]->getName() << std::endl;
		}
		std::cout << "q. Quit" << std::endl;

		char choice;
		std::cin.clear();
		std::cin.ignore(1, '\n');
		std::cin >> choice;

		if (choice == 'q' || choice == 'Q')
			break;

		int index = choice - '0';
		if (index >= 0 && index < m_fields.size())
			m_fields[index]->execute();
		else
			std::cout << "Invalid choice." << std::endl;

		system("cls");
	}
}

void Menu::addSubMenu(Menu &submenu)
{
	MenuField submenuField(submenu.m_name, []() {});
	submenu.setParent(std::make_shared<Menu>(this));
}

void Menu::setName2centr()
{
	if(m_fields.empty())
		return;

	size_t averageStr = 0;
	for (const auto &field : m_fields)
	{
		averageStr += field->getName().length();
	}
	averageStr /= m_fields.size();
	
	size_t countOfIndent = averageStr - m_name.length() / 2;

	m_name.insert(m_name.begin(), countOfIndent, '-');
	m_name.append(countOfIndent, '-');
}