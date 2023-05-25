#pragma once
#include <string>
#include <regex>
#include <sstream>
#include <exception>
#include <iostream>
#include "Table.h"

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
	friend Table& operator<<(Table &table, const Date &date);

	template<class T>
	friend T& outDate(T &out, const Date &date);
	
};

template<class T>
T& outDate(T &out, const Date &date)
{
	std::string sout = "";
	if (date.m_day < 10)
		sout += "0" + std::to_string(date.m_day) + "/";
	else
		sout += std::to_string(date.m_day) + "/";

	if (date.m_month < 10)
		sout += "0" + std::to_string(date.m_month) + "/";
	else
		sout += std::to_string(date.m_month) + "/";

	if (date.m_year < 10)
		sout += "0" + std::to_string(date.m_year);
	else
		sout += std::to_string(date.m_year);

	out << sout;
	return out;
}