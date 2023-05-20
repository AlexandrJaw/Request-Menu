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
		cout << "������� ����� ����������: ";
		cin >> dest;
		req->setDestination(std::move(dest));

		cout << "������� ����� �����: ";
		cin >> numFly;
		req->setFlyghttNumber(std::move(numFly));

		cout << "������� ���� ��� ������� ����� ������: ";
		cin >> name;
		req->setName(std::move(name));

		cout << "������� �������� ���� ������: ";
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