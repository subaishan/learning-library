#include<iostream>
using namespace std;
#include"employee.h"

//��ʼ��
employee::employee(int ID, string name, int Dept)
{
	this->ID = ID;
	this->Name = name;
	this->Dept_ID = Dept;
}

//չʾְ����Ϣ
void employee::ShowInFo()
{
	cout << "���:" << this->ID
		<< "\t����:" << this->Name
		<< "\t��λ:" << employee::GetDept()
		<< "\t��λְ��:��ɾ����·������Ĺ���:>"
		<< endl;
}

//չʾְ����λ
string employee::GetDept()
{
	return string("Ա��");
}