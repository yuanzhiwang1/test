#include"manager.h"

Manager::Manager(string id, string name, int Deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = Deptid;
}


void Manager::showmessage()
{
	cout << "Ա����ID��" << this->m_id << " Ա����������" << this->m_name
		 << " Ա���ĸ�λ" << this->getDeptname() << " ��λ��ţ�" << this->m_Deptid 
		 << " ��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}
string Manager::getDeptname()
{
	return string("����");
}
