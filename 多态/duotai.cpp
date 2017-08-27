#include <iostream>
using namespace std;

//class B
//{};
//class C1:public B
//{};
//class C2:public B
//{};
//int main()
//{
//	C1 *pc1 = new C1;
//	B *pd1 = pc1;
//	C2 *pc2 = new C2;
//	pd1 = pc2;
//
//	return 0;
//}


//class Base
//{
//public:
//	Base(int x,int y)//构造函数
//	{
//		a = x;
//		b = y;
//	}
//	virtual void show()//虚函数
//	{
//		cout<<"Base::"<<a<<" "<<b<<endl;
//	}
//private:
//	int a;
//	int b;
//};
//
//class Derived:public Base
//{
//public:
//	Derived(int x,int y,int z):Base(x,y)//派生类的构造函数（为基类构造函数传参）
//	{
//		c = z;
//	}
//	void show()//重新定义虚函数show
//	{
//		cout<<"Derived::"<<c<<endl;
//	}
//private:
//	int c;
//};
//
//int main()
//{
//	Base b(60,60);//创建基类对象b
//	Base *pb;//创建基指针类pb
//	Derived d(10,20,30);//创建派生类对象d
//
//	pb = &b;//对象指针指向基类对象b
//	pb->show();//调用基类的虚函数show()
//	pb = &d;//对象指针指向派生类对象d
//	pb->show();//调用派生类的虚函数show()
//
//	system("pause");
//	return 0;
//}



////函数重载
//int add(int x,int y)
//{
//	return x+y;
//}
//double add(float a,float b)
//{
//	return a+b;
//}
//int main()
//{
//	int a = 3,b = 5;
//	float x = 3.14f,y = 6.8f;
//	int ret1 = add(a,b);
//	cout<<"int----"<<ret1<<endl;
//	double ret2 = add(x,y);
//	cout<<"double----"<<ret2<<endl;
//	system("pause");
//	return 0;
//}


////重写
//class Base
//{
//public:
//	virtual void show(int x,int y)//虚函数
//	{
//		a = x;
//		b = y;
//		cout<<"Base::"<<a<<" "<<b<<endl;
//	}
//private:
//	int a;
//	int b;
//};
//
//class Derived:public Base
//{
//public:
//	void show(int x,int y)//重新定义虚函数show
//	{
//		c = x + y;
//		cout<<"Derived::"<<c<<endl;
//	}
//private:
//	int c;
//};
//
//int main()
//{
//	Base b;//创建基类对象b
//	Derived d;//创建派生类对象d
//	
//    b.show(10,20);
//	d.Derived::show(30,40);
//	system("pause");
//	return 0;
//}


////同名隐藏
//class Base
//{
//public:
//	int show()
//	{
//		cout<<"Base::show()"<<endl;
//		return 0;
//	}
//};
//
//class Derived:public Base
//{
//public:
//	void show()
//	{
//		cout<<"Derived::show()"<<endl;
//	}
//};
//
//int main()
//{
//	Derived d;//创建派生类对象d
//
//	d.show();//调用派生类自己的同名函数
//	d.Base::show();//调用基类的同名函数
//	system("pause");
//	return 0;
//}


////重写（协变）
//class Base
//{
//public:
//	virtual Base& fun(int x,int y)//虚函数
//	{
//		a = x;
//		b = y;
//		cout<<"Base::"<<a<<" "<<b<<endl;
//		return *this;
//	}
//private:
//	int a;
//	int b;
//};
//
//class Derived:public Base
//{
//public:
//	Derived& fun(int x,int y)//重新定义虚函数show
//	{
//		c = x + y;
//		cout<<"Derived::"<<c<<endl;
//		return *this;
//	}
//private:
//	int c;
//};
//
//int main()
//{
//	Base b;//创建基类对象b
//	Derived d;//创建派生类对象d
//	
//    b.fun(10,20);
//	d.Derived::fun(30,40);
//	system("pause");
//	return 0;
//}



