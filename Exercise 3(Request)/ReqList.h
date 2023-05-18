#pragma once
#include <list>
#include "Request.h"

class ReqList
{
private:
	std::list<Request> m_reqlist;
public:
	void addRequest(Request &req)
	{
		m_reqlist.push_back(req);
	}
	void deleteRequst(int index)
	{
		auto it = m_reqlist.begin();
		std::advance(it, index);
		m_reqlist.erase(it);
	}
};

