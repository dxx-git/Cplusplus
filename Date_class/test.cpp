#include<iostream>
using namespace std;
class Date 
{
public:
	explicit Date(int year)//声明构造函数Date的原型
	{
		cout<<"Date()"<<endl;
	}
private:
	int  _year;
	int _month;
	int _day;
};
int main()
{
	Date date = 2016;
	system("pause");
	return 0;
}

//#include<iostream>
//using namespace std;
//class Date 
//{
//public:
//	Date(int year,int month,int day);//声明构造函数Date的原型
//	void showDate();
//private:
//	 int  _year;
//	 int _month;
//	 int _day;
//};
//Date::Date(int year,int month,int day)//定义构造函数Date()
//	:_year(_month)
//	,_month(_day)
//	,_day(day)
//{}
//void Date::showDate()
//{
//	cout<<_year<<"->"<<_month<<"->"<<_day<<endl;
//}
//int main()
//{
//	Date date(2016,1,4);
//	date.showDate();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour,int minute,int second);
//private:
//	int _hour;
//	int _minute;
//	int second;
//};
//Time::Time(int hour,int minute,int second)
//{}
//class Date 
//{
//public:
//	Date(int year,int month,int day);//声明构造函数Date的原型
//private:
//    int _year;
//	int _month;
//	int _day;
//	Time t;
//};
//Date::Date(int year,int month,int day)//定义构造函数Date()
//	:_year(year)
//	,_month(month)
//	,_day(day)
//	,t(00,00,00)
//{}
//int main()
//{
//	Date date(2016,1,1);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date 
//{
//public:
//	Date();//声明构造函数Date的原型
//	void setDate(int year,int month,int day);
//	void showDate();
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date()//定义构造函数Date
//{
//	cout<<"initialized"<<endl;
//}
//
//void Date::setDate(int year,int month,int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//
//void Date::showDate()
//{
//	cout<<_year<<"->"<<_month<<"->"<<_day<<endl;
//}
//
//int main()
//{
//	Date date;
//	date.setDate(2016,9,27);
//	date.showDate();
//	system("pause");
//	return 0;
//}
//


//#include<iostream>
//using namespace std;
//
//class Date 
//{
//public:
//	Date(int year,int month,int day);//声明构造函数Date的原型
//	void setDate(int year,int month,int day);
//	void showDate();
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date(int year,int month,int day)//定义构造函数Date
//    :_year(year)//成员初始化列表
//	,_month(month)
//	,_day(day)
//	{}
//
//
//void Date::setDate(int year,int month,int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//
//void Date::showDate()
//{
//	cout<<_year<<"->"<<_month<<"->"<<_day<<endl;
//}
//
//int main()
//{
//	Date date(2016,1,1);
//	date.setDate(2016,9,27);
//	date.showDate();
//	system("pause");
//	return 0;
//}
//
