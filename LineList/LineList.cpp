#include "LineList.h"

LineList::LineList() :len(0),size(MAXSIZE)		//构造函数
{
	this->data = new ElemType[MAXSIZE];
}

LineList::~LineList()		//析构函数
{
	delete[] this->data;
	this->data = NULL;
}

bool LineList::getBiggerSpace()			//基本扩容函数的实现
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

int LineList::getLength()		//得到线性表长度的实现
{
	return this->len;
}

bool LineList::getAllData()		//得到全部数据的实现
{
	if (this->ListIsEmpty())
	{
		cout << "该线性表为空" << endl;
		return false;
	}
	for (int i = 0; i < len; i++)		//在此可尝试for(auto i: Type[] num)循环
	{
		cout << this->data[i] << " " << endl;
	}
	return true;
}

bool LineList::ListIsEmpty()		//判断线性表是否为空的实现
{
	if (this->len == 0)
		return true;
	return false;
}

bool LineList::DestroyList()		//销毁线性表的实现
{
	delete[] this->data;
	this->data = NULL;
	this->len = 0;
	return true;
}

ElemType LineList::getData(int palce)		//返回特定位置数据的实现
{
	if (palce > len + 1)
	{
		return (ElemType)-1;
	}
	return this->data[palce - 1];
}

int LineList::searchData(int num)		//查找数据的实现
{
	for (int i = 0; i < this->len; i++)		//在此可以优化一下，以减小时间复杂度.
	{
		if (num == this->data[i])
			return i;
	}
	return -1;
}

bool LineList::addData(int palce, ElemType value)		//在特定位置插入数据的实现
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

ElemType LineList::deleteData(int palce)		//删除数据的实现
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

int LineList::addData(ElemType value, bool _switch)		//头插法和尾插法的实现
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

bool LineList::deleteSomeoneData(int value, bool _switch)		//删除特定大小的全部元素的实现
{
	ElemType* _data = this->data;
	int num = 0;
	if (_switch == false)		//当开关关闭时，自动调用第一种算法
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
	if (_switch == false)		//解法一
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
	else			//解法二
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

bool LineList::fun_1(int left, int right)			//此题采用的思路和deleteSomeoneData算法相似,可以采用两种方式解决
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

int LineList::quick_sort_1(int left, int right)			//快速排序	平均时间复杂度为NlogN;
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
	if (right == -1)							//对right进行初始化,在第一次排序时right为len
		right = this->len - 1;					//这样设计,在数据量大时,会浪费很多的时间		
	if (left < right)							
	{
		i = this->quick_sort_1(left,right);
		this->quick_sort(left,i-1);
		this->quick_sort(i+1,right);
	}
	return true;
}

int LineList::fun_2(int value)			//采用二分查找法进行寻找   时间复杂度为O(logN)
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