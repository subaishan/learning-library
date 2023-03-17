#include<iostream>
using namespace std;
#include"twoTree.h"

void test01()
{
	twoTree a(1);
	twoTree b(2);
	twoTree c(3);

	a.Assign(&b,1);
	a.Assign(&c,2);

	a.preOrderTraverse(&a);
}

int main()
{
	test01();

	return 0;
}