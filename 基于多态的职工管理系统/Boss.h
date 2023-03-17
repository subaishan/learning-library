#pragma once
#include"Worker.h"
#include<string>
#include<iostream>
using namespace std;

class Boss :public Worker
{
public:
	Boss(int ID, string name, int Dept);

	//展示职工信息
	virtual void ShowInFo();

	//展示职工岗位
	virtual string GetDept();
};