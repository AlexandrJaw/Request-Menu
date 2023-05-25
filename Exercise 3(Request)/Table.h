#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>

class Table
{
private:
	std::vector<std::vector<std::string>> m_table;
	int m_activeLine;
public:
	Table() : m_activeLine(0) {}
	Table(Table &table) { m_table = table.m_table; }
	Table(Table &&table) { m_table = std::move(table.m_table); }

	Table& nextLine();

	Table& operator<<(std::string &&cell);
	Table& operator<<(Table &table) {}
	friend std::ostream& operator<<(std::ostream &out, const Table &table);

	Table& operator=(Table &&table)
	{
		if (this == &table)
			return *this;

		m_table = std::move(table.m_table);
		return *this;
	}
};

