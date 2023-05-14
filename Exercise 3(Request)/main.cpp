#include <iostream>
#include "Menu.h"

int main()
{
	Menu mainMenu;

	MenuField option1("option 1", []() {});
	MenuField option2("option 2", []() {});
	MenuField option3("option 3", []() {});

	mainMenu.addMenuField(std::make_unique<MenuField>(option1));
	mainMenu.addMenuField(std::make_unique<MenuField>(option2));
	mainMenu.addMenuField(std::make_unique<MenuField>(option3));

	Menu submenu;

	MenuField suboption("sub", []() {});

	submenu.addMenuField(std::make_unique<MenuField>(suboption));

	//mainMenu.addSubMenu(std::move(submenu));

	mainMenu.run();

	getchar();
	return 0;
}