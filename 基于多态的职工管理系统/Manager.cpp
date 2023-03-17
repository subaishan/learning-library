#include<iostream>
using namespace std;
#include"Manager.h"

//初始化
Manager::Manager(int ID, string name, int Dept)
{
	this->ID = ID;
	this->Name = name;
	this->Dept_ID = Dept;
}

//展示职工信息
void Manager::ShowInFo()
{
	cout << "编号:" << this->ID
		<< "\t姓名:" << this->Name
		<< "\t岗位:" << Manager::GetDept()
		<< "\t岗位职责:给员工分配工作,完成老板下发下来的工作:>"
		<< endl;
}

//展示职工岗位
string Manager::GetDept()
{
	return string("经理");
}