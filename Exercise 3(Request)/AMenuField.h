#pragma once
#include <string>

class AMenuField
{
private:
	std::string m_name;
public:
	AMenuField(std::string &name) : m_name(name) {}

	virtual void execute() = 0;
};

