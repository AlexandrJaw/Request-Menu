#include <iostream>
#include "Menu.h"
#include <exception>
#include <list>
#include "ReqList.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		ReqList reqlist;
		
		Menu mainMenu;

		auto option1 = std::make_unique <MenuField>("Показать все заявки", [&]() { return reqlist.showAllRequests(); });

		mainMenu.addMenuField(std::move(option1));

		Menu submenu("Добавление заявок");

		auto suboption1 = std::make_unique<MenuField>("Добавить новую заявку", [&]() { return reqlist.addRequest(); });
		auto suboption2 = std::make_unique<MenuField>("Ввести тестовые данные", [&]() { return reqlist.addTestData(); });

		submenu.addMenuField(std::move(suboption1));
		submenu.addMenuField(std::move(suboption2));

		mainMenu.addSubMenu(std::move(submenu));

		auto option2 = std::make_unique<MenuField>("Удалить заявку", [&]() { return reqlist.deleteRequest(); });

		mainMenu.addMenuField(std::move(option2));

		mainMenu.run();
		
	}
	catch (std::exception &excep)
	{
		std::cout << excep.what();
	}
	

	getchar();
	return 0;
}