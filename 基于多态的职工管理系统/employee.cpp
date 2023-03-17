#include<iostream>
using namespace std;
#include"employee.h"

//初始化
employee::employee(int ID, string name, int Dept)
{
	this->ID = ID;
	this->Name = name;
	this->Dept_ID = Dept;
}

//展示职工信息
void employee::ShowInFo()
{
	cout << "编号:" << this->ID
		<< "\t姓名:" << this->Name
		<< "\t岗位:" << employee::GetDept()
		<< "\t岗位职责:完成经理下发下来的工作:>"
		<< endl;
}

//展示职工岗位
string employee::GetDept()
{
	return string("员工");
}