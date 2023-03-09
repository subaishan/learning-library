//ʵ�飺��ͬ���㷨ʱ��Ч���ϵĲ���
#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

long add1(long n)
{
	long sum = 0;
	for (long i = 1; i <= n; i++)  //ѭ���㷨
	{
		sum += i;
	}
	return sum;
}

void add1_time(long n)
{
	clock_t t; // ��������ʱ����������
	long sum = 0;
	t = clock();   // clock() ���ص�������cpuʱ�Ӽ�ʱ��λ��
	sum = add1(n);
	t = clock() - t;
	cout << "����һ:\n���:" << sum << endl;
	cout << ((float)t / CLOCKS_PER_SEC) << "\n" << endl;   // CLOCKS_PER_SEC��ָ1������ĺ�����
}

long add2(long n)  //��˹�㷨
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
	cout << "������:\n���:" << sum << endl;
	cout << ((float)t / CLOCKS_PER_SEC) << "\n" << endl;
}

int main()
{
	cout << "������һ��100000���ϵ���" << endl;
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