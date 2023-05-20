#include <functional>
#include <iostream>
#include <string>
#include <memory>



int main()
{
	int a = 0;
	while (true)
	{
		std::cin >> a;
		switch (a)
		{
		case 0: std::cout << a; break;
		case 1: std::cout << a; break;
		case 2: std::cout << a; break;
		case 3: std::cout << a; break;
		case 4: std::cout << a; break;
		case 5: std::cout << a; break;
		case 6: std::cout << a; break;
		default:
			break;
		}
	}

	return 0;
}