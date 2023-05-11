#pragma once
#include <string>
#include <regex>
#include <sstream>
#include <exception>
#include <iostream>

class Date
{
private:
	int m_day = 0;
	int m_week = 0;
	int m_month = 0;
	int m_year = 0;

	const int months2Days();
	const int weeks2Days();
	const int years2Days();
public:
	Date(const std::string &date);
	
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

