#include"WorkerManager.h"
#include<iostream>
#include<string>
using namespace std;
#include"Boss.h"
#include"employee.h"
#include"Manager.h"
#include<fstream>

#define FILENAME "Empname.txt"

WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	//当文件不存在的时候
	if (!ifs.is_open())
	{
		//初始化职工
		this->Empnum = 0;
		//初始化指针
		this->Emparray = NULL;
		//初始化文件为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//当文件存在内容为空时
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//初始化职工
		this->Empnum = 0;
		//初始化指针
		this->Emparray = NULL;
		//初始化文件为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//当文件存在且不为空时
	this->FileIsEmpty = false;
	int num = Get_Empnum();
	this->Empnum = num;
	this->Emparray = new Worker * [num];
	//初始化职工
	this->init_Emp();
}

int WorkerManager::Get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string Name;
	int DID;

	int num = 0;
	while (ifs >> ID && ifs >> Name && ifs >> DID)
	{
		num++;
	}

	//关闭文件
	ifs.close();

	return num;
}

void WorkerManager::Show_Muse()
{
	cout << "******************************" << endl;
	cout << "   欢迎您使用职工管理系统       " << endl;
	cout << "                              " << endl;
	cout << "        1.添加职工             " << endl;
	cout << "        2.显示职工             " << endl;
	cout << "        3.删除职工             " << endl;
	cout << "        4.修改职工             " << endl;
	cout << "        5.查找职工             " << endl;
	cout << "        6.职工排序             " << endl;
	cout << "        7.系统重置             " << endl;
	cout << "        0.退出系统             " << endl;
	cout << "******************************" << endl;
}

void WorkerManager::SystemExit()
{
	cout << "欢迎下次使用本系统:>" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::AddEmp()
{
	int Addnum = 0;  //记录添加职工人数

	cout << "请输入添加职工人数" << endl;
	cin >> Addnum;

	if (Addnum > 0)
	{
		//记录添加后职工总人数
		int new_size = this->Empnum + Addnum;
		Worker** NewArray = new Worker*[new_size+3];

		if (this->Emparray != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				NewArray[i] = this->Emparray[i];
			}
		}

		//批量添加新职工
		for (int i = 0; i < Addnum; i++)
		{
			int ID;
			string name;
			int Dept;

			cout << "请输入第" << i + 1 << "位职工的编号:>" << endl;
			cin >> ID;

			cout << "请输入第" << i + 1 << "位职工的姓名:>" << endl;
			cin >> name;

			cout << "请选择第" << i + 1 << "位职工的岗位:>" << endl;
			cout << "1.员工" << "\t2.经理" << "\t3.老板" << endl;
			cin >> Dept;

			Worker* worker = NULL;
			switch (Dept)
			{
			case 1:
				worker = new employee(ID, name, Dept);
				break;
			case 2:
				worker = new Manager(ID, name, Dept);
				break;
			case 3:
				worker = new Boss(ID, name, Dept);
				break;
			default:
				cout << 111 << endl;
				break; 
			}
			
			//将新职工添加到程序中
			NewArray[this->Empnum + i] = worker;

		}

		//将原有数据销毁
		delete[] this->Emparray;

		//将新数据更新
		this->Emparray = NewArray;
		
		//将职工人数更新
		this->Empnum = new_size;

		cout << "成功添加" << Addnum << "位职工:>" << endl;

		this->FileIsEmpty = false;

	}
	else
	{
		cout << "输入错误:>" << endl;
	}

	system("pause");
	system("cls");
	this->save();
}

void WorkerManager::save()
{
	ofstream ofs;
	
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->Empnum; i++)
	{
		ofs << this->Emparray[i]->ID << "\t"
			<< this->Emparray[i]->Name << "\t"
			<< this->Emparray[i]->Dept_ID << endl;
	}

	ofs.close();
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string Name;
	int DID;

	int Indix = 0;
	while (ifs >> ID && ifs >> Name && ifs >> DID)
	{
		Worker* worker = NULL;

		if (DID == 1)
		{
			worker = new employee(ID, Name, DID);
		}

		if (DID == 2)
		{
			worker = new Manager(ID, Name, DID);
		}

		if (DID == 3)
		{
			worker = new Boss(ID, Name, DID);
		}

		this->Emparray[Indix] = worker;
		Indix++;
	}

	//关闭文件
	ifs.close();
}

