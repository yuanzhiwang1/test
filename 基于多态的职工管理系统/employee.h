#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(string id, string name, int Deptid);
	void showmessage();
	string getDeptname();
};