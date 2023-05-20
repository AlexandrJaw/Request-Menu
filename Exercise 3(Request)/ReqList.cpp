#include "ReqList.h"

void ReqList::addRequest()
{
	std::string dest = "";
	int numFly = 0;
	FullName name;
	std::string sdate;

	while (true)
	{
		cout << "������� ����� ����������: ";
		cin >> dest;

		cout << "������� ����� �����: ";
		cin >> numFly;

		cout << "������� ���� ��� ������� ����� ������: ";
		cin >> name;

		cout << "������� �������� ���� ������: ";
		cin >> sdate;
	}


	auto req = std::make_unique<Request>();
	m_reqlist.push_back(std::move(req));
}

void ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
}