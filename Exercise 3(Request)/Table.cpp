#include "Table.h"
#include <algorithm>


Table& Table::operator<<(const std::string &cell)
{
	if(m_table.size() == 0)
		m_table.push_back(std::vector<std::string>());
	m_table.at(m_activeLine).push_back(cell);
	return *this;
}

Table& nxln(Table& table)
{
	table.addLine();
	table.shiftPtrLine();
	return table;
}

std::ostream& operator<<(std::ostream &out, const Table &table)
{
	auto copyTable = table.m_table;

	int maxSizeRow = 0;
	for (const auto &row : copyTable)
		if (maxSizeRow < row.size())
			maxSizeRow = row.size();

	int maxLengthStr = 0;
	for (int j(0); j < maxSizeRow; ++j)
	{
		for (int i(0); i < copyTable.size(); ++i)
		{
			if (j < copyTable.at(i).size())
				if (maxLengthStr < copyTable[i][j].size())
					maxLengthStr = copyTable[i][j].size();
		}

		for (int i(0); i < copyTable.size(); ++i)
		{
			if (j < copyTable.at(i).size())
				copyTable[i][j].append(" ", (maxLengthStr + 1) - copyTable[i][j].size());
		}
	}

	for (const auto &col : copyTable)
	{
		for (const auto &row : col)
		{
			out << row;
		}
		out << std::endl;
	}
	return out;
}