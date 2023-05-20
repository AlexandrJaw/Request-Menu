#include "Date.h"

Date::Date(const std::string &date, bool &isSucces)
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
		isSucces = true;
	}
	else
	{
		isSucces = false;
	}
}

std::ostream& operator<<(std::ostream &out, const Date &date)
{
	out << date.m_day << ':' << date.m_month << ':' << date.m_year;
	return out;
}

const int Date::getAllDay()
{
	return m_day + months2Days() + weeks2Days() + years2Days();
}

const int Date::getAllWeek()
{
	return round(m_week + (m_day + months2Days() + years2Days()) / 7.0);
}

const int Date::getAllMonth() // Приблизительный расчет
{
	return round(m_month + (m_day + weeks2Days() + years2Days()) / 30.0);
}

const int Date::getAllYear()
{
	return round(m_year + (m_day + weeks2Days() + months2Days()) 
		/ ((m_year % 4 == 0) ? 366.0 : 365.0));
}

const int Date::months2Days()
{
	if (m_month % 2 == 1)
		return 31;
	else if (m_month != 2)
		return 30;
	else if (m_year % 4 == 0)
		return 29;
	else
		return 28;
}

const int Date::weeks2Days()
{
	return m_week * 7;
}

const int Date::years2Days()
{
	return m_year * ((m_year % 4 == 0) ? 366 : 365);
}