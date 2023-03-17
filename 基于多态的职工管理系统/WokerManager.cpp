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

	//���ļ������ڵ�ʱ��
	if (!ifs.is_open())
	{
		//��ʼ��ְ��
		this->Empnum = 0;
		//��ʼ��ָ��
		this->Emparray = NULL;
		//��ʼ���ļ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//���ļ���������Ϊ��ʱ
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//��ʼ��ְ��
		this->Empnum = 0;
		//��ʼ��ָ��
		this->Emparray = NULL;
		//��ʼ���ļ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//���ļ������Ҳ�Ϊ��ʱ
	this->FileIsEmpty = false;
	int num = Get_Empnum();
	this->Empnum = num;
	this->Emparray = new Worker * [num];
	//��ʼ��ְ��
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

	//�ر��ļ�
	ifs.close();

	return num;
}

void WorkerManager::Show_Muse()
{
	cout << "******************************" << endl;
	cout << "   ��ӭ��ʹ��ְ������ϵͳ       " << endl;
	cout << "                              " << endl;
	cout << "        1.���ְ��             " << endl;
	cout << "        2.��ʾְ��             " << endl;
	cout << "        3.ɾ��ְ��             " << endl;
	cout << "        4.�޸�ְ��             " << endl;
	cout << "        5.����ְ��             " << endl;
	cout << "        6.ְ������             " << endl;
	cout << "        7.ϵͳ����             " << endl;
	cout << "        0.�˳�ϵͳ             " << endl;
	cout << "******************************" << endl;
}

void WorkerManager::SystemExit()
{
	cout << "��ӭ�´�ʹ�ñ�ϵͳ:>" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::AddEmp()
{
	int Addnum = 0;  //��¼���ְ������

	cout << "���������ְ������" << endl;
	cin >> Addnum;

	if (Addnum > 0)
	{
		//��¼��Ӻ�ְ��������
		int new_size = this->Empnum + Addnum;
		Worker** NewArray = new Worker*[new_size+3];

		if (this->Emparray != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				NewArray[i] = this->Emparray[i];
			}
		}

		//���������ְ��
		for (int i = 0; i < Addnum; i++)
		{
			int ID;
			string name;
			int Dept;

			cout << "�������" << i + 1 << "λְ���ı��:>" << endl;
			cin >> ID;

			cout << "�������" << i + 1 << "λְ��������:>" << endl;
			cin >> name;

			cout << "��ѡ���" << i + 1 << "λְ���ĸ�λ:>" << endl;
			cout << "1.Ա��" << "\t2.����" << "\t3.�ϰ�" << endl;
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
			
			//����ְ����ӵ�������
			NewArray[this->Empnum + i] = worker;

		}

		//��ԭ����������
		delete[] this->Emparray;

		//�������ݸ���
		this->Emparray = NewArray;
		
		//��ְ����������
		this->Empnum = new_size;

		cout << "�ɹ����" << Addnum << "λְ��:>" << endl;

		this->FileIsEmpty = false;

	}
	else
	{
		cout << "�������:>" << endl;
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

	//�ر��ļ�
	ifs.close();
}

void WorkerManager::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��:>" << endl;

		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��ѡ������ʽ:>" << endl;
		cout << "1.��ְ�������������:>\t2.��ְ����Ž�������:>" << endl;
		int Choice = 0;
		cin >> Choice;

		int MIN = 0;

		for (int i = 0; i < this->Empnum; i++)
		{
			MIN = i;

			for (int j = i + 1; j < this->Empnum; j++)
			{

				//����
				if (Choice == 1)
				{
					if (this->Emparray[j]->ID < this->Emparray[MIN]->ID)
						MIN = j;
				}
				//����
				else if (Choice == 2)
				{
					if (this->Emparray[j]->ID > this->Emparray[MIN]->ID)
						MIN = j;
				}
				else
				{
					cout << "ѡ�����:>" << endl;
					system("pause");
					system("cls");
					return;
				}

				//���ݽ���
				if (MIN != i)
				{
					Worker* temp = this->Emparray[i];
					this->Emparray[i] = this->Emparray[MIN];
					this->Emparray[MIN] = temp;
				}
			}
		}

		cout << "����ɹ�:>" << endl;

		//���µ��ļ���
		this->save();

		this->Show_Emp();

		return;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��:>";

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
		cout << "�ļ������ڻ��¼Ϊ��:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "������ְ�����:>" << endl;
	int Choice = 0;
	cin >> Choice;
	
	if (this->IsExist(Choice) != -1)
	{
		int ret = this->IsExist(Choice);
		this->Emparray[ret]->ShowInFo();

		//����ȷ�� ��ֹ�����
		cout << "ȷ��ɾ����\n1.ȷ��:>\t2.����" << endl;
		int sio = 0;
		cin >> sio;

		if (sio == 1)
		{
			for (int i = ret; i < this->Empnum; i++)
			{
				this->Emparray[i] = this->Emparray[i + 1];
			}

			//����ְ������
			this->Empnum--;

			//�����ļ�
			this->save();
		}
	}
	else
	{
		cout << "���޴���:>" << endl;
	}

	system("pause");
	system("cls");
	return;
}

