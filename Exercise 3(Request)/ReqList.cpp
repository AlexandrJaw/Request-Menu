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
	else if (!isLastRoundOfInput)
	{
		cout << "INVALID INPUT" << std::endl << std::endl;
		cout << "�� �����: " << std::endl;
	}
	else
		cout << "�� �����: " << std::endl;

	//���� �������� �����
	if(!isInputsCorect(m_flags) || isLastRoundOfInput)
	{
		if (!m_flags[0])
		{
			cout << "������� ����� ����������: ";
			if (cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, dest);
			m_flags[0] = m_req->setDestination(std::move(dest));
			if (!m_flags[0]) return false; //���� ���� ��� �����������, ����� ����� ��������� ���� ����� � ������� ��� ���� ����� ��������� �� �����
		}
		else
			std::cout << " " << "1. ����� ����������: " << m_req->getDestination() << std::endl;

		if (!m_flags[1])
		{
			cout << "������� ����� ����� � ������� 'AAA000': ";
			if (cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, numFly);
			m_flags[1] = m_req->setFlyghtNumber(std::move(numFly));
			if (!m_flags[1]) return false;
		}
		else
			std::cout << " " << "2. ����� �����: " << m_req->getFlyghtNumber() << std::endl;

		if (!m_flags[2])
		{
			cout << "������� ���� ��� ������� ����� ������: ";
			if(cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, name);
			m_flags[2] = m_req->setName(std::move(name));
			if (!m_flags[2]) return false;
		}
		else
			std::cout << " " << "3. ���� ���/�������: " << m_req->getName() << std::endl;

		if (!m_flags[3])
		{
			cout << "������� �������� ���� ������ � ������� '��/��/��': ";
			if (cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, sdate);
			m_flags[3] = m_req->setDate(std::move(sdate));
			if (!m_flags[3]) return false;

			isLastRoundOfInput = true;
			return false; // ������� ���������� ��� ���� ��� �� ������� � ����� ��������� ����� ������������ 
		}
		else
			std::cout << " " << "4. �������� ���� ������: " << m_req->getDate() << std::endl;
	}
	system("pause");

	m_reqlist.push_back(std::move(m_req));
	m_flags.fill(false);

	isFirstAddThisRequest = true;
	isLastRoundOfInput = false;

	return true; // ������� ��� ���� ���� ��� ��������� � ��������� ���� ����� �������
}

bool ReqList::showAllRequests()
{
	cout << "����� ����������" << '\t' << "����� �����" << '\t' << "��� ��������" << '\t' << "�������� ���� ������" << std::endl;
	for (const auto &req : m_reqlist)
	{
		cout << req->getDestination() << '\t' << req->getFlyghtNumber() << '\t' << req->getName() << '\t' << req->getDate() << std::endl;
	}
	system("pause");
	return true;
}

bool ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
	return true;
}