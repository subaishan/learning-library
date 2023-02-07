#include "Mylist.h"

//ͷ�巨
void Mylist::heard_getelem()
{
	this->next = new Mylist;
	cin >> this->next->stu._name;
	cin >> this->next->stu._age;
	cin >> this->next->stu._ID;
	cin >> this->next->stu.fraction;

	return;
}

void Mylist::print()
{
	mylist p = this->next;
	cout << p->stu._name << " " << p->stu._age << " " << p->stu._ID
		<< " " << p->stu.fraction << endl;
	return;
}