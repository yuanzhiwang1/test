#include <iostream>
#include <string>
#include <fstream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
//ʵ��һ�����ڶ�̬��ְ������ϵͳ
//��˾��ְ����Ϊ���� : ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ����ͨԱ��ְ��:��ɾ�����������
//	����ְ�� : ����ϰ彻�������񣬲��·������Ա��
//	�ϰ�ְ�� : ����˾��������
//����ϵͳ����Ҫʵ�ֵĹ������� :
//	�˳��������:�˳���ǰ����ϵͳ
//	����ְ����Ϣ : ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�ְ����ϢΪ:ְ����š����������ű��
//	��ʾְ����Ϣ : ��ʾ��˾�ڲ�����ְ������Ϣ
//	ɾ����ְְ�� : ���ձ��ɾ��ָ����ְ��
//  �޸�ְ����Ϣ:���ձ���޸�ְ��������Ϣ
//  ����ְ����Ϣ : ����ְ���ı�Ż���ְ�����������в�����ص���Ա��Ϣ
//  ���ձ������ : ����ְ����ţ�������������������û�ָ��
//  ��������ĵ� : ����ļ��м�¼������ְ����Ϣ(���ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ)

int main() {
	class WorkerManager wm;
	wm.showmenu();
	int choice = 0;
	////����Ա���������ϰ���������Ƿ���������
	//class Worker * worker = NULL;
	//worker = new Employee("1", "����", "1");
	//worker->showmessage();

	//worker = new Manager("2", "����", "2");
	//worker->showmessage();

	//worker = new Boss("3", "����", "3");
	//worker->showmessage();

	while (1)
	{
		cout << "������0-7������" << endl;
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
			cout << "�����ʽ��������������0-7������" << endl;
		}
		system("cls");
		wm.showmenu();
	}
				
	

	return 0;
}