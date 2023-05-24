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
	else if (!isLastRoundOfInput)
	{
		cout << "INVALID INPUT" << std::endl << std::endl;
		cout << "Вы ввели: " << std::endl;
	}
	else
		cout << "Вы ввели: " << std::endl;

	//Цикл проверки ввода
	if(!isInputsCorect(m_flags) || isLastRoundOfInput)
	{
		if (!m_flags[0])
		{
			cout << "Введите пункт назначения: ";
			if (cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, dest);
			m_flags[0] = m_req->setDestination(std::move(dest));
			if (!m_flags[0]) return false; //Если ввод был некоректным, тогда нужно повторить цикл ввода с выводом при этом всего введённого до этого
		}
		else
			std::cout << " " << "1. Пункт назначения: " << m_req->getDestination() << std::endl;

		if (!m_flags[1])
		{
			cout << "Введите номер рейса в формате 'AAA000': ";
			if (cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, numFly);
			m_flags[1] = m_req->setFlyghtNumber(std::move(numFly));
			if (!m_flags[1]) return false;
		}
		else
			std::cout << " " << "2. Номер рейса: " << m_req->getFlyghtNumber() << std::endl;

		if (!m_flags[2])
		{
			cout << "Введите ваши имя фамилию через пробел: ";
			if(cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, name);
			m_flags[2] = m_req->setName(std::move(name));
			if (!m_flags[2]) return false;
		}
		else
			std::cout << " " << "3. Ваши имя/фамилия: " << m_req->getName() << std::endl;

		if (!m_flags[3])
		{
			cout << "Введите желаемую дату вылета в формате 'дд/мм/гг': ";
			if (cin.peek() == '\n')
				cin.ignore();
			std::getline(cin, sdate);
			m_flags[3] = m_req->setDate(std::move(sdate));
			if (!m_flags[3]) return false;

			isLastRoundOfInput = true;
			return false; // Команда необходима для того что бы вывести в конце результат ввода пользователя 
		}
		else
			std::cout << " " << "4. Желаемая дата вылета: " << m_req->getDate() << std::endl;
	}
	system("pause");

	m_reqlist.push_back(std::move(m_req));
	m_flags.fill(false);

	isFirstAddThisRequest = true;
	isLastRoundOfInput = false;

	return true; // Означет что весь ввод был коректным и повторять цикл ввода ненужно
}

bool ReqList::showAllRequests()
{
	cout << "Пункт назначения" << '\t' << "Номер рейса" << '\t' << "ФИО пасажира" << '\t' << "Желаемая дата вылета" << std::endl;
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