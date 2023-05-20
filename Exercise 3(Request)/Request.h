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
	std::string m_flyghtNumber;
	FullName m_name;
	Date m_date;
public:
	Request(const std::string &&dest, const std::string &&flyNum, const FullName &&name, const Date &date)
		: m_destination(std::move(dest)), m_date(date), m_flyghtNumber(std::move(flyNum)), m_name(std::move(name)) {}
	
	bool setDestination(const std::string &&dest);
	bool setFlyghttNumber(const std::string &&num);
	bool setName(std::string &&name);
	bool setDate(const Date &date);

	friend std::ostream& operator<<(std::ostream &out, const Request &req);
	
};

