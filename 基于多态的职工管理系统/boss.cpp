#include "boss.h"

Boss::Boss(string id, string name, int Deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = Deptid;
}
void Boss::showmessage()
{
	cout << "Ա����ID��" << this->m_id << " Ա����������" << this->m_name
		<< " Ա���ĸ�λ" << this->getDeptname() << " ��λ��ţ�" << this->m_Deptid
		<< " ��λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptname()
{
	return string("�ϰ�");
}