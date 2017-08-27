#include<iostream>
using namespace std;
#include<assert.h>

#define DataType int

class Seqlist 
{
	friend ostream& operator<<(ostream &_cout,const Seqlist& s);
public:
	Seqlist();
	Seqlist(DataType arr[],size_t size); 
	Seqlist(const Seqlist& s);
	Seqlist& operator=(const Seqlist& s);
	//Seqlist& operator=(Seqlist s);
	~Seqlist();
	
	void PushBack(const DataType& data);
	void PopBack();
	void Insert(size_t pos,const DataType& data);
	void Erase(size_t pos);
	int Find(const DataType& data)const;
	size_t Size()const;
	size_t Capacity()const;
	DataType& Front();
	DataType& Front()const;
	DataType& Back();
	const DataType& Back()const;
	const DataType& operator[](size_t index)const;
	void Clear();
	bool Empty();
	void Resize(size_t size,const DataType& data = 0);

private:
	void CheckCapacity()
	{
		if(_size >= _capacity)
		{
			DataType *newspace = new DataType[2*_capacity];
			size_t i = 0;
			for(i=0; i<_size; i++)
			{
				newspace[i] = _pData[i];
			}

			delete []_pData;
			_pData = NULL;
			_pData = newspace;
			_capacity *= 2;
		}
	}
private:
	size_t _size;
	size_t _capacity;
	DataType* _pData;
};

ostream& operator<<(ostream &_cout,const Seqlist& s)
{
	size_t i = 0;
	for(i=0; i<s._size; i++)
	{
		_cout<<s._pData[i]<<"->";
	}
	_cout<<"end";

	return _cout;
}

//普通版构造函数
Seqlist::Seqlist()
	:_size(0)
	,_capacity(3)
	,_pData(new DataType[_capacity])
{}
//数组版构造函数
Seqlist::Seqlist(DataType arr[],size_t size)
	:_size(size)
	,_capacity(size)
	,_pData(new DataType[size])
{
	////方式1:
	//memcpy(_pData,arr,size*sizeof(DataType));
	
	//方式二:
	size_t i = 0;
	for(i=0; i<size; i++)
	{
		_pData[i] = arr[i];
	}
}
//普通版本的拷贝构造函数
Seqlist::Seqlist(const Seqlist& s)
	:_pData(new DataType[s._capacity])
	,_capacity(s._capacity)
	,_size(s._size)
{
	size_t i = 0;
	for(i=0; i<_size; i++)
	{
		_pData[i] = s._pData[i];
	}
}
////简洁版的拷贝构造函数
//Seqlist::Seqlist(const Seqlist& s)
//	:_pData(NULL)
//	,_size(0)
//	,_capacity(0)
//{
//	Seqlist temp(s._pData,_capacity);
//	temp._size = s._size;
//	swap(*this,temp);
//}
//普通版的赋值运算符重载
Seqlist& Seqlist::operator=(const Seqlist& s)
{
	if(this != &s)
	{
		DataType* temp = _pData;//保存原地址
		_pData = new DataType[s._capacity];
		_size = s._size;
		_capacity = s._capacity;
		delete []temp;
		size_t i = 0;
		for(i=0; i<s._size; i++)
		{
			_pData[i] = s._pData[i];
		}
	}
	
    return *this;
}
//简洁版的赋值运算符重载
//Seqlist& Seqlist::operator=(Seqlist s)
//{
//	swap(*this,s);
//	return *this;
//}
Seqlist::~Seqlist()
{
	if(NULL != _pData)
	{
		delete []_pData;
		_pData = NULL;
		_capacity = 0;
		_size = 0;
	}
}

void Seqlist::PushBack(const DataType& data)
{
	assert(_pData);
	CheckCapacity();
	_pData[_size] = data;
	_size++;
}
void Seqlist::PopBack()
{
	assert(_pData);
	if(Empty())
	{
		assert(false);
		return;
	}
	_size--;
}
void Seqlist::Insert(size_t pos,const DataType& data)//在pos之后插入数据data
{
	assert(pos>=0 && pos<_size);
	CheckCapacity();
	size_t i = 0;
	for(i=_size; i>pos; i--)
	{
		_pData[i] = _pData[i-1];
	}
	_pData[pos] = data;
	_size++;
}
void Seqlist::Erase(size_t pos)
{
	assert((pos>=0) && (pos<_size));
	if(_size == 0)
		return;
	else
	{
		size_t i = 0;
		for(i=pos; i<_size-1; i++)
		{
			_pData[i] = _pData[i+1];
		}
		_size--;
	}
}
int Seqlist::Find(const DataType& data)const
{
	size_t i = 0;
	for(i=0; i<_size; i++)
	{
		if(_pData[i] == data)
			return i;
	}
	return -1;
}
size_t Seqlist::Size()const
{
	return _size;
}
size_t Seqlist::Capacity()const
{
	return _capacity;
}
DataType& Seqlist::Front()
{
	assert(_size > 0);
	return _pData[0];
}
DataType& Seqlist::Front()const
{
	assert(_size > 0);
	return _pData[0];
}
DataType& Seqlist::Back()
{
	assert(_size > 0);
	return _pData[_size-1];
}
const DataType& Seqlist::Back()const
{
	assert(_size > 0);
	return _pData[_size-1];
}
const DataType& Seqlist::operator[](size_t index)const
{
	return _pData[index];
}
void Seqlist::Clear()
{
	if(NULL != _pData)
	{
		delete []_pData;
		_size = 0;
		_capacity = 0;
	}
}
bool Seqlist::Empty()
{
	return _size==0;
}
void Seqlist::Resize(size_t size,const DataType& data)
{
	if(size > _size)
	{
		size_t temp = _size;
		_size = size;
		CheckCapacity();
		size_t i = 0;
		for(i=temp; i<size; i++)
		{
			_pData[i] = data;
		}
	}
	if(size > _size)
	{
		_size = size;
	}
}

void Funtest()
{
	int arr[5] = {0};
	Seqlist s1;
	Seqlist s2(arr,5);
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout<<s1<<endl;
	s1.PopBack();
	cout<<s1<<endl;
	s1.Insert(1,5);
	cout<<s1<<endl;
	s1.Erase(1);
	cout<<s1<<endl;
	int ret = s1.Find(2);
	if(ret == -1)
	cout<<"未找到元素"<<endl;
	else
	cout<<ret<<endl;
	ret = s1.Size();
	cout<<ret<<endl;
	ret = s1.Capacity();
	cout<<ret<<endl;
	ret = s1.Back();
	cout<<ret<<endl;
	ret = s1.Front();
	cout<<ret<<endl;
	bool r = s1.Empty();
	cout<<r<<endl;
	s1.Resize(7,6);
	cout<<s1<<endl;
	s1.Resize(2);
	cout<<s1<<endl;
	s2 = s1;
	cout<<s2<<endl;
}

int main()
{
	Funtest();
	system("pause");
	return 0;
}
