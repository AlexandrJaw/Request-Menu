#include "Table.h"
#include <algorithm>


Table& Table::operator<<(const std::string &cell)
{
	if (m_rawTable.size() == 0 || m_nxlnFlag)
	{
		m_rawTable.push_back(std::vector<std::string>());
		m_nxlnFlag = false;
	}
	m_rawTable.at(m_activeLine).push_back(cell);
	return *this;
}

Table& nxln(Table& table)
{
	table.setnxlnFlagT();
	table.shiftPtrLine();
	return table;
}

std::ostream& operator<<(std::ostream &out, const Table &table)
{
	auto finishedTable = table.m_rawTable;

	int maxSizeRow = 0;
	for (const auto &row : finishedTable)
		if (maxSizeRow < row.size())
			maxSizeRow = row.size();

	for (int j(0); j < maxSizeRow; ++j)
	{
		int maxLengthStr = 0;
		for (int i(0); i < finishedTable.size(); ++i)
		{
			if (j < finishedTable.at(i).size())
				if (maxLengthStr < finishedTable[i][j].size())
					maxLengthStr = finishedTable[i][j].size();
		}

		for (int i(0); i < finishedTable.size(); ++i)
		{
			if (j < finishedTable.at(i).size())
			{
				finishedTable[i][j].append(maxLengthStr + 1 - finishedTable[i][j].size(), ' ');
				finishedTable[i][j] += '|';
			}
		}
	}

	int strSizeRow = 0;
	for (const auto &col : finishedTable[0])
		strSizeRow += col.size();

	out << std::string(strSizeRow, '-') << std::endl;

	for (const auto &col : finishedTable)
	{
		for (const auto &row : col)
		{
			out << row;
		}
		out << std::endl;
		out << std::string(strSizeRow, '-') << std::endl;
	}
	return out;
}