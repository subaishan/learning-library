#pragma once

#include<string>
#include<iostream>
#include"student.h"

using namespace std;

typedef class Mylist
{
public:
	//������
	student stu;

	//ָ����
	Mylist* next;

	void heard_getelem();

	void print();
}*mylist;

