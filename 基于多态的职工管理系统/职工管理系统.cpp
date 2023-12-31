#include <iostream>
#include <string>
#include <fstream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
//实现一个基于多态的职工管理系统
//公司中职工分为三类 : 普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责普通员工职责:完成经理交给的任务
//	经理职责 : 完成老板交给的任务，并下发任务给员工
//	老板职责 : 管理公司所有事务
//管理系统中需要实现的功能如下 :
//	退出管理程序:退出当前管理系统
//	增加职工信息 : 实现批量添加职工功能，将信息录入到文件中，职工信息为:职工编号、姓名、部门编号
//	显示职工信息 : 显示公司内部所有职工的信息
//	删除离职职工 : 按照编号删除指定的职工
//  修改职工信息:按照编号修改职工个人信息
//  查找职工信息 : 按照职工的编号或者职工的姓名进行查找相关的人员信息
//  按照编号排序 : 按照职工编号，进行排序，排序规则由用户指定
//  清空所有文档 : 清空文件中记录的所有职工信息(清空前需要再次确认，防止误删)

int main() {
	class WorkerManager wm;
	wm.showmenu();
	int choice = 0;
	////测试员工，经理，老板的三个类是否正常运行
	//class Worker * worker = NULL;
	//worker = new Employee("1", "张三", "1");
	//worker->showmessage();

	//worker = new Manager("2", "李四", "2");
	//worker->showmessage();

	//worker = new Boss("3", "王五", "3");
	//worker->showmessage();

	while (1)
	{
		cout << "请输入0-7的整数" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitmenu();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.delete_Emp();
			break;
		case 4:
			wm.change_Emp();
			break;
		case 5:
			wm.find_Emp();
			break;
		case 6:
			wm.sort_Emp();
			break;
		case 7:
			wm.clear_file();
			break;
		default:
			system("cls");
			wm.showmenu();
			cout << "输入格式错误，请重新输入0-7的整数" << endl;
		}
		system("cls");
		wm.showmenu();
	}
				
	

	return 0;
}