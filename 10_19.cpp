#include<iostream>
using namespace std;

//void FunTest1()
//{
//	int *p = new int[10];
//	FILE* pFile = fopen( "1.txt", "r" );//已读的方式打开"1.txt"文件
//	if (pFile == NULL)//如果打开失败，则返回
//	{
//		return;//error:如果打开失败，则造成内存泄漏
//	}
//	// DoSomethint();
//	if (p != NULL)
//	{
//		delete[] p;
//		p = NULL;
//	}
//}
//void FunTest2()
//{
//	int *p = new int[10];
//	try
//	{
//		//DoSomething();
//	}
//	catch (...)
//	{
//		return;//返回之前忘记释放内存，导致内存泄漏
//	}
//	delete[] p;
//}


//template <typename T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ap)
//		:_p(ap)
//	{
//		ap = NULL;//让ap与动态申请的空间脱离关系
//		cout<<"AutoPtr()"<<endl;
//	}
//	~AutoPtr()
//	{
//		if(NULL != _p)
//		{
//			cout<<"~AutoPtr()"<<endl;
//			delete _p;
//			_p = NULL;
//		}
//	}
//private:
//	T* _p;
//};
//void Funtest()
//{
//	AutoPtr<int> p = new int;
//	AutoPtr<int> p1(p);
//}
//int main()
//{
//	Funtest();
//	system("pause");
//	return 0;
//}

template <typename T>
class AutoPtr
{
public:
	AutoPtr(T* ap = NULL)
		:_p(ap)
	{
		cout<<"AutoPtr()"<<endl;
	}

	AutoPtr(AutoPtr<T>& ap)//由于内部要改变ap的值，所以去掉const修饰
		:_p(ap._p)
	{
		ap._p = NULL;//让ap与动态申请的空间脱离关系
	}

	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if(this != &ap)
		{
			if(NULL != _p)//防止对空对象进行引用导致程序崩溃
			{
				delete _p;
				_p = ap._p;//如果_p为空，则崩溃
				ap._p = NULL;//脱离关系
			}
		}
		return *this;
	}

	~AutoPtr()
	{
		if(NULL != _p)
		{
		    cout<<"~AutoPtr()"<<endl;
			delete _p;
			_p = NULL;
		}
	}
private:
	T* _p;
};
void Funtest()
{
	AutoPtr<int> p = new int;
	AutoPtr<int> p1(p);
	AutoPtr<int> p2;
	p2 = p1;
	AutoPtr<int> p3 = new int;
}
int main()
{
	Funtest();
	system("pause");
	return 0;
}

