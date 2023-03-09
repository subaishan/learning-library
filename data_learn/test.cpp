//实验：不同的算法时间效率上的差异
#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

long add1(long n)
{
	long sum = 0;
	for (long i = 1; i <= n; i++)  //循环算法
	{
		sum += i;
	}
	return sum;
}

void add1_time(long n)
{
	clock_t t; // 该类型是时钟数据类型
	long sum = 0;
	t = clock();   // clock() 返回的类型是cpu时钟计时单位数
	sum = add1(n);
	t = clock() - t;
	cout << "方法一:\n结果:" << sum << endl;
	cout << ((float)t / CLOCKS_PER_SEC) << "\n" << endl;   // CLOCKS_PER_SEC是指1秒包含的毫秒数
}

long add2(long n)  //高斯算法
{
	long sum = n * (n + 1) / 2;
	return sum;
}

void add2_time(long n)
{
	clock_t t;
	long sum = 0;
	t = clock();
	sum = add2(n);
	t = clock() - t;
	cout << "方法二:\n结果:" << sum << endl;
	cout << ((float)t / CLOCKS_PER_SEC) << "\n" << endl;
}

int main()
{
	cout << "请输入一个100000以上的数" << endl;
	long value = 0;
	cin >> value;
	if (value > 100000)
	{
		add1_time(value);
		add2_time(value);
	}
	else return 0;
	return 0;
}