#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFILE.txt"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	void showmenu();

	void exitmenu();

	void Add_Emp();

	void save();

	int getEmpnum();

	void init_Emp();

	void show_Emp();

	int isexit(string name);

	void delete_Emp();

	void change_Emp();

	void find_Emp();

	void sort_Emp();

	void clear_file();

	~WorkerManager();
public:
	int m_Empnum;
	bool m_fileempty;
	Worker ** m_Emparray;
};
