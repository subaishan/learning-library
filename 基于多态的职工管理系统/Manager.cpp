#include<iostream>
using namespace std;
#include"Manager.h"

//��ʼ��
Manager::Manager(int ID, string name, int Dept)
{
	this->ID = ID;
	this->Name = name;
	this->Dept_ID = Dept;
}

//չʾְ����Ϣ
void Manager::ShowInFo()
{
	cout << "���:" << this->ID
		<< "\t����:" << this->Name
		<< "\t��λ:" << Manager::GetDept()
		<< "\t��λְ��:��Ա�����乤��,����ϰ��·������Ĺ���:>"
		<< endl;
}

//չʾְ����λ
string Manager::GetDept()
{
	return string("����");
}