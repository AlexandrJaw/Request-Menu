#include "ReqList.h"
#include <array>

void ReqList::addRequest()
{
	std::string dest = "";
	std::string numFly = 0;
	std::string name;
	std::string sdate;

	auto req = std::make_unique<Request>();

	std::array<bool, 4> flags;

	while (true)
	{
		if (!flags[0])
		{
			cout << "¬ведите пункт назначени€: ";
			cin >> dest;
			flags[0] = req->setDestination(std::move(dest));
		}
		if (!flags[1])
		{
			cout << "¬ведите номер рейса в формате 'AAA000': ";
			cin >> numFly;
			flags[1] = req->setFlyghttNumber(std::move(numFly));
		}
		if (!flags[2])
		{
			cout << "¬ведите ваши им€ фамилию через пробел: ";
			cin >> name;
			flags[2] = req->setName(std::move(name));
		}
		if (!flags[3])
		{
			cout << "¬ведите желаемую дату вылета в формате 'дд/мм/гг': ";
			cin >> sdate;
			flags[3] = req->setDate(std::move(sdate));
		}
	}
	m_reqlist.push_back(std::move(req));
}

void ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
}