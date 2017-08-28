#include<iostream>
#include<string.h>
using namespace std;

#define  _CRT_SECURE_NO_WARNINGS 1

class String
{
public:
	String()//construct
	{}
	String(const char* s)//construct
		:_p(new char[strlen(s)] + 1)
	{
		if (*s == 0)
		{
			_p = '\0';
		}
		else
		{
			strcpy(_p, s);
		}
	}

	String(const String& s)//ordinary
		:_p(new char[strlen(s._p) + 1])
	{
		strcpy(_p, s._p);
	}

	//String(const String& s)//simple1
	//{
	//	char* temp(s._p);
	//	swap(temp, _p);
	//}

	//String(const String& s)//simple2
	//	:_p(NULL)
	//{
	//	String temp(s._p);
	//	swap(temp._p, _p);
	//}

	String& operator=(const String& s)//ordinary
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._p) + 1];
			strcpy(temp, s._p);
			delete[]_p;
			_p = temp;
		}
		return *this;
	}

	//String& operator=(const String& s)//simple1
	//{
	//	if (this != &s)
	//	{
	//		delete[]_p;
	//		_p = new char[strlen(s._p) + 1];
	//		strcpy(_p, s._p);
	//	}
	//	return *this;
	//}

	//String& operator=(const String& s)//simple2
	//{
	//	if (this != &s)
	//	{
	//		String temp(s._p);//String temp(s);
	//		swap(temp._p, _p);
	//	}
	//	return *this;
	//}

	//String& operator=(String s)//simple3
	//{
	//	swap(s._p, _p);
	//	return *this;
	//}

	~String()//destruct
	{
		if (_p != NULL)
		{
			delete[]_p;
			_p = NULL;
		}
	}

public:
	char* _p;
};

int main()
{
	const char* str = "abcdef";
	String s1;
	String s2(str);
	String s3("ghijk");
	s1 = s3;
	cout << "s1 = " << s1._p << endl;
	cout << "s2 = " << s2._p << endl;
	cout << "s3 = " << s3._p << endl;
	return 0;
}
