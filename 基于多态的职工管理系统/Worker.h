#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:

	//չʾְ����Ϣ
	virtual void ShowInFo() = 0;

	//չʾְ����λ
	virtual string GetDept() = 0;

	//ְ�����
	int ID;
	//ְ������
	string Name;
	//ְ����λ
	int Dept_ID;
};
