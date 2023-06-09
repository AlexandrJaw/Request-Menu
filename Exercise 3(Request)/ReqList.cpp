#include "ReqList.h"
#include <array>
#include <iomanip>

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
			std::cout << " " << "1. ����� ����������: " << '\t' << m_req->getDestination() << std::endl;

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
			std::cout << " " << "2. ����� �����: " << '\t' << m_req->getFlyghtNumber() << std::endl;

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
			std::cout << " " << "3. ���� ���/�������: " << '\t' << m_req->getName() << std::endl;

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
			std::cout << " " << "4. �������� ���� ������: " << '\t' << m_req->getDate() << std::endl;
	}
	system("pause");

	m_reqlist.push_back(std::move(m_req));
	m_flags.fill(false);

	isFirstAddThisRequest = true;
	isLastRoundOfInput = false;

	return true; // ������� ��� ���� ���� ��� ��������� � ��������� ���� ����� �������
}

bool ReqList::addTestData()
{
	bool suck;
	auto req = std::make_unique<Request>("Kiev", "KV123", FullName("Sasha", "Javorsky"), Date("26/05/23", suck));
	m_reqlist.push_back(std::move(req));
	req = std::make_unique<Request>("Amsterdam", "AMS753", FullName("Heinz", "Stainmeier"), Date("30/05/23", suck));
	m_reqlist.push_back(std::move(req));
	req = std::make_unique<Request>("Lviv", "LV954", FullName("Vuyko", "Boyko"), Date("27/05/23", suck));
	m_reqlist.push_back(std::move(req));
	req = std::make_unique<Request>("New York", "NY952", FullName("Edgar", "Word"), Date("30/05/23", suck));
	m_reqlist.push_back(std::move(req));

	return true;
}

bool ReqList::showAllRequests()
{
	if (m_reqlist.size() == 0)
	{
		std::cout << "�� �� ����� �� ����� ������." << std::endl;
		system("pause");
		return true;
	}
	Table table;
	table << "�" << "����� ����������" <<  "����� �����" << "��� ��������" << "�������� ���� ������" << nxln;
	int index = 1;
	for (const auto &req : m_reqlist)
	{
		table << std::to_string(index) << req->getDestination() << req->getFlyghtNumber() << req->getName() << req->getDate() << nxln;
		++index;
	}
	std::cout << table;
	system("pause");
	return true;
}

bool ReqList::deleteRequest()
{
	if (!isFirstTryDeleteThisReq)
		std::cout << "IVALID INPUT" << std::endl;

	std::cout << "������� ����� ������ ������� ������ �������: ";
	int index = 0;
	if (cin.peek() == '\n')
		cin.ignore();
	cin.clear();
	cin >> index;
	--index;
	if (index >= 0 && index < m_reqlist.size())
	{
		auto it = m_reqlist.begin();
		std::advance(it, index);
		m_reqlist.erase(it);
		std::cout << "������ �������." << std::endl;
		system("pause");
		isFirstTryDeleteThisReq = true;
		return true;
	}
	else
	{
		isFirstTryDeleteThisReq = false;
		return false;
	}
}