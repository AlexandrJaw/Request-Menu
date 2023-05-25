#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include <functional>

class Table
{
private:
	std::vector<std::vector<std::string>> m_table;
	int m_activeLine;
public:
	Table() : m_activeLine(0) {}
	Table(Table &table) { m_table = table.m_table; }
	Table(Table &&table) { m_table = std::move(table.m_table); }

	void addLine() { m_table.push_back(std::vector<std::string>()); }
	void shiftPtrLine() { ++m_activeLine; }

	Table& operator<<(const std::string &cell);
	Table& operator<<(Table &table) { return table; }
	Table& operator<<(std::function<Table&(Table&)> fcn) { return fcn(*this); }

	friend std::ostream& operator<<(std::ostream &out, const Table &table);

	Table& operator=(Table &&table)
	{
		if (this == &table)
			return *this;

		m_table = std::move(table.m_table);
		return *this;
	}
};

Table& nxln(Table &table);