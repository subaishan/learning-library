#pragma once
#include"Worker.h"
#include<string>
#include<iostream>
using namespace std;

class Manager :public Worker
{
public:
	Manager(int ID, string name, int Dept);

	//չʾְ����Ϣ
	virtual void ShowInFo();

	//չʾְ����λ
	virtual string GetDept();
};