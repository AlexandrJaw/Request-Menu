#pragma once
#include <string>
#include <chrono>
#include "Date.h"
#include "FulName.h"

class Request
{
	std::string m_destination;
	int m_flightNumber;
	FullName name;
	Date date;
};

