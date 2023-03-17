#pragma once    //防止头文件重复包含
#include<iostream>     //标准输入输出流
using namespace std;   //命名空间
#include"Worker.h"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	
	//展示菜单
	void Show_Muse();

	//职工人数
	int Empnum;

	//职工数组
	Worker** Emparray;

	//增加职工
	void AddEmp();

	//文件接口
	void save();

	//判断文件是否存在
	bool FileIsEmpty;

	//统计文件中职工人数
	int Get_Empnum();

	//初始化职工
	void init_Emp();

	//职工信息展示接口
	void Show_Emp();

	//删除职工接口
	void Del_Emp();

	//判断职工是否存在并返回一个值
	int IsExist(int Choice);

	//查找职工接口
	void FindEmp();

	//修改职工接口
	void Mod_Emp();

	//职工排序接口
	void Sort_Emp();

	//删除全部职工接口
	void Clean_File();

	//退出系统接口
	void SystemExit();

	//析构函数
	~WorkerManager();
};