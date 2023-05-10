#include "Date.h"

Date::Date(const std::string &date)
{
	std::regex patern("^(0?[1-9]|[1-2]\\d|3[0-1]):(0?[1-9]|1[0-2]):\\d{2}$");
	if (std::regex_match(date, patern))
	{
		std::stringstream buf;
		buf << date;
		buf >> m_day;
		buf.ignore(1, ':');
		buf >> m_month;
		buf.ignore(1, ':');
		buf >> m_year;
	}
	else
	{
		throw std::runtime_error("Неправильный формат ввода");
	}
}

std::ostream& operator<<(std::ostream &out, const Date &date)
{
	out << date.m_day << ':' << date.m_month << ':' << date.m_year;
	return out;
}

const int Date::getAllDay()
{
	return m_day + m_month;
}

const int daysInMonth(const Date &date)
{
	if (date.m_month % 2 == 1)
		return 31;
	else if (date.m_month != 2)
		return 30;
	else if (date.m_year % 4 == 0)
		return 29;
	else
		return 28;
}