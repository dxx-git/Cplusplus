#include<iostream>
using namespace std;
class Date 
{
public:
	explicit Date(int year)//�������캯��Date��ԭ��
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
//	Date(int year,int month,int day);//�������캯��Date��ԭ��
//	void showDate();
//private:
//	 int  _year;
//	 int _month;
//	 int _day;
//};
//Date::Date(int year,int month,int day)//���幹�캯��Date()
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
//	Date(int year,int month,int day);//�������캯��Date��ԭ��
//private:
//    int _year;
//	int _month;
//	int _day;
//	Time t;
//};
//Date::Date(int year,int month,int day)//���幹�캯��Date()
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
//	Date();//�������캯��Date��ԭ��
//	void setDate(int year,int month,int day);
//	void showDate();
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date()//���幹�캯��Date
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
//	Date(int year,int month,int day);//�������캯��Date��ԭ��
//	void setDate(int year,int month,int day);
//	void showDate();
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date(int year,int month,int day)//���幹�캯��Date
//    :_year(year)//��Ա��ʼ���б�
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