void WorkerManager::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "������ְ�����:>" << endl;
	int Choice = 0;
	cin >> Choice;

	if (this->IsExist(Choice) != -1)
	{
		int ret = this->IsExist(Choice);
		this->Emparray[ret]->ShowInFo();

		cout << "�������µ�ְ�����:>" << endl;
		int NewId = 0;
		cin >> NewId;

		cout << "�������µ�ְ������:>" << endl;
		string NewName;
		cin >> NewName;

		cout << "�������µ�ְ����λ:>" << endl;
		cout << "1.��ͨԱ��:>\t2.����:>\t3.�ϰ�:>" << endl;
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

		//��ְ����Ϣ���µ�������
		this->Emparray[ret] = worker;

		//��ְ����Ϣ���µ��ļ���
		this->save();
	}
	else
	{
		cout << "���޴���:>" << endl;
	}

	//�����������
	system("pause");
	system("cls");
	return;
}

void WorkerManager::FindEmp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "ѡ����ҷ�ʽ:>\n1.��ְ����Ų���:>\t2.��ְ����������:>" << endl;
	int Choice = 0;
	cin >> Choice;

	if (Choice == 1)
	{
		cout << "������ְ�����:>" << endl;
		int ios = 0;
		cin >> ios;

		if (this->IsExist(ios) != -1)
		{
			int ret = this->IsExist(ios);
			this->Emparray[ret]->ShowInFo();
		}
		else
		{
			cout << "���޴���:>" << endl;
		}
	}

	else if (Choice == 2)
	{
		string name;
		cout << "������ְ������:>" << endl;
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
			cout << "���޴���:>" << endl;
		}
	}

	else
	{
		cout << "ѡ�����:>" << endl;
	}

	system("pause");
	system("cls");
	return;
}

void WorkerManager::Clean_File()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��:>" << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "��ȷ��Ҫ����ϵͳ��:>" << endl
		<< "1.ȷ��:>\t2.����:>" << endl;
	int Choice = 0;
	cin >> Choice;

	if (Choice == 1)
	{
		//ɾ���ļ��ٴν���һ�����ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//�ͷ��ڶ���������
		for (int i = 0; i < this->Empnum; i++)
		{
			delete this->Emparray[i];
			this->Emparray[i] = NULL;
		}

		//�ͷ�����ָ��
		delete this->Emparray;
		this->Emparray = NULL;
		this->Empnum = 0;
		this->FileIsEmpty = true;

		cout << "���óɹ�:>" << endl;
	}
	else if (Choice == 2)
	{	}
	else
	{
		cout << "ѡ�����:>" << endl;
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
