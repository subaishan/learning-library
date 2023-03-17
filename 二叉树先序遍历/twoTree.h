#pragma once
#include<iostream>
#include<string>
using namespace std;

class twoTree
{
public:
	twoTree(int);

	int elem;

	twoTree* lchild = NULL;
	twoTree* rchild = NULL;

	void preOrderTraverse(twoTree * a);

	void Assign(twoTree * , int);
};

