#pragma once
#include <list>
#include "Request.h"
#include <memory>
#include <iostream>

constexpr int NUMBER_OF_DATA_FIELDS = 4;

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

