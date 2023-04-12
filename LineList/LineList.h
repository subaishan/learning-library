#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//宏定义区
#define MAXSIZE 100
//数据表类型
typedef int ElemType;

class LineList
{
private:
	//这是数据区，设为私有权限，仅开放成员函数能调用
	ElemType* data;		//数据,推荐将数组下标为零的地方设为空值。这样做便于某些函数的操作
	int len;		//长度
	int size;		//当前最大长度

public:
	//这是成员函数区，设为公共权限
	LineList();		//构造函数初始化线性表
	~LineList();
	
	bool getBiggerSpace();		//基本扩容函数

	//基本函数
	int getLength();		//获得线性表长度
	bool getAllData();		//打印全部数据
	bool ListIsEmpty();		//判断线性表是否为空
	bool DestroyList();		//销毁线性表
	ElemType getData(int palce);		//获得线性表特定位置数据
	int searchData(int num);		//查找线性表中特定数值的元素并返回下标
	bool addData(int palce, ElemType value);		//在线性表中位置palce插入一个元素		//设计时可以使用函数的重载
	ElemType deleteData(int palce);		//删除线性表中位置palce的元素

	//额外函数
	int addData(ElemType, bool _switch = false);		//头插法和尾插法，尾插法开关时bool值,默认调用头插法,该方法和基本方法重载，返回值为添加元素位置的下标

	//算法
	bool deleteSomeoneData(int value, bool _switch = false);		//删除该表中数据大小为x的所以数据元素,其中有两种实现方式
	bool partitionl(bool _switch = false);		//以第一个元素为基准元素，将大于基准元素的数排在基准元素之后，将小于基准元素的元素排在基准元素之前。
	int quick_sort_1(int left = 0, int right = -1);		
	bool quick_sort(int left = 0, int right = -1);//快速排序


	//作业题
	bool fun_1(int left, int right);			//删除表中数据大小再区间(left,right)中的元素
	int fun_2(int value);					//在有序链表中找到合适的位置插入数value,采用二分查找法.
};

