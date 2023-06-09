#include "Menu.h"
#include <assert.h>
#include <algorithm>

void Menu::run()
{
	if (isFirstRun)
	{
		isFirstRun = false;
		auto outField = std::make_unique<MenuField>();
		if (m_parent == nullptr)
		{
			outField->setName("Quit");
			outField->setAction([]() { return true; });
		}
		else
		{
			outField->setName("Back");
			outField->setAction([]() { return true; });
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
			std::cout << i + 1 << ". " << m_fields[i]->getName() << std::endl;
		}
		
		char choice = 0;
		std::cin >> choice;

		
		int index = choice - '0';
		
		if (index > 0 && index <= m_fields.size())
		{
			if (m_fields[index - 1]->getName() == "Quit"
				|| m_fields[index - 1]->getName() == "Back")
				break;
			std::string beginTitle = "";
			std::string endTitle = "";

			if (isChildMenu(index - 1))
			{
				beginTitle = endTitle = "----------";
			}
			else
			{
				beginTitle = ">>";
				endTitle = "<<";
			}
			m_fields[index - 1]->execute(beginTitle,endTitle);
		}
		else
			std::cout << "Invalid choice." << std::endl;
	}
}

void Menu::addSubMenu(Menu &&submenu)
{
	submenu.setParent(this);
	m_childMenuField.push_back(m_fields.size());
	auto submenuFieldPtr = std::make_unique<MenuField>(submenu.m_name, []() { return true; });
	submenuFieldPtr->setAction([&]() { submenu.run(); return true; });
	m_fields.push_back(std::move(submenuFieldPtr));
}

void Menu::removeMenuField(int index) 
{ 
	m_fields.erase(m_fields.begin() + index);
	if (isChildMenu(index))
	{
		auto it = std::find(m_childMenuField.begin(), m_childMenuField.end(), index);
		m_childMenuField.erase(it);
	}
}

bool Menu::isChildMenu(int index)
{
	return std::find(m_childMenuField.begin(), m_childMenuField.end(), index)
		!= m_childMenuField.end();
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