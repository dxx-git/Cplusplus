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
//	Base(int x,int y)//���캯��
//	{
//		a = x;
//		b = y;
//	}
//	virtual void show()//�麯��
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
//	Derived(int x,int y,int z):Base(x,y)//������Ĺ��캯����Ϊ���๹�캯�����Σ�
//	{
//		c = z;
//	}
//	void show()//���¶����麯��show
//	{
//		cout<<"Derived::"<<c<<endl;
//	}
//private:
//	int c;
//};
//
//int main()
//{
//	Base b(60,60);//�����������b
//	Base *pb;//������ָ����pb
//	Derived d(10,20,30);//�������������d
//
//	pb = &b;//����ָ��ָ��������b
//	pb->show();//���û�����麯��show()
//	pb = &d;//����ָ��ָ�����������d
//	pb->show();//������������麯��show()
//
//	system("pause");
//	return 0;
//}



////��������
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


////��д
//class Base
//{
//public:
//	virtual void show(int x,int y)//�麯��
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
//	void show(int x,int y)//���¶����麯��show
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
//	Base b;//�����������b
//	Derived d;//�������������d
//	
//    b.show(10,20);
//	d.Derived::show(30,40);
//	system("pause");
//	return 0;
//}


////ͬ������
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
//	Derived d;//�������������d
//
//	d.show();//�����������Լ���ͬ������
//	d.Base::show();//���û����ͬ������
//	system("pause");
//	return 0;
//}


////��д��Э�䣩
//class Base
//{
//public:
//	virtual Base& fun(int x,int y)//�麯��
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
//	Derived& fun(int x,int y)//���¶����麯��show
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
//	Base b;//�����������b
//	Derived d;//�������������d
//	
//    b.fun(10,20);
//	d.Derived::fun(30,40);
//	system("pause");
//	return 0;
//}



//class Circle//����
//{
//public:
//	void setr(int x)
//	{
//		r = x;
//	}
//	virtual void show() = 0;//���崿�麯��
//protected:
//	int r;
//};
//class Area:public Circle//������
//{
//public:
//	void show()//���¶����麯��show��Բ�����
//	{
//		cout<<"Area is "<<3.14*r*r<<endl;
//	}
//};
//int main()
//{
//	Circle* p;//����ָ��
//	Area a;//���������a
//    a.setr(5);
//	p = &a;
//	p->show();//����Բ�����
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
//	virtual void show()//�����麯��
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
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
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


////û�и�����������û��������麯��
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
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//	D d;//�������������d
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



////û�и�����������������麯��
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
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//	D d;//�������������d
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



////�в��ָ�����������������麯��
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
//	virtual void Funtest1()//��д������麯��Funtest1()
//	{
//		cout<<"D::Funtest1"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//};
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//	D d;//�������������d
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



////ȫ��������������������麯��
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
//	virtual void Funtest2()//��д������麯��Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//	virtual void Funtest1()//��д������麯��Funtest1()
//	{
//		cout<<"D::Funtest1"<<endl;
//	}
//	virtual void Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//};
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//	D d;//�������������d
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



////û�и��ǵĶ�̳е����
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
//	virtual void Funtest3()//������������麯��Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//
//	D d;//�������������d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//
//	B2 &b2 = d;//��ӡB2�����
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


////���ָ��ǵĶ�̳е����
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
//	virtual void Funtest3()//������������麯��Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//
//	D d;//�������������d
//	Vpf* fun = (Vpf*)*(int*)&d;
//
//	cout<<"D"<<endl;
//	while(*fun)
//	{
//		(*fun)();
//		fun++;
//	}
//
//	B2 &b2 = d;//��ӡB2�����
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


////�����캯��������̳�
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
//	{}//�����๹�캯��
//	virtual void Funtest2()//��д������麯��Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()//������������麯��Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//
//	D d;//�������������d
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



////���ָ��ǵ�����̳�
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
//	virtual void Funtest2()//��д������麯��Funtest2()
//	{
//		cout<<"D::Funtest2"<<endl;
//	}
//	virtual void Funtest3()//������������麯��Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//};
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//
//	D d;//�������������d
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




////���μ̳�
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
//	virtual void Funtest2()//����
//	{
//		cout<<"C1::Funtest2"<<endl;
//	}
//
//	int _data2;
//};
//class C2:public B
//{
//public:
//	virtual void Funtest3()//������麯��
//	{
//		cout<<"C2::Funtest3"<<endl;
//	}
//	virtual void Funtest1()//��д
//	{
//		cout<<"C2::Funtest1"<<endl;
//	}
//
//	int _data3;
//};
//class D:public C1,public C2
//{
//public:
//	virtual void Funtest3()//��д������麯��Funtest3()
//	{
//		cout<<"D::Funtest3"<<endl;
//	}
//	virtual void Funtest4()//������麯��Funtest4()
//	{
//		cout<<"D::Funtest4"<<endl;
//	}
//
//	int _data4;
//};
//
//typedef void (*Vpf)();//����ָ��
//
//void PrintVft()//��ӡ���
//{
//
//	D d;//�������������d
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
//	fun = (Vpf*)*((int*)&d + 3);//���ƫ��12���ֽ��ҵ�C2�����ָ��
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



//���μ̳У�����̳У�
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
	virtual void Funtest2()//����
	{
		cout<<"C1::Funtest2"<<endl;
	}

	int _data2;
};
class C2:virtual public B
{
public:
	virtual void Funtest3()//������麯��
	{
		cout<<"C2::Funtest3"<<endl;
	}
	virtual void Funtest1()//��д
	{
		cout<<"C2::Funtest1"<<endl;
	}

	int _data3;
};
class D:public C1,public C2
{
public:
	virtual void Funtest3()//��д������麯��Funtest3()
	{
		cout<<"D::Funtest3"<<endl;
	}
	virtual void Funtest4()//������麯��Funtest4()
	{
		cout<<"D::Funtest4"<<endl;
	}

	int _data4;
};

typedef void (*Vpf)();//����ָ��

void PrintVft()//��ӡ���
{

	D d;//�������������d
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

	fun = (Vpf*)*((int*)&d + 3);//���ƫ��12���ֽ��ҵ�C2�����ָ��
	while(*fun)
	{
		(*fun)();
		fun++;
	}

	cout<<endl<<endl;

	fun = (Vpf*)*((int*)&d + 7);//���ƫ��28���ֽ��ҵ�B�����ָ��
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

