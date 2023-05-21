#include "ReqList.h"
#include <array>

bool isInputCorect(std::array<bool, NUMBER_OF_DATA_FIELDS> &flags) // Функция для проверки коректности ввода
{
	for (const auto &f : flags)
		if (!f)
			return false;
	return true;
}

void ReqList::addRequest() // Метод добавления новой заявки на авиабилет
{
	std::string dest = "";
	std::string numFly = 0;
	std::string name;
	std::string sdate;

	auto req = std::make_unique<Request>();

	std::array<bool, NUMBER_OF_DATA_FIELDS> flags; //Флаги для проверки коректности ввода
	for (auto &f : flags)
		f = false;

	//Цикл проверки ввода
	while (!isInputCorect(flags))
	{
		for(const auto &f : flags) // Выводит сообщение при неправильном вводе
			if (f)
			{
				system("cls");
				std::cout << "Неправильний ввод. Повторите ввод." << std::endl;
				break;
			}

		if (!flags[0])
		{
			cout << "Введите пункт назначения: ";
			cin >> dest;
			flags[0] = req->setDestination(std::move(dest));
			if (!flags[0]) continue;
		}
		else
			std::cout << "Вы ввели пункт назначения: " << req->getDestination() << std::endl;

		if (!flags[1])
		{
			cout << "Введите номер рейса в формате 'AAA000': ";
			cin >> numFly;
			flags[1] = req->setFlyghtNumber(std::move(numFly));
			if (!flags[1]) continue;
		}
		else
			std::cout << "Вы ввели номер рейса: " << req->getFlyghtNumber() << std::endl;
		if (!flags[2])
		{
			cout << "Введите ваши имя фамилию через пробел: ";
			cin >> name;
			flags[2] = req->setName(std::move(name));
			if (!flags[2]) continue;
		}
		else
			std::cout << "Вы ввели ваши имя/фамилию: " << req->getName() << std::endl;
		if (!flags[3])
		{
			cout << "Введите желаемую дату вылета в формате 'дд/мм/гг': ";
			cin >> sdate;
			flags[3] = req->setDate(std::move(sdate));
			if (!flags[3]) continue;
		}
		else
			std::cout << "Вы ввели желаемую дату вылета: " << req->getDate() << std::endl;
	}
	m_reqlist.push_back(std::move(req));
}

void ReqList::deleteRequest(int index)
{
	auto it = m_reqlist.begin();
	std::advance(it, index);
	m_reqlist.erase(it);
}