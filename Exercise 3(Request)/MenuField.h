#pragma once
#include <string>
#include <functional>

class MenuField
{
private:
	std::string m_name;
	std::function<void()> m_action;
public:
	MenuField(const std::string &name = "", std::function<void()> action = []() {})
		: m_name(name), m_action(action) {}

	void setName(const std::string &name) { m_name = name; }
	void setAction(const std::function<void()>& action) { m_action = action; }
	const std::string& getName() const { return m_name; }
	void execute() const { m_action(); }
};