void WorkerManager::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空:>" << endl;

		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请选择排序方式:>" << endl;
		cout << "1.按职工编号升序排列:>\t2.按职工编号降序排列:>" << endl;
		int Choice = 0;
		cin >> Choice;

		int MIN = 0;

		for (int i = 0; i < this->Empnum; i++)
		{
			MIN = i;

			for (int j = i + 1; j < this->Empnum; j++)
			{

				//升序
				if (Choice == 1)
				{
					if (this->Emparray[j]->ID < this->Emparray[MIN]->ID)
						MIN = j;
				}
				//降序
				else if (Choice == 2)
				{
					if (this->Emparray[j]->ID > this->Emparray[MIN]->ID)
						MIN = j;
				}
				else
				{
					cout << "选择错误:>" << endl;
					system("pause");
					system("cls");
					return;
				}

				//数据交换
				if (MIN != i)
				{
					Worker* temp = this->Emparray[i];
					this->Emparray[i] = this->Emparray[MIN];
					this->Emparray[MIN] = temp;
				}
			}
		}

		cout << "排序成功:>" << endl;

		//更新到文件中
		this->save();

		this->Show_Emp();

		return;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空:>";

		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->Empnum; i++)
	{
		this->Emparray[i]->ShowInFo();
	}

	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "请输入职工编号:>" << endl;
	int Choice = 0;
	cin >> Choice;
	
	if (this->IsExist(Choice) != -1)
	{
		int ret = this->IsExist(Choice);
		this->Emparray[ret]->ShowInFo();

		//二次确认 防止误操作
		cout << "确认删除？\n1.确定:>\t2.返回" << endl;
		int sio = 0;
		cin >> sio;

		if (sio == 1)
		{
			for (int i = ret; i < this->Empnum; i++)
			{
				this->Emparray[i] = this->Emparray[i + 1];
			}

			//更新职工人数
			this->Empnum--;

			//更新文件
			this->save();
		}
	}
	else
	{
		cout << "查无此人:>" << endl;
	}

	system("pause");
	system("cls");
	return;
}

void WorkerManager::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "请输入职工编号:>" << endl;
	int Choice = 0;
	cin >> Choice;

	if (this->IsExist(Choice) != -1)
	{
		int ret = this->IsExist(Choice);
		this->Emparray[ret]->ShowInFo();

		cout << "请输入新的职工编号:>" << endl;
		int NewId = 0;
		cin >> NewId;

		cout << "请输入新的职工姓名:>" << endl;
		string NewName;
		cin >> NewName;

		cout << "请输入新的职工岗位:>" << endl;
		cout << "1.普通员工:>\t2.经理:>\t3.老板:>" << endl;
		int NewDid = 0;
		cin >> NewDid;

		Worker* worker = NULL;
		if (NewDid == 1)
		{
			worker = new employee(NewId, NewName, NewDid);
		}
		if (NewDid == 2)
		{
			worker = new Manager(NewId, NewName, NewDid);
		}
		if (NewDid == 3)
		{
			worker = new Boss(NewId, NewName, NewDid);
		}

		//将职工信息更新到程序中
		this->Emparray[ret] = worker;

		//将职工信息更新到文件中
		this->save();
	}
	else
	{
		cout << "查无此人:>" << endl;
	}

	//按任意键清屏
	system("pause");
	system("cls");
	return;
}

void WorkerManager::FindEmp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "选择查找方式:>\n1.按职工编号查找:>\t2.按职工姓名查找:>" << endl;
	int Choice = 0;
	cin >> Choice;

	if (Choice == 1)
	{
		cout << "请输入职工编号:>" << endl;
		int ios = 0;
		cin >> ios;

		if (this->IsExist(ios) != -1)
		{
			int ret = this->IsExist(ios);
			this->Emparray[ret]->ShowInFo();
		}
		else
		{
			cout << "查无此人:>" << endl;
		}
	}

	else if (Choice == 2)
	{
		string name;
		cout << "请输入职工姓名:>" << endl;
		cin >> name;

		int num = 0;
		for (int i = 0; i < this->Empnum; i++)
		{
			if (this->Emparray[i]->Name == name)
			{
				this->Emparray[i]->ShowInFo();
				num++;
			}
		}

		if (num == 0)
		{
			cout << "查无此人:>" << endl;
		}
	}

	else
	{
		cout << "选择错误:>" << endl;
	}

	system("pause");
	system("cls");
	return;
}

void WorkerManager::Clean_File()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "您确定要重置系统吗:>" << endl
		<< "1.确定:>\t2.返回:>" << endl;
	int Choice = 0;
	cin >> Choice;

	if (Choice == 1)
	{
		//删除文件再次建立一个空文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//释放在堆区的内容
		for (int i = 0; i < this->Empnum; i++)
		{
			delete this->Emparray[i];
			this->Emparray[i] = NULL;
		}

		//释放数组指针
		delete this->Emparray;
		this->Emparray = NULL;
		this->Empnum = 0;
		this->FileIsEmpty = true;

		cout << "重置成功:>" << endl;
	}
	else if (Choice == 2)
	{	}
	else
	{
		cout << "选择错误:>" << endl;
	}

	system("pause");
	system("cls");

	return;
}

int WorkerManager::IsExist(int Choice)
{
	for (int i = 0; i < this->Empnum; i++)
	{
		if (this->Emparray[i]->ID == Choice)
			return i;
	}

	return -1;
}


WorkerManager::~WorkerManager()
{
	if (this->Emparray != NULL)
	{
		for(int i = 0; i < this->Empnum; i++)
			if (this->Emparray[i] != NULL)
			{
				delete this->Emparray[i];
				this->Emparray[i] = NULL;
			}

		delete[] this->Emparray;
		this->Emparray = NULL;
	}
}
