#pragma once
#include <string>
#include <functional>
#include <iostream>

class MenuField
{
private:
	std::string m_name;
	std::function<bool()> m_action;
public:
	///<summary>
	///Функция уcтанавливаемая под поле меню должна возвращать значение типа bool.
	///'false' если нужно повторить цикл (с выводом названия опции в шапке)
	///и 'true' если повторять функцию не нужно.
	///</summary>
	MenuField(const std::string &name = "", std::function<bool()> action = []() { return true; })
		: m_name(name), m_action(action) {}

	void setName(const std::string &name) { m_name = name; }
	void setAction(const std::function<bool()>& action) { m_action = action; }
	const std::string& getName() const { return m_name; }
	void execute(const std::string &beginTitle = "", const std::string &endTitle = "") const;
	~MenuField() {}
};

