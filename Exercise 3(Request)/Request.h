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
	Request() : m_destination(""), m_date(), m_flyghtNumber(""), m_name() {}
	Request(const std::string &&dest, const std::string &&flyNum, const FullName &&name, const Date &date)
		: m_destination(std::move(dest)), m_date(date), m_flyghtNumber(std::move(flyNum)), m_name(std::move(name)) {}
	
	bool setDestination(const std::string &&dest);
	bool setFlyghtNumber(const std::string &&num);
	bool setName(std::string &&name);
	bool setDate(const std::string &sdate);

	const std::string& getDestination() { return m_destination; }
	const std::string& getFlyghtNumber() { return m_flyghtNumber; }
	const FullName& getName() { return m_name; }
	const Date& getDate() { return m_date; }

	friend std::ostream& operator<<(std::ostream &out, const Request &req);
	
};

