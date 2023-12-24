#include "employee.h"

Employee::Employee(string id, string name, int Deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = Deptid;
}

void Employee::showmessage()
{
	cout << "员工的ID：" << this->m_id << " 员工的姓名：" << this->m_name 
		 << " 员工的岗位" << this->getDeptname() << " 岗位编号："<< this->m_Deptid << " 岗位职责：完成经理交给的任务" <<  endl;
}

string Employee::getDeptname()
{
	return string("普通员工");
}