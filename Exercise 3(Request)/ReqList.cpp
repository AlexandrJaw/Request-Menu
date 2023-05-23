#include "ReqList.h"
#include <array>

bool isInputsCorect(std::array<bool, NUMBER_OF_DATA_FIELDS> &flags) // Функция для проверки коректности ввода
{
	for (const auto &f : flags)
		if (!f)
			return false;
	return true;
}

bool ReqList::addRequest() // Метод добавления новой заявки на авиабилет
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
	
	//Цикл проверки ввода
	if(!isInputsCorect(m_flags))
	{
		if (!m_flags[0])
		{
			cout << "Введите пункт назначения: ";
			cin >> dest;
			m_flags[0] = m_req->setDestination(std::move(dest));
			if (!m_flags[0]) return false;
		}
		else
			std::cout << "Вы ввели пункт назначения: " << m_req->getDestination() << std::endl;

		if (!m_flags[1])
		{
			cout << "Введите номер рейса в формате 'AAA000': ";
			cin >> numFly;
			m_flags[1] = m_req->setFlyghtNumber(std::move(numFly));
			if (!m_flags[1]) return false;
		}
		else
			std::cout << "Вы ввели номер рейса: " << m_req->getFlyghtNumber() << std::endl;
		if (!m_flags[2])
		{
			cout << "Введите ваши имя фамилию через пробел: ";
			cin >> name;
			m_flags[2] = m_req->setName(std::move(name));
			if (!m_flags[2]) return false;
		}
		else
			std::cout << "Вы ввели ваши имя/фамилию: " << m_req->getName() << std::endl;
		if (!m_flags[3])
		{
			cout << "Введите желаемую дату вылета в формате 'дд/мм/гг': ";
			cin >> sdate;
			m_flags[3] = m_req->setDate(std::move(sdate));
			if (!m_flags[3]) return false;
		}
		else
			std::cout << "Вы ввели желаемую дату вылета: " << m_req->getDate() << std::endl;
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