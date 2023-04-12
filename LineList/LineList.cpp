#include "LineList.h"

LineList::LineList() :len(0),size(MAXSIZE)		//���캯��
{
	this->data = new ElemType[MAXSIZE];
}

LineList::~LineList()		//��������
{
	delete[] this->data;
	this->data = NULL;
}

bool LineList::getBiggerSpace()			//�������ݺ�����ʵ��
{
	ElemType* _data = new ElemType[size + MAXSIZE];
	for (int i = 0; i < this->len; i++)
	{
		_data[i] = this->data[i];
	}
	delete[] this->data;
	this->data = _data;
	return true;
}

int LineList::getLength()		//�õ����Ա��ȵ�ʵ��
{
	return this->len;
}

bool LineList::getAllData()		//�õ�ȫ�����ݵ�ʵ��
{
	if (this->ListIsEmpty())
	{
		cout << "�����Ա�Ϊ��" << endl;
		return false;
	}
	for (int i = 0; i < len; i++)		//�ڴ˿ɳ���for(auto i: Type[] num)ѭ��
	{
		cout << this->data[i] << " " << endl;
	}
	return true;
}

bool LineList::ListIsEmpty()		//�ж����Ա��Ƿ�Ϊ�յ�ʵ��
{
	if (this->len == 0)
		return true;
	return false;
}

bool LineList::DestroyList()		//�������Ա��ʵ��
{
	delete[] this->data;
	this->data = NULL;
	this->len = 0;
	return true;
}

ElemType LineList::getData(int palce)		//�����ض�λ�����ݵ�ʵ��
{
	if (palce > len + 1)
	{
		return (ElemType)-1;
	}
	return this->data[palce - 1];
}

int LineList::searchData(int num)		//�������ݵ�ʵ��
{
	for (int i = 0; i < this->len; i++)		//�ڴ˿����Ż�һ�£��Լ�Сʱ�临�Ӷ�.
	{
		if (num == this->data[i])
			return i;
	}
	return -1;
}

bool LineList::addData(int palce, ElemType value)		//���ض�λ�ò������ݵ�ʵ��
{
	if (this->len >= this->size)
		this->getBiggerSpace();
	if (palce < 1 || palce > this->size)
		return false;
	for (int i = len-1; i >= palce - 1; i--)
	{
		data[i + 1] = data[i];
	}
	data[palce - 1] = value;
	this->len++;
	return true;
}

ElemType LineList::deleteData(int palce)		//ɾ�����ݵ�ʵ��
{
	if (this->ListIsEmpty())
		return (ElemType)-1;
	if (palce < 1 || palce > this->size)
		return (ElemType)-1;
	ElemType value = this->data[palce - 1];
	for (int i = palce - 1; i < this->len - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->len--;
	return value;
}

int LineList::addData(ElemType value, bool _switch)		//ͷ�巨��β�巨��ʵ��
{
	if (this->len >= this->size)
		this->getBiggerSpace();
	if (_switch == false)
	{
		this->data[len] = value;
		len++;
		return len - 1;
	}
	else
	{
		this->addData(1,value);
	}
}

bool LineList::deleteSomeoneData(int value, bool _switch)		//ɾ���ض���С��ȫ��Ԫ�ص�ʵ��
{
	ElemType* _data = this->data;
	int num = 0;
	if (_switch == false)		//�����عر�ʱ���Զ����õ�һ���㷨
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->data[i] != value)
			{
				_data[num] = this->data[i];
				num++;
			}
		}
		this->len = num;
	}
	else
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->data[i] == value)
				num++;
			this->data[i] = this->data[i + num];
		}
		this->len -= num;
	}
	return true;
}

bool LineList::partitionl(bool _switch)
{
	if (this->ListIsEmpty())
		return false;
	int left = 0;
	int right = this->len - 1;
	if (_switch == false)		//�ⷨһ
	{
		ElemType _data = this->data[0];
		while (left < right)
		{
			while (left < right && this->data[right] > _data)
				right--;
			while (left < right && this->data[left] <= _data)
				left++;
			if (left < right)
				swap(this->data[left], this->data[right]);
		}
		swap(this->data[left], this->data[0]);
		return true;
	}
	else			//�ⷨ��
	{
		ElemType _data = this->data[left];
		while (left < right)
		{
			while (left < right && this->data[right] > this->data[0])
				right--;
			this->data[left] = this->data[right];
			while (left < right && this->data[left] <= this->data[0])
				left++;
			this->data[right] = this->data[left];
		}
		this->data[left] = _data;
		return true;
	}
}

bool LineList::fun_1(int left, int right)			//������õ�˼·��deleteSomeoneData�㷨����,���Բ������ַ�ʽ���
{
	if (this->ListIsEmpty() || left <= 0 || right > this->len)
		return false;
	int num = 0;
	ElemType* _data = this->data;
	for (int i = 0; i < this->len; i++)
	{
		if (this->data[i] <left || this->data[i] > right)
		{
			_data[num] = this->data[i];
			num++;
		}
	}
	this->len = num;
	return true;
}

int LineList::quick_sort_1(int left, int right)			//��������	ƽ��ʱ�临�Ӷ�ΪNlogN;
{
	if (this->ListIsEmpty())
		return false;			
	ElemType s = this->data[left];
	while (left < right)
	{
		while (left < right && this->data[right] > s)
			right--;
		this->data[left] = this->data[right];
		while (left < right && this->data[left] <= s)
			left++;
		this->data[right] = this->data[left];
	}
	this->data[left] = s;
	//this->getAllData();
	//cout << endl;
	return left;
}

bool LineList::quick_sort(int left, int right)
{
	int i;
	if (right == -1)							//��right���г�ʼ��,�ڵ�һ������ʱrightΪlen
		right = this->len - 1;					//�������,����������ʱ,���˷Ѻܶ��ʱ��		
	if (left < right)							
	{
		i = this->quick_sort_1(left,right);
		this->quick_sort(left,i-1);
		this->quick_sort(i+1,right);
	}
	return true;
}

int LineList::fun_2(int value)			//���ö��ֲ��ҷ�����Ѱ��   ʱ�临�Ӷ�ΪO(logN)
{
	if (this->ListIsEmpty())
		return -1;
	int left = 0, right = this->len - 1;
	int num = 1;
	while (left < right)
	{
		num = (left + right) / 2;
		if (this->data[num] == value) 
		{
			this->addData(num + 1, value);
			return num + 1;
		}
		else if (this->data[num] > value) right = num - 1;
		else if (this->data[num] < value) left = num + 1;
	}
	if (num == 0)
	{
		this->addData(0, value);
		return 0;
	}
	else if (this->data[num] > value)
	{
		this->addData(num+1, value);
		return num;
	}
	else if (this->data[num] < value)
	{
		this->addData(num + 3, value);
		return num + 2;
	}
}