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
	friend std::istream& operator>>(std::istream &in, FullName &name)
	{
		in.clear();
		in.ignore(32000, '\n');
		in >> name.m_firstName;
		in >> name.m_lastName;
	}
};

