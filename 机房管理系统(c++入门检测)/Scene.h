#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Scene
{
public:
	//建立登录界面
	void signIn();

	//接收账号密码
	vector<int, map<string, int>> ID;

	//验证账号密码
	int checking_ID();

	//创建学生组

	//创建老师组

	//创建机房组

};

