#include "twoTree.h"

//œ»–Ú±È¿˙À„∑®
void twoTree::preOrderTraverse( twoTree * a)
{
	if (a != NULL)
	{
		cout << a->elem;
		a->preOrderTraverse(a->lchild);
		a->preOrderTraverse(a->rchild);
	}
	else
		return;
}

void twoTree::Assign(twoTree *a, int num)
{
	if (num == 1)
	{
		this->lchild = a;
	}
	else if(num == 2)
	{
		this->rchild = a;
	}
	else
	{
		exit(0);
	}
}

twoTree::twoTree(int a)
{
	this->elem = a;
}