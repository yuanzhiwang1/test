#include "workerManager.h"

WorkerManager::WorkerManager()
{
	// �ļ����������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�δ����" << endl;
		this->m_Empnum = 0;
		this->m_Emparray = NULL;
		this->m_fileempty = true;
	}

	//�ļ����ڵ�������Ϊ�����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_Empnum = 0;
		this->m_Emparray = NULL;
		this->m_fileempty = true;
	}
	int num = this->getEmpnum();
	// cout << "ְ������Ϊ��" << num << endl;  
	this->m_Empnum = num;
	cout << num << endl;
	// �������������ʼ������
	this->m_Emparray = new Worker *[this->m_Empnum];
	this->init_Emp();


}

void WorkerManager::showmenu()
{
	cout << "**********************************" << endl;
	cout << "*****  " << "��ӭʹ��ְ������ϵͳ" << "  *****" << endl;
	cout << "********  " << "0.�˳��������" << "  ********" << endl;
	cout << "********  " << "1.����ְ����Ϣ" << "  ********" << endl;
	cout << "********  " << "2.��ʾְ����Ϣ" << "  ********" << endl;
	cout << "********  " << "3.ɾ����ְְ��" << "  ********" << endl;
	cout << "********  " << "4.�޸�ְ����Ϣ" << "  ********" << endl;
	cout << "********  " << "5.����ְ����Ϣ" << "  ********" << endl;
	cout << "********  " << "6.���ձ������" << "  ********" << endl;
	cout << "********  " << "7.��������ĵ�" << "  ********" << endl;
	cout << "**********************************" << endl;
}

void WorkerManager::exitmenu()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	int size = 0;
	cout << "��������Ҫ��ӵ�����" << endl;
	cin >> size;
	if (size > 0)
	{
		int newsize = this->m_Empnum + size; //Ӧ�������������Ƿ��Ѿ���������
		Worker ** newspace = new Worker *[newsize]; //�����¿ռ�
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
			cout << "�������" << i+1 << "����ְ�����" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "�������ְ����λ" << endl;
			cout << "1������ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3�����ϰ�" << endl;
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
				cout << "�����ʽ��������������" << endl;
				break;
			}
			newspace[this->m_Empnum + i] = worker;
		}
		delete[] this->m_Emparray;
		this->m_Emparray = newspace;
		this->m_Empnum = newsize;
		cout << "�����" << size << "����ְ��" << endl;
		this->m_fileempty = false;
		this->save();
	}
	else
	{
		cout << "�����ʽ����" << endl;
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
		cout << "�ļ�Ϊ����������Ϊ��" << endl;
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
	cout << "����������ְԱ��������" << endl;
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
		cout << "�ѳɹ���ְ��" << name << "�Ƴ�ϵͳ" << endl;
	}
	else
	{
		cout << "��Ա���Ѵ�ϵͳ���Ƴ��������ٴ��Ƴ�" << endl;
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
		cout << "��������Ҫ���ĵ�ְ����Ϣ����" << endl;
		cin >> name;
		index = this->isexit(name);
		if (index >= 0)
		{
			string id;
			int deptid;
			cout << "�������ְ���µı��" << endl;
			cin >> id;
			cout << "�������ְ���µĸ�λ���" << endl;
			cout << "1������ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3�����ϰ�" << endl;
			cin >> deptid;
			this->m_Emparray[index]->m_id = id;
			this->m_Emparray[index]->m_Deptid = deptid;
			cout << "�޸ĳɹ�" << endl;
			this->save();
			system("pause");
			break;
		}
		else
		{
			cout << "��Ա�������ڣ�����������" << endl;
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
		cout << "��������Ҫ���ҵ�ְ������" << endl;
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
			cout << "��Ա�������ڣ�����������" << endl;
			system("pause");
			break;
		}
	}
}

void WorkerManager::sort_Emp()
{
	int choice = 0;
	Worker * temp = NULL;
	cout << "��ѡ������ʽ" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
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
			cout << "��������ɹ�" << endl;
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
			cout << "��������ɹ�" << endl;
			break;
		}
		else
		{
			cout << "������������������" << endl;
			break;
		}
	}
	system("pause");
}

void WorkerManager::clear_file()
{
	cout << "����ȷ����Ҫɾ�������ĵ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
		cout << "������" << endl;
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