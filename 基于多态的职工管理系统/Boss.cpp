#include<iostream>
using namespace std;
#include"Boss.h"

//��ʼ��
Boss::Boss(int ID, string name, int Dept)
{
	this->ID = ID;
	this->Name = name;
	this->Dept_ID = Dept;
}

//չʾְ����Ϣ
void Boss::ShowInFo()
{
	cout << "���:" << this->ID
		<< "\t����:" << this->Name
		<< "\t��λ:" << Boss::GetDept()
		<< "\t��λְ��:����˾��������:>"
		<< endl;
}

//չʾְ����λ
string Boss::GetDept()
{
	return string("�ϰ�");
}