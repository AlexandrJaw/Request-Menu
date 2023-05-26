#pragma once
#include <list>
#include "Request.h"
#include <memory>
#include <iostream>
#include <array>
#include "Table.h"

constexpr int NUMBER_OF_DATA_FIELDS = 4;

using std::cin;
using std::cout;
class ReqList
{
private:
	std::list<std::unique_ptr<Request>> m_reqlist;
public:
	ReqList() : isFirstAddThisRequest(true), isLastRoundOfInput(false), isFirstTryDeleteThisReq(true) { m_flags.fill(false); }

private:
	std::unique_ptr<Request> m_req;
	std::array<bool, NUMBER_OF_DATA_FIELDS> m_flags;
	bool isFirstAddThisRequest;
	bool isLastRoundOfInput;
public:
	bool addRequest();

public:
	bool addTestData();

private:
	bool isFirstTryDeleteThisReq;
public:
	bool deleteRequest();

	bool showAllRequests();
	
};

