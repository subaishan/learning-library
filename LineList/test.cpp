#include<iostream>
using namespace std;
#include"LineList.h"
#include"test.h"

int main()
{
	//list_text();
	//cout << endl;
	//partitonl_text();
	//quickSort_test();
	//fun_1_test();
	//fun_2_test();
	return 0;
}

bool list_text()			//基本函数测试
{
	LineList list;
	for (int i = 0; i < 10; i++)
	{
		list.addData(i);
	}
	list.deleteData(2);
	list.getAllData();
	list.addData(3);
	cout << "线性表长度" << list.getLength() << endl;
	list.deleteSomeoneData(3, true);
	cout << "线性表长度" << list.getLength() << endl;
	list.getAllData();

	return true;
}

bool partitonl_text()		//一重快速排序算法测试(例2.4)
{
	LineList list;
	for (int i = 0; i < 10; i++)
	{
		list.addData(i);
	}
	list.addData(12);
	list.addData(1, 11);
	list.addData(14);
	list.addData(13);
	list.addData(11);

	list.getAllData();
	list.partitionl(true);
	list.getAllData();

	cout << endl;
	list.partitionl(false);
	list.getAllData();
	return true;
}

bool quickSort_test()			//快速排序算法
{
	LineList list;
	for (int i = 0; i < 3; i++)
	{
		list.addData(i);
	}
	list.addData(12);
	list.addData(1, 11);
	list.addData(14);
	list.addData(13);
	list.getAllData();
	cout << endl;

	list.quick_sort();
	list.getAllData();
	return true;
}

bool fun_1_test()
{
	LineList list;
	for (int i = 0; i < 10; i++)
	{
		list.addData(i);
	}
	list.addData(12);
	list.addData(1, 11);
	list.addData(14);
	list.addData(13);
	list.addData(11);

	list.fun_1(2,8);
	list.getAllData();
	return true;
}

bool fun_2_test()
{
	LineList list;
	for (int i = 0; i < 10; i++)
	{
		list.addData(i);
	}
	list.addData(12);
	list.addData(1, 11);
	list.addData(14);
	list.addData(18);
	list.addData(11);

	list.quick_sort();

	list.fun_2(19);
	cout << endl;
	list.getAllData();

	return true;
}