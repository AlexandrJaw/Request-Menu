#pragma once
#include <string>
#include <regex>
#include <sstream>
#include <exception>
#include <iostream>

class Date
{
private:
	int m_day;
	int m_week;
	int m_month;
	int m_year;

	const int months2Days();
	const int weeks2Days();
	const int years2Days();
public:
	Date(int day = 0, int week = 0, int month = 0, int year = 0)
		: m_day(day), m_month(month), m_week(week), m_year(year) {}
	Date(const std::string &date, bool &isSucces);
	
	void setFromString(const std::string &date, bool &isSucces);

	const int getDay() { return m_day; }
	const int getWeek() { return m_week; }
	const int getMonth() { return m_month; }
	const int getYear() { return m_year; }

	const int getAllDay();
	const int getAllWeek();
	const int getAllMonth();
	const int getAllYear();

	friend std::ostream& operator<<(std::ostream &out, const Date &date);
	
};

