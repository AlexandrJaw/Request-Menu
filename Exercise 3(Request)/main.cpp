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

		auto option1 = std::make_unique <MenuField>("Добавить заявку", [&]() { reqlist.addRequest(); });
		auto option2 = std::make_unique <MenuField>("option 2", []() {});
		auto option3 = std::make_unique <MenuField>("option 3", []() {});

		mainMenu.addMenuField(std::move(option1));
		mainMenu.addMenuField(std::move(option2));
		mainMenu.addMenuField(std::move(option3));

		//auto submenu = std::make_shared<Menu>("Submenu");
		Menu submenu("Submenu");

		auto suboption = std::make_unique<MenuField>("suboption", []() {});

		submenu.addMenuField(std::move(suboption));

		mainMenu.addSubMenu(std::move(submenu));

		mainMenu.run();
		
	}
	catch (std::exception &excep)
	{
		std::cout << excep.what();
	}
	

	getchar();
	return 0;
}