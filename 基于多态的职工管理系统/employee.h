#pragma once
#include"Worker.h"
#include<string>
#include<iostream>
using namespace std;

class employee:public Worker
{
public:
	employee(int ID,string name,int Dept);
	
	//չʾְ����Ϣ
	virtual void ShowInFo();

	//չʾְ����λ
	virtual string GetDept();
};