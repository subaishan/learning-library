#pragma once    //��ֹͷ�ļ��ظ�����
#include<iostream>     //��׼���������
using namespace std;   //�����ռ�
#include"Worker.h"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	
	//չʾ�˵�
	void Show_Muse();

	//ְ������
	int Empnum;

	//ְ������
	Worker** Emparray;

	//����ְ��
	void AddEmp();

	//�ļ��ӿ�
	void save();

	//�ж��ļ��Ƿ����
	bool FileIsEmpty;

	//ͳ���ļ���ְ������
	int Get_Empnum();

	//��ʼ��ְ��
	void init_Emp();

	//ְ����Ϣչʾ�ӿ�
	void Show_Emp();

	//ɾ��ְ���ӿ�
	void Del_Emp();

	//�ж�ְ���Ƿ���ڲ�����һ��ֵ
	int IsExist(int Choice);

	//����ְ���ӿ�
	void FindEmp();

	//�޸�ְ���ӿ�
	void Mod_Emp();

	//ְ������ӿ�
	void Sort_Emp();

	//ɾ��ȫ��ְ���ӿ�
	void Clean_File();

	//�˳�ϵͳ�ӿ�
	void SystemExit();

	//��������
	~WorkerManager();
};