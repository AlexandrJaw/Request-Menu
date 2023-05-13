#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "MenuField.h"

class Menu
{
	using menu_ptr_t = std::vector<std::unique_ptr<MenuField>>;
private:
	std::string m_name;
	std::unique_ptr<Menu> m_parent = nullptr;
	menu_ptr_t m_fields;
	
public:
	Menu(const std::string &name = "Menu") : m_name(name) {}

	void addMenuField(std::unique_ptr<MenuField> &field) { m_fields.push_back(field); }

	void run()
	{
		while (true)
		{
			std::cout << m_name;

			system("cls");
		}
	}
};

