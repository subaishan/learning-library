//常见算法时间函数的增长趋势分析
#include<iostream>
#include<cmath>

using namespace std;

double log2(double n)
{
	return log10(n) / log10(2);
}

long exponent(int n)
{
	long s = 1;
	for (int i = 0; i < n; i++)
	{
		s *= 2;
	}
	return s;
}

long factorial(int n)
{
	long s = 1;
	for (int i = 1; i <= n; i++)
	{
		s *= i;
	}
	return s;
}

void fun(int n)
{
	cout << "log2(n)   sqrt(n)   n   nlog2(n)   n^2   n^3   2^n    n!\n" << endl;
	cout << "============================================================" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << log2(i) << "\t" << sqrt(i) << "\t" << i << "\t" << i * log2(i) << "\t" << i* i << "\t"
			<< i * i * i << "\t" << exponent(i) << "\t" << factorial(i) << endl;
	}
	return;
}

int main()
{
	int n = 10;
	fun(n);
	return 0;
}