#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:

	//展示职工信息
	virtual void ShowInFo() = 0;

	//展示职工岗位
	virtual string GetDept() = 0;

	//职工编号
	int ID;
	//职工姓名
	string Name;
	//职工岗位
	int Dept_ID;
};
