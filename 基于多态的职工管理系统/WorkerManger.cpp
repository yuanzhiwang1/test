#include "workerManager.h"

WorkerManager::WorkerManager()
{
	// 文件不存在情况
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件未创建" << endl;
		this->m_Empnum = 0;
		this->m_Emparray = NULL;
		this->m_fileempty = true;
	}

	//文件存在但是内容为空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_Empnum = 0;
		this->m_Emparray = NULL;
		this->m_fileempty = true;
	}
	int num = this->getEmpnum();
	// cout << "职工个数为：" << num << endl;  
	this->m_Empnum = num;
	cout << num << endl;
	// 第三种情况，初始化数组
	this->m_Emparray = new Worker *[this->m_Empnum];
	this->init_Emp();


}

void WorkerManager::showmenu()
{
	cout << "**********************************" << endl;
	cout << "*****  " << "欢迎使用职工管理系统" << "  *****" << endl;
	cout << "********  " << "0.退出管理程序" << "  ********" << endl;
	cout << "********  " << "1.增加职工信息" << "  ********" << endl;
	cout << "********  " << "2.显示职工信息" << "  ********" << endl;
	cout << "********  " << "3.删除离职职工" << "  ********" << endl;
	cout << "********  " << "4.修改职工信息" << "  ********" << endl;
	cout << "********  " << "5.查找职工信息" << "  ********" << endl;
	cout << "********  " << "6.按照编号排序" << "  ********" << endl;
	cout << "********  " << "7.清空所有文档" << "  ********" << endl;
	cout << "**********************************" << endl;
}

void WorkerManager::exitmenu()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	int size = 0;
	cout << "请输入需要添加的人数" << endl;
	cin >> size;
	if (size > 0)
	{
		int newsize = this->m_Empnum + size; //应当考虑数组中是否已经包含数据
		Worker ** newspace = new Worker *[newsize]; //开辟新空间
		if (this->m_Empnum != 0)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newspace[i] = this->m_Emparray[i];
			}
		}
		for (int i = 0; i < size; i++)
		{	
		    string id = "NULL";
			string name = "NULL";
			int Deptid = 0;
			cout << "请输入第" << i+1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "请输入该职工岗位" << endl;
			cout << "1代表普通员工" << endl;
			cout << "2代表经理" << endl;
			cout << "3代表老板" << endl;
			cin >> Deptid;
			Worker * worker = NULL;
			switch (Deptid)
			{
			case 1:
				worker = new Employee(id, name, Deptid);
				break;
			case 2:
				worker = new Manager(id, name, Deptid);
				break;
			case 3:
				worker = new Boss(id, name, Deptid);
				break;
			default:
				cout << "输入格式有误，请重新输入" << endl;
				break;
			}
			newspace[this->m_Empnum + i] = worker;
		}
		delete[] this->m_Emparray;
		this->m_Emparray = newspace;
		this->m_Empnum = newsize;
		cout << "已添加" << size << "名新职工" << endl;
		this->m_fileempty = false;
		this->save();
	}
	else
	{
		cout << "输入格式错误" << endl;
	}
	system("pause");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_Emparray[i]->m_id << " "
			<< this->m_Emparray[i]->m_name << " "
			<< this->m_Emparray[i]->m_Deptid << " "
			<< endl;
	}
	ofs.close();
}

