#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class Manager: public Worker
{
public:
	Manager(string id,string name,int Deptid);
	void showmessage();
	string getDeptname();
};