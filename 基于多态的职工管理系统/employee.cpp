#include "employee.h"

Employee::Employee(string id, string name, int Deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = Deptid;
}

void Employee::showmessage()
{
	cout << "Ա����ID��" << this->m_id << " Ա����������" << this->m_name 
		 << " Ա���ĸ�λ" << this->getDeptname() << " ��λ��ţ�"<< this->m_Deptid << " ��λְ����ɾ�����������" <<  endl;
}

string Employee::getDeptname()
{
	return string("��ͨԱ��");
}