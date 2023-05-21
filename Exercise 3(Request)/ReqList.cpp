#include "ReqList.h"
#include <array>

bool isInputCorect(std::array<bool, NUMBER_OF_DATA_FIELDS> &flags) // ������� ��� �������� ����������� �����
{
	for (const auto &f : flags)
		if (!f)
			return false;
	return true;
}

void ReqList::addRequest() // ����� ���������� ����� ������ �� ���������
{
	std::string dest = "";
	std::string numFly = 0;
	std::string name;
	std::string sdate;

	auto req = std::make_unique<Request>();

	std::array<bool, NUMBER_OF_DATA_FIELDS> flags; //����� ��� �������� ����������� �����
	for (auto &f : flags)
		f = false;

	//���� �������� �����
	while (!isInputCorect(flags))
	{
		for(const auto &f : flags) // ������� ��������� ��� ������������ �����
			if (f)
			{
				system("cls");
				std::cout << "������������ ����. ��������� ����." << std::endl;
				break;
			}

		if (!flags[0])
		{
			cout << "������� ����� ����������: ";
			cin >> dest;
			flags[0] = req->setDestination(std::move(dest));
			if (!flags[0]) continue;
		}
		else
			std::cout << "�� ����� ����� ����������: " << req->getDestination() << std::endl;

		if (!flags[1])
		{
			cout << "������� ����� ����� � ������� 'AAA000': ";
			cin >> numFly;
			flags[1] = req->setFlyghtNumber(std::move(numFly));
			if (!flags[1]) continue;
		}
		else
			std::cout << "�� ����� ����� �����: " << req->getFlyghtNumber() << std::endl;
		if (!flags[2])
		{
			cout << "������� ���� ��� ������� ����� ������: ";
			cin >> name;
			flags[2] = req->setName(std::move(name));
			if (!flags[2]) continue;
		}
		else
			std::cout << "�� ����� ���� ���/�������: " << req->getName() << std::endl;
		if (!flags[3])
		{
			cout << "������� �������� ���� ������ � ������� '��/��/��': ";
			cin >> sdate;
			flags[3] = req->setDate(std::move(sdate));
			if (!flags[3]) continue;
		}
		else
			std::cout << "�� ����� �������� ���� ������: " << req->getDate() << std::endl;
	}
	m_reqlist.push_back(std::move(req));
}

void ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
}