//class Circle//基类
//{
//public:
//	void setr(int x)
//	{
//		r = x;
//	}
//	virtual void show() = 0;//定义纯虚函数
//protected:
//	int r;
//};
//class Area:public Circle//派生类
//{
//public:
//	void show()//重新定义虚函数show求圆形面积
//	{
//		cout<<"Area is "<<3.14*r*r<<endl;
//	}
//};
//int main()
//{
//	Circle* p;//基类指针
//	Area a;//派生类对象a
//    a.setr(5);
//	p = &a;
//	p->show();//计算圆形面积
//
//	system("pause");
//    return 0;
//}



//class CTest
//{
//public:
//	CTest(){iTest = 10;}
//	/*virtual */~CTest(){};
//private:
//	int iTest;
//};
//int main()
//{
//	CTest t;
//	cout<<sizeof(t)<<endl;
//	system("pause");
//	return 0;
//}


//class B
//{
//public:
//	B()
//	{
//		cout<<"B()"<<endl;
//	}	
//	virtual void show()//定义虚函数
//	{
//		cout<<"B::show()"<<endl;
//	}
//};
//class D:public B
//{
//public:
//	virtual void show()
//	{
//		cout<<"D::show()"<<endl;
//	}
//};
//
//int main()
//{
//	D d;
//	d.show();
//	system("pause");
//	return 0;
//}



//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"B::Funtest2"<<endl;
//	}
//	virtual void Funtest3()
//	{
//		cout<<"B::Funtest3"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"B::Funtest4"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//	B b;
//	Vpf* fun = (Vpf*)*(int*)&b;
//
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}


////没有覆盖且派生类没有新添加虚函数
//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"B::Funtest2"<<endl;
//	}
//	virtual void Funtest3()
//	{
//		cout<<"B::Funtest3"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"B::Funtest4"<<endl;
//	}
//};
//
//class D:public B
//{};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}



////没有覆盖且派生类新添加虚函数
//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"B::Funtest2"<<endl;
//	}
//};
//
//class D:public B
//{
//public:
//	virtual void Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}



////有部分覆盖且派生类新添加虚函数
//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"B::Funtest2"<<endl;
//	}
//};
//
//class D:public B
//{
//public:
//	virtual void Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//	virtual void Funtest1()//重写基类的虚函数Funtest1()
//	{
//		cout<<"D::Funtest1"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}



////全部覆盖且派生类新添加虚函数
//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"B::Funtest2"<<endl;
//	}
//};
//
//class D:public B
//{
//public:
//	virtual void Funtest2()//重写基类的虚函数Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//	virtual void Funtest1()//重写基类的虚函数Funtest1()
//	{
//		cout<<"D::Funtest1"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}



////没有覆盖的多继承的虚表
//class B1
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B1::Funtest1"<<endl;
//	}
//};
//class B2
//{
//	virtual void Funtest2()
//	{
//		cout<<"B2::Funtest2"<<endl;
//	}
//};
//class D:public B1,public B2
//{
//public:
//	virtual void Funtest3()//新增派生类的虚函数Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//
//	B2 &b2 = d;//打印B2的虚表
//	fun = (Vpf*)*(int*)&b2;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B1)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}


////部分覆盖的多继承的虚表
//class B1
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B1::Funtest1"<<endl;
//	}
//};
//class B2
//{
//	virtual void Funtest2()
//	{
//		cout<<"B2::Funtest2"<<endl;
//	}
//};
//class D:public B1,public B2
//{
//public:
//	virtual void Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()//新增派生类的虚函数Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//
//	B2 &b2 = d;//打印B2的虚表
//	fun = (Vpf*)*(int*)&b2;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B1)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}


////带构造函数的虚拟继承
//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"B::Funtest2"<<endl;
//	}
//};
//class D:virtual public B
//{
//public:
//	D()
//	{}//派生类构造函数
//	virtual void Funtest2()//重写基类的虚函数Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()//新增派生类的虚函数Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//
//    cout<<endl<<endl;
//
//	fun = (Vpf*)*((int*)&d + 3);
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}