int WorkerManager::getEmpnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0;
	string id;
	string name;
	int dept;
	while (ifs >> id && ifs >> name && ifs >> dept)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string id;
	string name;
	int deptid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		class Worker * worker = NULL;
		if (deptid == 1)  
		{
			worker = new Employee(id, name, deptid);
		}
		else if (deptid == 2) 
		{
			worker = new Manager(id, name, deptid);
		}
		else 
		{
			worker = new Boss(id, name, deptid);
		}
		this->m_Emparray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::show_Emp()
{
	if (this->m_fileempty)
	{
		cout << "文件为创建或内容为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			this->m_Emparray[i]->showmessage();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::isexit(string name)
{
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_Emparray[i]->m_name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::delete_Emp()
{
	cout << "请输入已离职员工的姓名" << endl;
	string name;
	cin >> name;
	int index = this->isexit(name);
	if (index >= 0)
	{
		for (int i = index; i < this->getEmpnum()-1; i++)
		{
			this->m_Emparray[i] = this->m_Emparray[i + 1];
		}
		this->m_Empnum--;
		this->save();
		cout << "已成功将职工" << name << "移除系统" << endl;
	}
	else
	{
		cout << "该员工已从系统中移除，无需再次移除" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::change_Emp()
{
	while (1)
	{
		string name;
		int index = 0;
		cout << "请输入需要更改的职工信息姓名" << endl;
		cin >> name;
		index = this->isexit(name);
		if (index >= 0)
		{
			string id;
			int deptid;
			cout << "请输入该职工新的编号" << endl;
			cin >> id;
			cout << "请输入该职工新的岗位编号" << endl;
			cout << "1代表普通员工" << endl;
			cout << "2代表经理" << endl;
			cout << "3代表老板" << endl;
			cin >> deptid;
			this->m_Emparray[index]->m_id = id;
			this->m_Emparray[index]->m_Deptid = deptid;
			cout << "修改成功" << endl;
			this->save();
			system("pause");
			break;
		}
		else
		{
			cout << "该员工不存在，请重新输入" << endl;
			system("pause");
			break;
		}
	}

}

void WorkerManager::find_Emp()
{
	while (1)
	{
		string name;
		int index = 0;
		cout << "请输入需要查找的职工姓名" << endl;
		cin >> name;
		index = this->isexit(name);
		if (index >= 0)
		{
			this->m_Emparray[index]->showmessage();
			system("pause");
			break;
		}
		else
		{
			cout << "该员工不存在，请重新输入" << endl;
			system("pause");
			break;
		}
	}
}

void WorkerManager::sort_Emp()
{
	int choice = 0;
	Worker * temp = NULL;
	cout << "请选择排序方式" << endl;
	cout << "1.降序" << endl;
	cout << "2.升序" << endl;
	cin >> choice;
	while (1)
	{
		if (choice == 1)
		{
			for (int i = 0; i < this->m_Empnum - 1; i++)
			{
				for (int j = i; j < this->m_Empnum - 1; j++)
				{
					if (stoi(this->m_Emparray[i]->m_id) < stoi(this->m_Emparray[j + 1]->m_id))
					{
						temp = this->m_Emparray[i];
						this->m_Emparray[i] = this->m_Emparray[j + 1];
						this->m_Emparray[j + 1] = temp;
					}
				}
			}
			this->save();
			cout << "降序排序成功" << endl;
			break;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < this->m_Empnum - 1; i++)
			{
				for (int j = i; j < this->m_Empnum - 1; j++)
				{
					if (stoi(this->m_Emparray[i]->m_id) > stoi(this->m_Emparray[j + 1]->m_id))
					{
						temp = this->m_Emparray[i];
						this->m_Emparray[i] = this->m_Emparray[j + 1];
						this->m_Emparray[j + 1] = temp;
					}
				}
			}
			this->save();
			cout << "升序排序成功" << endl;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	system("pause");
}

void WorkerManager::clear_file()
{
	cout << "请问确定需要删除所有文档吗" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		for (int i = 0; i < this->m_Empnum; i++)
		{
			if (this->m_Emparray[i] != NULL)
			{
				delete this->m_Emparray[i];
			}
		}
		this->m_Empnum = 0;
		delete[] this->m_Emparray;
		this->m_Emparray = NULL;
		this->m_fileempty = true;
		cout << "清空完毕" << endl;
	}

}

WorkerManager::~WorkerManager()
{
	if (this->m_Emparray != NULL)
	{
		delete[] this->m_Emparray;
		this->m_Emparray = NULL;

	}
}