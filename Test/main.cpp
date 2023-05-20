#include <functional>
#include <iostream>
#include <string>
#include <memory>


class Str
{
	std::string m_str;
public:
	Str(std::string &&str) : m_str(std::move(str)) {}

	std::string&& getStr() { return std::move(m_str); }
};

class Str2
{
	std::unique_ptr<Str> m_str;
public:
	
	void setStr()
	{
		std::string str = "Hello world!";

		m_str = std::make_unique<Str>(std::move(str));
	}

	std::string getStr()
	{
		return m_str->getStr();
	}
};
int main()
{
	
	Str2 str;
	str.setStr();

	std::cout << str.getStr() << std::endl;
	


	return 0;
}

