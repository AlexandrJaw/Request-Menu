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

		auto option1 = std::make_unique <MenuField>("�������� ��� ������", [&]() { return reqlist.showAllRequests(); });

		mainMenu.addMenuField(std::move(option1));

		Menu submenu("���������� ������");

		auto suboption1 = std::make_unique<MenuField>("�������� ����� ������", [&]() { return reqlist.addRequest(); });
		auto suboption2 = std::make_unique<MenuField>("������ �������� ������", [&]() { return reqlist.addTestData(); });

		submenu.addMenuField(std::move(suboption1));
		submenu.addMenuField(std::move(suboption2));

		mainMenu.addSubMenu(std::move(submenu));

		auto option2 = std::make_unique<MenuField>("������� ������", [&]() { return reqlist.deleteRequest(); });

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