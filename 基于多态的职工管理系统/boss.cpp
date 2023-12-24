#include "boss.h"

Boss::Boss(string id, string name, int Deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = Deptid;
}
void Boss::showmessage()
{
	cout << "员工的ID：" << this->m_id << " 员工的姓名：" << this->m_name
		<< " 员工的岗位" << this->getDeptname() << " 岗位编号：" << this->m_Deptid
		<< " 岗位职责：管理公司所有事务" << endl;
}
string Boss::getDeptname()
{
	return string("老板");
}