////部分覆盖的虚拟继承
//class B1
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B1::Funtest1"<<endl;
//	}
//	virtual void Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//};
//class D:virtual public B1
//{
//public:
//	virtual void Funtest2()//重写基类的虚函数Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()//新增派生类的虚函数Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//
//	D d;//创建派生类对象d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//
//    cout<<endl<<endl;
//
//	fun = (Vpf*)*((int*)&d + 2);
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<sizeof(B1)<<endl;
//	cout<<sizeof(D)<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}




////菱形继承
//class B
//{
//public:
//	virtual void Funtest1()
//	{
//		cout<<"B::Funtest1"<<endl;
//	}
//
//    int _data1;
//};
//class C1:public B
//{
//public:
//	virtual void Funtest2()//新添
//	{
//		cout<<"C1::Funtest2"<<endl;
//	}
//
//	int _data2;
//};
//class C2:public B
//{
//public:
//	virtual void Funtest3()//新添加虚函数
//	{
//		cout<<"C2::Funtest3"<<endl;
//	}
//	virtual void Funtest1()//重写
//	{
//		cout<<"C2::Funtest1"<<endl;
//	}
//
//	int _data3;
//};
//class D:public C1,public C2
//{
//public:
//	virtual void Funtest3()//重写基类的虚函数Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//	virtual void Funtest4()//新添加虚函数Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//
//	int _data4;
//};
//
//typedef void (*Vpf)();//函数指针
//
//void PrintVft()//打印虚表
//{
//
//	D d;//创建派生类对象d
//	d.C1::_data1 = 1;
//	d.C2::_data1 = 5;
//	d._data2 = 2;
//	d._data3 = 3;
//	d._data4 = 4;
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//	
//	cout<<endl<<endl;
//
//	fun = (Vpf*)*((int*)&d + 3);//向后偏移12个字节找到C2的虚表指针
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//}
//int main()
//{
//	cout<<"B  "<<sizeof(B)<<endl;
//	cout<<"C1  "<<sizeof(C1)<<endl;
//	cout<<"C2  "<<sizeof(C2)<<endl;
//	cout<<"D  "<<sizeof(D)<<endl<<endl;
//	PrintVft();
//	system("pause");
//	return 0;
//}



//菱形继承（虚拟继承）
class B
{
public:
	virtual void Funtest1()
	{
		cout<<"B::Funtest1"<<endl;
	}

	int _data1;
};
class C1:virtual public B
{
public:
	virtual void Funtest2()//新添
	{
		cout<<"C1::Funtest2"<<endl;
	}

	int _data2;
};
class C2:virtual public B
{
public:
	virtual void Funtest3()//新添加虚函数
	{
		cout<<"C2::Funtest3"<<endl;
	}
	virtual void Funtest1()//重写
	{
		cout<<"C2::Funtest1"<<endl;
	}

	int _data3;
};
class D:public C1,public C2
{
public:
	virtual void Funtest3()//重写基类的虚函数Funtest3()
	{
		cout<<"D::Funtest3"<<endl;
	}
	virtual void Funtest4()//新添加虚函数Funtest4()
	{
		cout<<"D::Funtest4"<<endl;
	}

	int _data4;
};

typedef void (*Vpf)();//函数指针

void PrintVft()//打印虚表
{

	D d;//创建派生类对象d
	d._data1 = 1;
	d._data2 = 2;
	d._data3 = 3;
	d._data4 = 4;
	Vpf* fun = (Vpf*)*(int*)&d;

	cout<<"D"<<endl;
	while(*fun)
	{
		(*fun)();
		fun++;
	}

	cout<<endl<<endl;

	fun = (Vpf*)*((int*)&d + 3);//向后偏移12个字节找到C2的虚表指针
	while(*fun)
	{
		(*fun)();
		fun++;
	}

	cout<<endl<<endl;

	fun = (Vpf*)*((int*)&d + 7);//向后偏移28个字节找到B的虚表指针
	while(*fun)
	{
		(*fun)();
		fun++;
	}
}
int main()
{
	cout<<"B  "<<sizeof(B)<<endl;
	cout<<"C1  "<<sizeof(C1)<<endl;
	cout<<"C2  "<<sizeof(C2)<<endl;
	cout<<"D  "<<sizeof(D)<<endl<<endl;
	PrintVft();
	system("pause");
	return 0;
}

