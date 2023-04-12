#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//�궨����
#define MAXSIZE 100
//���ݱ�����
typedef int ElemType;

class LineList
{
private:
	//��������������Ϊ˽��Ȩ�ޣ������ų�Ա�����ܵ���
	ElemType* data;		//����,�Ƽ��������±�Ϊ��ĵط���Ϊ��ֵ������������ĳЩ�����Ĳ���
	int len;		//����
	int size;		//��ǰ��󳤶�

public:
	//���ǳ�Ա����������Ϊ����Ȩ��
	LineList();		//���캯����ʼ�����Ա�
	~LineList();
	
	bool getBiggerSpace();		//�������ݺ���

	//��������
	int getLength();		//������Ա���
	bool getAllData();		//��ӡȫ������
	bool ListIsEmpty();		//�ж����Ա��Ƿ�Ϊ��
	bool DestroyList();		//�������Ա�
	ElemType getData(int palce);		//������Ա��ض�λ������
	int searchData(int num);		//�������Ա����ض���ֵ��Ԫ�ز������±�
	bool addData(int palce, ElemType value);		//�����Ա���λ��palce����һ��Ԫ��		//���ʱ����ʹ�ú���������
	ElemType deleteData(int palce);		//ɾ�����Ա���λ��palce��Ԫ��

	//���⺯��
	int addData(ElemType, bool _switch = false);		//ͷ�巨��β�巨��β�巨����ʱboolֵ,Ĭ�ϵ���ͷ�巨,�÷����ͻ����������أ�����ֵΪ���Ԫ��λ�õ��±�

	//�㷨
	bool deleteSomeoneData(int value, bool _switch = false);		//ɾ���ñ������ݴ�СΪx����������Ԫ��,����������ʵ�ַ�ʽ
	bool partitionl(bool _switch = false);		//�Ե�һ��Ԫ��Ϊ��׼Ԫ�أ������ڻ�׼Ԫ�ص������ڻ�׼Ԫ��֮�󣬽�С�ڻ�׼Ԫ�ص�Ԫ�����ڻ�׼Ԫ��֮ǰ��
	int quick_sort_1(int left = 0, int right = -1);		
	bool quick_sort(int left = 0, int right = -1);//��������


	//��ҵ��
	bool fun_1(int left, int right);			//ɾ���������ݴ�С������(left,right)�е�Ԫ��
	int fun_2(int value);					//�������������ҵ����ʵ�λ�ò�����value,���ö��ֲ��ҷ�.
};

