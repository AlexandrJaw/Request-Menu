#include "ReqList.h"

void ReqList::addRequest()
{
	std::string dest = "";
	std::string numFly = 0;
	std::string name;
	std::string sdate;

	auto req = std::make_unique<Request>();

	while (true)
	{
		cout << "¬ведите пункт назначени€: ";
		cin >> dest;
		req->setDestination(std::move(dest));

		cout << "¬ведите номер рейса: ";
		cin >> numFly;
		req->setFlyghttNumber(std::move(numFly));

		cout << "¬ведите ваши им€ фамилию через пробел: ";
		cin >> name;
		req->setName(std::move(name));

		cout << "¬ведите желаемую дату вылета: ";
		cin >> sdate;
		req->setDate(std::move(sdate));
	}


	
	m_reqlist.push_back(std::move(req));
}

void ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
}