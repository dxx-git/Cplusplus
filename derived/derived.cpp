#include <iostream>
using namespace std;
//
//class Person
//{
//public://�������ݳ�Ա
//	int length;//���
//	int weight;//����
//};
//
//class Student:public Person
//{
//public:
//	void test1()
//	{
//		length = 183;//�����пɷ��ʸ���Ĺ��г�Ա���������Ժͷ�����
//		weight = 70;
//		total = 300;
//	}
//private:
//	int total;//�ܷ�
//	char* school;//ѧУ
//};
//
//void Funtest()
//{
//	Student s1;
//	s1.length = 160;//����������Ķ���ɷ��ʻ���Ĺ��г�Ա���������Ժͷ�����
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
//	private://˽�����ݳ�Ա
//	int length;//���
//};
//
//class Student:private Person
//{
//public:
//	void test1()
//	{
//		length = 183;//�����в����Է��ʸ����˽�г�Ա���������Ժͷ�����
//	}
//};
//
//void Funtest()
//{
//	Student s1;
//	s1.length = 160;//����������Ķ��󲻿��Է��ʻ����˽�г�Ա���������Ժͷ�����
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
//	b = &d;//����ָ��ָ���������
//
//	D *d1;
//	B b1;
//	d1 = (D*)&b1;//��������ͨ��ǿ������ת��ָ�������(��������)
//
//	D &d2 = d;
//	B b2;
//	b2 = d2;//��������ָ���������
//
//	D d3;
//	B &b3 = b1;
//    d3 = (D&)b3;//��������ָ���������
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