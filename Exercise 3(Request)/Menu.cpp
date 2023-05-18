#include "Menu.h"
#include <assert.h>

void Menu::run()
{
	if (isFirstRun)
	{
		isFirstRun = false;
		auto outField = std::make_unique<MenuField>();
		if (m_parent == nullptr)
		{
			outField->setName("Quit");
			outField->setAction([]() {});
		}
		else
		{
			outField->setName("Back");
			outField->setAction([]() {});
		}
		this->addMenuField(std::move(outField));
	}
	setName2centr();

	while (true)
	{
		system("cls");
		std::cout << m_name << std::endl;
		for (int i(0); i < m_fields.size(); ++i)
		{
			std::cout << i << ". " << m_fields[i]->getName() << std::endl;
		}
		
		char choice = 0;
		std::cin >> choice;

		
		int index = choice - '0';
		
		if (index >= 0 && index < m_fields.size())
		{
			m_fields[index]->execute();

			if (m_fields[index]->getName() == "Quit" 
				|| m_fields[index]->getName() == "Back")
				break;
		}
		else
			std::cout << "Invalid choice." << std::endl;
	}
}

void Menu::addSubMenu(Menu &&submenu)
{
	submenu.setParent(this);
	auto submenuFieldPtr = std::make_unique<MenuField>(submenu.m_name, []() {});
	submenuFieldPtr->setAction([&]() { submenu.run(); });
	m_fields.push_back(std::move(submenuFieldPtr));
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
	
	int countOfIndent = averageStr - m_name.length() / 2;

	if (countOfIndent <= 0)
		return;

	m_name.insert(m_name.begin(), countOfIndent, '-');
	m_name.append(countOfIndent, '-');
}