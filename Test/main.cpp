#include <functional>
#include <iostream>


class Aaa
{
private:
	int Bbb = 0;
public:
	void setBbb(const int &b) { Bbb = b; }
};

int main()
{
	Aaa *ptr = new Aaa;

	ptr->setBbb(6);

	return 0;
}