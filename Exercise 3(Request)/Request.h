#pragma once
#include <string>
#include <chrono>
#include "Date.h"
#include "FulName.h"
#include <iostream>

class Request
{
private:
	std::string m_destination;
	int m_flyghtNumber;
	FullName m_name;
	Date m_date;
public:
	Request(const std::string &dest, const int flyNum, const FullName &name, const Date &date)
		: m_destination(dest), m_date(date), m_flyghtNumber(flyNum), m_name(name) {}

	friend std::ostream& operator<<(std::ostream &out, const Request &req);
	
};

