#pragma once
#include <list>
#include "Request.h"
#include <memory>
#include <iostream>

using std::cin;
using std::cout;
class ReqList
{
private:
	std::list<std::unique_ptr<Request>> m_reqlist;
public:
	void addRequest();
	
	void deleteRequest(int index);
	
};

