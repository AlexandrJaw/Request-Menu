#pragma once
#include <string>
#include <iostream>

class FullName
{
private:
	std::string m_firstName;
	std::string m_secondName;
	std::string m_lastName;
public:
	FullName() : m_firstName(""), m_secondName(""), m_lastName("") {}
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
	}

	void setFirstName(const std::string &&first) { m_firstName = std::move(first); }
	void setLastName(const std::string &&last) { m_lastName = std::move(last); }

	friend std::ostream& operator<<(std::ostream &out, const FullName &name)
	{
		out << name.m_firstName << ' ' << name.m_lastName;
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

