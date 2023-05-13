#pragma once
#include <string>

class MenuField
{
private:
	std::string m_name;
public:
	MenuField(std::string &name) : m_name(name) {}

	virtual void execute() = 0;
};

