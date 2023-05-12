#pragma once
#include <string>
#include <vector>
#include <memory>

template<class T>
class Menu
{
	using menu_ptr_t = std::vector<std::unique_ptr<Menu>>;
private:
	std::string m_name;
	std::unique_ptr<Menu> m_topMenu;
	menu_ptr_t m_subMenu;
	T m_data;
public:
	Menu(std::string &name, menu_ptr_t subMenu = 0) : m_name(name) {}

	void createSubMenu(std::unique_ptr<Menu> subMenu) { m_subMenu = subMenu; }

	void addField();
	void run()
	{
		while (true)
		{

		}
	}
};

