#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	virtual void showmessage() = 0;

	virtual string getDeptname() = 0;

	string m_id;
	string m_name;
	int m_Deptid;
};