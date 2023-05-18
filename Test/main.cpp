#include <functional>
#include <iostream>
#include <string>
#include <memory>

class A
{
private:
	std::string m_str = "";
public:
	void setStr(const std::string &str) { m_str = str; }
};

int main()
{
	auto ptr = std::make_unique<A>();

	ptr->setStr("str");

	return 0;
}