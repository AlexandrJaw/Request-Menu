#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "MenuField.h"

class Menu : std::enable_shared_from_this<Menu>
{
	using VecPtrField_t = std::vector<std::unique_ptr<MenuField>>;
private:
	std::string m_name;
	std::shared_ptr<Menu> m_parent = nullptr;
	VecPtrField_t m_fields;
	
	void setName2centr();
public:
	Menu(const std::string &name = "Menu") : m_name(name) {}
	Menu(Menu &&menu) 
		: m_name(menu.m_name)
		, m_parent(menu.m_parent)
		, m_fields(std::move(menu.m_fields)) {}
	Menu(Menu &) = delete;

	void addMenuField(std::unique_ptr<MenuField> &&field) { m_fields.push_back(std::move(field)); }
	void removeMenuField(int index) { m_fields.erase(m_fields.begin() + index); }
	void setName(const std::string &name) { m_name = name; }

	void run();

	void addSubMenu(std::shared_ptr<Menu> &&submenu);
	void setParent(std::shared_ptr<Menu> &&parent) { m_parent = parent; }
	~Menu() { std::cout << "Menu: "<< m_name << " is deleted" << std::endl; }
};

