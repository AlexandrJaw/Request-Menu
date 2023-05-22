#include "Request.h"

std::ostream& operator<<(std::ostream &out, const Request &req)
{
	out << req.m_destination << '\t' << req.m_flyghtNumber << '\t'
		<< req.m_name << '\t' << req.m_date;
	return out;
}

bool Request::setDestination(const std::string &&dest)
{ 
	std::regex patern("[a-zA-Z]+$|[à-ÿÀ-ß]+$");
	if (std::regex_match(dest, patern))
	{
		m_destination = std::move(dest);
		return true;
	}
	return false;
}
bool Request::setFlyghtNumber(const std::string &&num)
{ 
	std::regex patern("^[A-ZÀ-ß]{2,3}\\d{3}$");
	if (std::regex_match(num, patern))
	{
		m_flyghtNumber = std::move(num);
		return true;
	}
	return false;
}
bool Request::setName( std::string &&name)
{ 
	std::regex patern("^\\p{Lu}\\p{Ll}* \\p{Lu}\\p{Ll}*$");
	if (std::regex_match(name, patern))
	{
		FullName fullname;

		fullname.setFirstName(std::move(name.substr(0, name.find(' '))));
		name.erase(0, name.find(' ') + 1);

		fullname.setLastName(std::move(name));

		m_name = std::move(fullname);
		return true;
	}
	return false;
}
bool Request::setDate(const std::string &sdate)
{ 
	bool issucces;
	Date date(sdate, issucces);
	if (issucces)
	{
		m_date = date;
	}
	return issucces;
}