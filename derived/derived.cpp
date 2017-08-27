#include <iostream>
using namespace std;
//
//class Person
//{
//public://公有数据成员
//	int length;//身高
//	int weight;//体重
//};
//
//class Student:public Person
//{
//public:
//	void test1()
//	{
//		length = 183;//子类中可访问父类的共有成员（包括属性和方法）
//		weight = 70;
//		total = 300;
//	}
//private:
//	int total;//总分
//	char* school;//学校
//};
//
//void Funtest()
//{
//	Student s1;
//	s1.length = 160;//类外派生类的对象可访问基类的公有成员（包括属性和方法）
//	s1.weight = 45;
//}
//int main()
//{
//	Funtest();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Person
//{
//	private://私有数据成员
//	int length;//身高
//};
//
//class Student:private Person
//{
//public:
//	void test1()
//	{
//		length = 183;//子类中不可以访问父类的私有成员（包括属性和方法）
//	}
//};
//
//void Funtest()
//{
//	Student s1;
//	s1.length = 160;//类外派生类的对象不可以访问基类的私有成员（包括属性和方法）
//}
//int main()
//{
//	Funtest();
//	return 0;
//}

//class B
//{
//public:
//	B()
//	{
//		cout<<"B()"<<endl;
//	}
//	~B()
//	{
//		cout<<"~B()"<<endl;
//	}
//};
//
//class D:public B
//{
//public:
//	D()
//	{
//		cout<<"D()"<<endl;
//	}
//	~D()
//	{
//		cout<<"~D()"<<endl;
//	}
//};
//
//void Funtest()
//{
//	D d;
//}
//int main()
//{
//	Funtest();
//	return 0;
//}



//class B
//{
//protected:
//	int _a;
//};
//
//class D:public B
//{
//public:
//	void test()
//	{
//		B::_a = 10;
//	}
//private:
//	int _a;
//};
//
//void Funtest()
//{
//	D d;
//	d.test();
//}
//int main()
//{
//	Funtest();
//	return 0;
//}

//class B
//{
//protected:
//	int _b;
//};
//
//class D:public B
//{
//private:
//	int _d;
//};
//
//void Funtest()
//{
//	D d;
//	B *b;
//	b = &d;//父类指针指向子类对象
//
//	D *d1;
//	B b1;
//	d1 = (D*)&b1;//子类对象可通过强制类型转换指向父类对象(尽量避免)
//
//	D &d2 = d;
//	B b2;
//	b2 = d2;//父类引用指向子类对象
//
//	D d3;
//	B &b3 = b1;
//    d3 = (D&)b3;//父类引用指向子类对象
//}
//int main()
//{
//	Funtest();
//	return 0;
//}


class B
{
	int _b;
};
class C1:virtual public B
{
	int _c1;
};
class C2:virtual public B
{
	int _c2;
};
class D:public C1,public C2
{
	int _d;
};
void Funtest()
{
	D d;
	d._d = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._b = 4;
}