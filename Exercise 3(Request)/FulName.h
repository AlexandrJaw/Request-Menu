#pragma once
#include <string>
#include <iostream>

class FullName
{
private:
	std::string m_firstName;
	std::string m_seondName;
	std::string m_lastName;
public:
	friend std::ostream& operator<<(std::ostream &out, const FullName &name)
	{
		out << name.m_firstName << '\t' << name.m_lastName;
		return out;
	}
};

