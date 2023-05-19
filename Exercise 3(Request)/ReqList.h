#pragma once
#include <list>
#include "Request.h"
#include <memory>

class ReqList
{
private:
	std::list<std::unique_ptr<Request>> m_reqlist;
public:
	void addRequest()
	{
		auto req = std::make_unique<Request>()
		m_reqlist.push_back();
	}
	void deleteRequest(int index)
	{
		auto it = m_reqlist.begin();
		std::advance(it, index);
		m_reqlist.erase(it);
	}
};

