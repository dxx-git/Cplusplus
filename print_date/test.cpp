#include<iostream>
using namespace std;

class Date
{
	friend  void print_date(int year,int month);//��ӡ����
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year,int month,int day);//���캯��
	Date(const Date& d);//�������캯��
	Date& operator=(const Date& d);
	Date operator+(int day);
	Date& operator++();
	Date operator++(int);
	Date operator-(int day);
	int operator-(/*const*/ Date& d);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	int days_everymonth(int year,int month);//�����µ�����
	Date& display(const Date& d);//��ӡĳ������
private:
	int _year;
	int _month;
	int _day;
};

	bool judge_leap(int year);//�ж��Ƿ�����
	void print_date(int year,int month);//��ӡ����
	int week_firstday(int year,int day);//����Ҫ�������ĵ�һ�������ڼ�

 ostream& operator<<(ostream& _cout, const Date& d)
 {
	 _cout<<d._year<<"--"<<d._month<<"--"<<d._day;
	 return _cout;
 }
 istream& operator>>(istream& _cin, Date& d)
 {
	 _cin>>d._year>>d._month>>d._day;
	 return _cin;
 }
 Date::Date(int year = 2016,int month = 1,int day = 1)//���캯��
	 :_year(year)
	 ,_month(month)
	 ,_day(day)
{
	if(    (year < 1949)
		|| ((month < 1) && (month>12))
		|| ((day < 0) && (day > days_everymonth(_year,_month))))//���Ϸ������ڽ�����ΪĬ��ֵ
	{
		year = 2016;
		month = 1;
		day = 1;
	}
}
 Date::Date(const Date& d)
 {
	 _year = d._year;
	 _month = d._month;
	 _day = d._day;
 }
 Date& Date::operator=(const Date& d)
 {
	 if(this != &d)
	 {
		 _year = d._year;
		 _month = d._month;
		 _day = d._day;
	 }
	 return *this;
 }
 Date Date::operator+(int day)
 {
	 _day = _day + day;
	 
	 while (_day > days_everymonth(_year,_month))
	 {
		 _day = _day - days_everymonth(_year,_month);
	     if(_month == 12)
		 {
			 _year += 1;
			 _month = 1;
		 }
		 else
		 {
			 _month += 1;
		 }
	 }
	return *this;
 }
 Date& Date::operator++()
 {
	 _day++;
	 
	 if (_day > days_everymonth(_year,_month))
	 {
		 _day = _day - days_everymonth(_year,_month);
		 if(_month == 12)
		 {
			 _year += 1;
			 _month = 1;
		 }
		 else
		 {
			 _month += 1;
		 }
	 }
	
	 return *this;
 }
 Date Date::operator++(int)
 {
	 Date temp(*this);
	 ++_day;

	 if (_day > days_everymonth(_year,_month))
	 {
		 _day = _day - days_everymonth(_year,_month);
		 if(_month == 12)
		 {
			 _year += 1;
			 _month = 1;
		 }
		 else
		 {
			 _month += 1;
		 }
	 }

	 return temp;
 }
 Date Date::operator-(int day)
 {
	 _day = _day - day;

	 while (_day <= 0)
	 {
		 
		 if(_month == 1)
		 {
			 _month = 12;
			 _year -=1;
		 }
		 else
		 {
			 _month -= 1;
		 }
		  _day +=  days_everymonth(_year,_month);
	 }

	 return *this;
 }
 int Date::operator-(Date& d)
 {
	 Date max;
	 Date min;
	 if(*this > d)
	 {
		 max = *this;
         min = d;
	 }
	 else
	 {
	     max = d;
		 min = *this;
	 }
	 int day = 0;
	 while(max > min)
	 {
		 min = min +1;
		 day++;
	 }
	 return day;
 }
 Date& Date::operator--()
 {
	 _day--;

	 if (_day == 0)
	 {
		 _month -= 1;
		 if(_month == 0)
		 {
			 _month = 12;
			 _year -= 1;
		 }
		 _day = days_everymonth(_year,_month);
	 }
	 return *this;
 }
 Date Date::operator--(int)//���üӼ�
 {
	 Date temp(*this);
	 --_day;

	 if(_day == 0)
	 {
		 _month -= 1;
		 if(_month == 0)
		 {
			 _month = 12;
			 _year -= 1;
		 }
		 _day = days_everymonth(_year,_month);
	 }
	 return temp;
 }
 bool Date::operator>(const Date& d)
 {
	 /*if(_year > d._year)
		 return true;
	 else if(_year < d._year)
		 return false;
	 else
	 {
		 if(_month > d._month)
			 return true;
		 else if(_month < d._month)
			 return false;
		 else
		 {
		     if(_day > d._day)
				 return true;
			 else
				 return false;
		 }
	 }*/

	 if(   (_year > d._year)
		 ||((_year == d._year) && (_month > d._month))
		 ||(((_year == d._year) && (_month == d._month) && (_day > d._day))))
		 return true;
	 else
		 return false;
 }
 bool Date::operator<(const Date& d)
 {
	 /*if(_year < d._year)
		 return true;
	 else if(_year > d._year)
		 return false;
	 else
	 {
		 if(_month < d._month)
			 return true;
		 else if(_month > d._month)
			 return false;
		 else
		 {
			 if(_day < d._day)
				 return true;
			 else
				 return false;
		 }
	 }*/

	 if(   (_year < d._year)
		 ||((_year == d._year) && (_month < d._month))
		 ||(((_year == d._year) && (_month == d._month) && (_day < d._day))))
		 return true;
	 else
		 return false;
 }
 bool Date::operator==(const Date& d)
 {
	 /*if(_year != d._year)
		 return false;
	 else
	 {
		 if(_month != d._month)
			 return false;
		 else
		 {
			 if(_day == d._day)
				 return true;
			 else
				 return false;
		 }
	 }*/

	 if((_year == d._year) && (_month == d._month) && (_day  == d._day))
		 return true;
	 else
		 return false;
 }
 bool Date::operator!=(const Date& d)
 {
	 if((_year != d._year) || (_month != d._month) || (_day != d._day))
		 return true;
	 else 
		 return false;
 }
 bool Date::operator>=(const Date& d)
 {
	 if(_year >= d._year)
		 return true;
	 else
	 {
		 if(_month >= d._month)
			 return true;
		 else
		 {
			 if(_day >= d._day)
				 return true;
			 else
				 return false;
		 }
	 }
 }
 bool Date::operator<=(const Date& d)
 {
	 if(_year <= d._year)
		 return true;
	 else
	 {
		 if(_month <= d._month)
			 return true;
		 else
		 {
			 if(_day <= d._day)
				 return true;
			 else
				 return false;
		 }
	 }
 }
 
 static bool judge_leap(int year)
 {
	 if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0)))
		 return true;
	 else
		 return false;
 }
 static int week_firstday(int year,int month)
 {
	 Date d1(1949,9,21);//���й���1949�꿪ʼʹ�ù�Ԫ���귨
	 int week = 3;//��Ԫ1949��9��21��Ϊ��һ
	 int day = 0;
	 Date d2(year,month,1);
	 day = d2 - d1;//ͳ��Ŀ���·ݵĵ�һ������ʼ������������
	 week += day%7;
	 if(week > 7)
	 {
		 week -= 7;
	 }
	 return week;
 }
 Date& Date::display(const Date &d)
 {
	 cout<<d._year<<"--"<<d._month<<"--"<<d._day<<endl;
	 return *this;
 }
 int Date::days_everymonth(int year,int month)
 {
	 int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	 if(judge_leap(year) == true)
		 day[2] = 29;//�����2����29��
	 return day[month];
 }
 void print_date(int year,int month)//��ӡ����
 {
	 cout<<year<<"��"<<month<<"��"<<endl;
	 cout<<"��"<<" "<<"һ"<<" "<<"��"<<" "<<"��"<<" "<<"��"<<" "<<"��"<<" "<<"��"<<endl;
	 int i = 0;
	 int j = 0;
	 Date temp(year,month,1);
	 int week = week_firstday(year,month);
	 int day = temp.days_everymonth(year,month);//��Ҫ��ӡ�µ�����
	 int k = 1;
	 for(i=0; i<week; i++)
	 {
		 cout<<"   ";
	 }
	 for(i=0; i<6; i++)
	 {
		 for(j=0; j<7; j++)
		 {
			 if(i == 0)
			 {
				 if(j == 7-week)
					 break;
			 }
			 if(k <= day)
				 printf("%2d ",k++);
		 }
		 cout<<endl;
	 }
 }
 
 void Funtest()
 {
	 Date d1(2016,10,17);
	 Date d2(d1);
	 d1.operator+(100);
	 d2.operator-(33);
	 d1.operator+(999);
	 cout<<d1<<endl;
	 d2.operator-(100);
	 d2.operator-(999);
	 cout<<d2<<endl;
	 
	 
	/*Date d1(2016,10,12);
	 cin>>d1;
	 d1++;
	 cout<<d1<<endl;
	 Date d2;
	 d2 = d1;
	 d2.operator-(33);
	 d2.display(d2);
	 int ret = d1.operator<(d2);
	 print_date(2016,10);*/
 }
 int main()
 {
	 Funtest();
	 system("color 1E");
	 system("pause");
	 return 0;
 }