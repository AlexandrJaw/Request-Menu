#include "Table.h"

Table& Table::operator<<(std::string &&cell)
{
	if(m_table.size() == 0)
		m_table.push_back(std::vector<std::string>());
	m_table.at(m_activeLine).push_back(cell);
	return *this;
}

Table& Table::nextLine()
{
	m_table.push_back(std::vector<std::string>());
	++m_activeLine;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Table &table)
{
	auto copyTable = table.m_table;

	int maxLengthStr = 0;
	for(int i(0); i < copyTable.size(); ++i)
		for (int j(0); j < copyTable.at(i).size(); ++j)
		{
			if(maxLengthStr < copyTable[i][j].size())
				maxLengthStr = copyTable[i][j].size();   //TODO: Доделать выравнивание таблицы
		}
}