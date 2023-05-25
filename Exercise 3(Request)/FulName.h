#pragma once
#include <string>
#include <iostream>
#include "Table.h"

class FullName
{
private:
	std::string m_firstName;
	std::string m_secondName;
	std::string m_lastName;
public:
	FullName(const std::string &firstName = "", const std::string &lastName = "", const std::string &secondName = "")
		: m_firstName(firstName), m_lastName(lastName), m_secondName(secondName) {}
	FullName(const FullName &name) 
		: m_firstName(name.m_firstName)
		, m_secondName(name.m_secondName)
		, m_lastName(name.m_lastName) {}
	FullName(const FullName &&name) 
		: m_firstName(std::move(name.m_firstName))
		, m_secondName(std::move(name.m_secondName))
		, m_lastName(std::move(name.m_lastName)) {}

	FullName& operator=(const FullName &&name)
	{
		if (&name == this)
			return *this;
		m_firstName = std::move(name.m_firstName);
		m_lastName = std::move(name.m_lastName);
		m_secondName = std::move(name.m_secondName);
		return *this;
	}

	void setFirstName(const std::string &&first) { m_firstName = std::move(first); }
	void setLastName(const std::string &&last) { m_lastName = std::move(last); }

	friend std::ostream& operator<<(std::ostream &out, const FullName &name)
	{
		out << name.m_firstName << ' ' << name.m_lastName;
		return out;
	}
	friend Table& operator<<(Table &table, const FullName &name)
	{
		table << std::string(name.m_firstName + " " + name.m_lastName);
		return table;
	}
	friend std::istream& operator>>(std::istream &in, FullName &name)
	{
		in.clear();
		in.ignore(32000, '\n');
		in >> name.m_firstName;
		in >> name.m_lastName;
	}
};

