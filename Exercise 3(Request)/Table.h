#pragma once
#include <vector>
#include <iomanip>
#include <iostream>

class Table
{
private:
	std::vector<std::vector<std::string>> m_table;
public:
	Table(Table &table) { m_table = table.m_table; }
	Table(Table &&table) { m_table = std::move(table.m_table); }

	Table& operator=(Table &&table)
	{
		if (this == &table)
			return *this;

		m_table = std::move(table.m_table);
		return *this;
	}
};

