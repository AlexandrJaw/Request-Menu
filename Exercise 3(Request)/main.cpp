#include <iostream>
#include "Menu.h"
#include <exception>
int main()
{
	try
	{
		{
			Menu mainMenu;

			MenuField option1("option 1", []() {});
			MenuField option2("option 2", []() {});
			MenuField option3("option 3", []() {});

			mainMenu.addMenuField(std::make_unique<MenuField>(option1));
			mainMenu.addMenuField(std::make_unique<MenuField>(option2));
			mainMenu.addMenuField(std::make_unique<MenuField>(option3));

			auto submenu = std::make_shared<Menu>("Submenu");

			MenuField suboption("suboption", []() {});

			submenu->addMenuField(std::make_unique<MenuField>(suboption));

			mainMenu.addSubMenu(std::move(submenu));

			mainMenu.run();
		}
	}
	catch (std::exception &excep)
	{
		std::cout << excep.what();
	}
	

	getchar();
	return 0;
}