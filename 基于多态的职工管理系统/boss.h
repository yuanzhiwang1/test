#pragma once
#include <iostream>
#include "worker.h"
using namespace std;


class Boss : public Worker
{
public:
	Boss(string id, string name, int Deptid);
	void showmessage();
	string getDeptname();
};