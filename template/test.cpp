#include<iostream>
using namespace std;
//
//int Add(const int &_iLeft, const int &_iRight)
//{
//	return (_iLeft + _iRight);
//}
//float Add(const float &_fLeft, const float &_fRight)
//{
//	return (_fLeft + _fRight);
//}
//
//int main()
//{
//	cout<<Add(1,3)<<endl;
//	cout<<Add(1.3f,2.5f)<<endl;
//    system("pause");
//	return 0;
//}


//class B
//{
//public:
//	virtual int add(int _x,int _y)
//	{
//		return (_x+_y);
//	}
//	virtual float add(float _x,float _y)
//	{
//		return (_x+_y);
//	}
//};
//class INT_ADD:public B
//{};
//class FLOAT_ADD:public B
//{};
//
//int main()
//{
//	B *b;
//	INT_ADD i;
//	FLOAT_ADD f;
//
//	b = &i;
//	cout<<b->add(1,3)<<endl;
//	b = &f;
//	cout<<b->add(1.8f,3.6f)<<endl;
//
//	system("pause");
//	return 0;
//}


//template <typename T>
//T ADD(T x,T y)
//{
//	return (x+y);
//}
//int main()
//{
//	cout<<ADD(1,3)<<endl;
//	cout<<ADD(1.3,2.5)<<endl;
//	system("pause");
//	return 0;
//}


//template <typename ���Ͳ���>
//�������� ������ (ģ���βα�)
//{
//	������
//}
//
//
//template <class ���Ͳ���>
//�������� ������ (ģ���βα�)
//{
//	������
//}


//template <typename T>
// T ADD(T x,T y)
//{
//	return (x+y);
//}
//int main()
//{
//	cout<<ADD(1,3)<<endl;//��ʽʵ����
//	cout<<ADD<float>(1.3f,2.5f)<<endl;//��ʽʵ����
//	system("pause");
//	return 0;
//}


//template <typename T,typename G>
//T ADD(T x,G y)
//{
//	return (x+y);
//}
//int main()
//{
//    cout<<ADD(1,'d');
//	system("pause");
//	return 0;
//}


//template <typename T>
// T ADD(const T& x,const T& y)
//{
//	return (x+y);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int &ra = a;
//	int &rb = b;
//	
//	cout<<"a + b ="<<ADD(ra,rb)<<endl;
//	system("pause");
//	return 0;
//}


//template <typename T>
//T ADD(const T* x,const T* y)
//{
//	return (*x + *y);
//}
//int main()
//{
//	int a[5] = {0};
//	int b[5] = {5,4,3,2,1};
//	cout<<"a + b = "<<ADD(a,b)<<endl;
//	system("pause");
//	return 0;
//}


//typedef int T;//��int����������ΪT
//
//template <typename T>//����ģ��
//void Funtest(T t)
//{
//	cout<<"t type = "<<typeid(t).name()<<endl;//��ӡ�β�t������
//}
//
//T gloab;//����ȫ�ֱ���gloab
//
//int main()
//{
//	Funtest(10);
//	cout<<"gloab type = "<<typeid(gloab).name()<<endl;
//	system("pause");
//	return 0;
//}

//template <typename T,G>//error C2061: �﷨����: ��ʶ����G��
//void Funtest(T t,G g)//error C2061: �﷨����: ��ʶ����G��
//{}

//template<class T, U, typename V>
//void f1(T, U, V);//�ں���ģ����ڲ�����ָ��ȱʡ��ģ��ʵ��
//
//template<class T>
//T f2(int &T);//�βε�������ģ������Ͳ���ͬ�������������
//
//template<class T>
//T f3 (T, T);//��ȷ
//
//typedef int TYPENAME;
//template<typename TYPENAME>
//TYPENAME f4(TYPENAME);//������������ģ������Ͳ���ͬ����ʹ��ʱ��ѭ�ͽ�ԭ��
//
//int main()
//{
//	f1(1,'g',"ac");
//	int a = 0;
//	//a = f2(&a);
//	f3(1,3);
//}

//int Max(const int& left, const int & right)//��ͨ����
//{
//	return left>right? left:right;
//}
//template<typename T>
//T Max(const T& left, const T& right)
//{
//	return left>right? left:right;
//}
//template<typename T>
//T Max(const T& a, const T& b, const T& c)
//{
//	return Max(Max(a, b), c);
//};
//int main()
//{
//	cout<<Max(10, 20, 30)<<endl;
//	cout<<Max<>(10, 20)<<endl;
//	cout<<Max(10, 20)<<endl;
//	cout<<Max(10, 20.12)<<endl;
//	cout<<Max<int>(10.0, 20.0)<<endl;
//	cout<<Max(10.0, 20.0)<<endl;
//	//cout<<Max("abh","ghj");
//	system("pause");
//	return 0;
//}


//template <typename T>
//int Compare(T s1, T s2) 
//{
//	if(s1<s2)
//		return -1;
//	else if(s1>s2)
//		return 1;
//	else 
//		return 0;
//}
//template<>//ģ�庯�����ػ�
//int Compare<const char*>(const char* s1,const char* s2)
//{
//	return strcmp(s1,s2);
//}
//int main()
//{
//	const char* str1 = "abcd";
//	const char* str2 = "ghf";
//	cout<<Compare(str1,str2)<<endl;
//	system("pause");
//	return 0;
//}


template <typename T>
int Compare(T s1, T s2) 
{
	if(s1<s2)
		return -1;
	else if(s1>s2)
		return 1;
	else 
		return 0;
}
template<>//ģ�庯�����ػ�
int Compare<const char*>(const char* s1,const char* s2)//ע���������Ϊconst char*
{
	return strcmp(s1,s2);
}
int main()
{
	char* str1 = "abcd";//����ʵ������Ϊchar*
	char* str2 = "ghf";//����ʵ������Ϊchar*
	cout<<Compare(str1,str2)<<endl;
	system("pause");
	return 0;
}