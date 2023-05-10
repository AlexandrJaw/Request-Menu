#pragma once
#include <string>
#include <chrono>

struct FullName;

class Request
{
	std::string m_destination;
	int m_flightNumber;
	FullName name;
	
};

struct FullName
{
private:
	std::string m_firstName;
	std::string m_seondName;
	std::string m_lastName;
public:

};