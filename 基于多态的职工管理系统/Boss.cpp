#include<iostream>
using namespace std;
#include"Boss.h"

//初始化
Boss::Boss(int ID, string name, int Dept)
{
	this->ID = ID;
	this->Name = name;
	this->Dept_ID = Dept;
}

//展示职工信息
void Boss::ShowInFo()
{
	cout << "编号:" << this->ID
		<< "\t姓名:" << this->Name
		<< "\t岗位:" << Boss::GetDept()
		<< "\t岗位职责:管理公司所有事务:>"
		<< endl;
}

//展示职工岗位
string Boss::GetDept()
{
	return string("老板");
}