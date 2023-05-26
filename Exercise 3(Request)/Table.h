#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include <functional>

class Table
{
private:
	std::vector<std::vector<std::string>> m_rawTable;
	int m_activeLine;
	bool m_nxlnFlag;
public:
	Table() : m_activeLine(0), m_nxlnFlag(true) {}
	Table(Table &table) { m_rawTable = table.m_rawTable; }
	Table(Table &&table) { m_rawTable = std::move(table.m_rawTable); }

	void setnxlnFlagT() { m_nxlnFlag = true; }
	void setnxlnFlagF() { m_nxlnFlag = false; }
	void shiftPtrLine() { ++m_activeLine; }

	Table& operator<<(const std::string &cell);
	Table& operator<<(Table &table) { return table; }
	Table& operator<<(std::function<Table&(Table&)> fcn) { return fcn(*this); }

	friend std::ostream& operator<<(std::ostream &out, const Table &table);

	Table& operator=(Table &&table)
	{
		if (this == &table)
			return *this;

		m_rawTable = std::move(table.m_rawTable);
		return *this;
	}
};

Table& nxln(Table &table);