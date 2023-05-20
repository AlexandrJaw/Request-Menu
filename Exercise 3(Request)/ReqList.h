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
	void addRequest()
	{
		cout << "¬ведите пункт назначени€: ";
		std::string dest = "";
		cin >> dest;

		cout << "¬ведите номер рейса: ";
		int numFly = 0;
		cin >> numFly;

		cout << "¬ведите ваши им€ фамилию через пробел: ";
		FullName name;
		cin >> name;

		cout << "¬ведите желаемую дату вылета: ";
		std::string sdate;
		cin >> sdate;
		bool issucces;
		Date date(sdate, issucces);

		//
		
		auto req = std::make_unique<Request>();
		m_reqlist.push_back(std::move(req));
	}
	void deleteRequest(int index)
	{
		auto it = m_reqlist.begin();
		std::advance(it, index);
		m_reqlist.erase(it);
	}
};

