#include "Request.h"

std::ostream& operator<<(std::ostream &out, const Request &req)
{
	out << req.m_destination << '\t' << req.m_flyghtNumber << '\t'
		<< req.m_name << '\t' << req.m_date;
	return out;
}