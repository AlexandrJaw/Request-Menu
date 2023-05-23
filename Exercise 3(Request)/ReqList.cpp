#include "ReqList.h"
#include <array>

bool isInputsCorect(std::array<bool, NUMBER_OF_DATA_FIELDS> &flags) // ������� ��� �������� ����������� �����
{
	for (const auto &f : flags)
		if (!f)
			return false;
	return true;
}

bool ReqList::addRequest() // ����� ���������� ����� ������ �� ���������
{
	std::string dest = "";
	std::string numFly = "";
	std::string name = "";
	std::string sdate = "";

	if (isFirstAddThisRequest)
	{
		m_req = std::make_unique<Request>(); 
		isFirstAddThisRequest = false;
	}
	else
		std::cout << "INVALID INPUT" << std::endl;
	
	//���� �������� �����
	if(!isInputsCorect(m_flags))
	{
		if (!m_flags[0])
		{
			cout << "������� ����� ����������: ";
			cin >> dest;
			m_flags[0] = m_req->setDestination(std::move(dest));
			if (!m_flags[0]) return false;
		}
		else
			std::cout << "�� ����� ����� ����������: " << m_req->getDestination() << std::endl;

		if (!m_flags[1])
		{
			cout << "������� ����� ����� � ������� 'AAA000': ";
			cin >> numFly;
			m_flags[1] = m_req->setFlyghtNumber(std::move(numFly));
			if (!m_flags[1]) return false;
		}
		else
			std::cout << "�� ����� ����� �����: " << m_req->getFlyghtNumber() << std::endl;
		if (!m_flags[2])
		{
			cout << "������� ���� ��� ������� ����� ������: ";
			cin >> name;
			m_flags[2] = m_req->setName(std::move(name));
			if (!m_flags[2]) return false;
		}
		else
			std::cout << "�� ����� ���� ���/�������: " << m_req->getName() << std::endl;
		if (!m_flags[3])
		{
			cout << "������� �������� ���� ������ � ������� '��/��/��': ";
			cin >> sdate;
			m_flags[3] = m_req->setDate(std::move(sdate));
			if (!m_flags[3]) return false;
		}
		else
			std::cout << "�� ����� �������� ���� ������: " << m_req->getDate() << std::endl;
	}
	m_reqlist.push_back(std::move(m_req));
	m_flags.fill(false);
	isFirstAddThisRequest = true;
	return true;
}

bool ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
	return true;
}