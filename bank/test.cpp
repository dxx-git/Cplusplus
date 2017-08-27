#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include <string>
using namespace std;
class man;
class Bank 
{
	public:
		Bank();
		void Set(); //银行开户
		void Del(); //银行销户  
		void Trans(int);   //转账
		void Enter();//进入系统
		void addmoney(int,double); //存款
		void Exit();    // 退出系统
		void Choose();//选择
        void Save();     //存储信息
		void load();   // 功能界面
	protected:
               man *desc[20];
               static int Sum;   //账户数
    };
int Bank::Sum=0;
Bank::Bank() //构造函数
{
}
class man:public Bank  //从Bank共有继承 
{
	public:
		friend class Bank;
		man(int id,string Name,string PassWord,double m,string num,string car,string add,string pla) //有参构造
		{
			ID=id;name=Name;money=m;passwd=PassWord;number=num;card=car;address=add;place=pla;
		}
		man()                                             //无参构造
		{
		    ID=0;name='0';money=0;passwd='0';number='0';card='0';address='0';place='0';
		}
		int Getid()//取得ID
		  {
		    return ID;
		  }
		void Seve_();// 存储信息
		string get_passwd()// 取得密码
		{
		   return passwd;
		}
		void show(); 
		void getmon(); //取钱
		void change_();  // 改密码 
		void ADD(double);  //存钱 
		void Trans_(double);  //转账 
		double Getmon();   //两卡转帐
    private:
		int ID; //开户帐号
		string passwd; // 用户密码
		string name;   // 用户姓名 
		double money;  //金钱
		string number; //电话
		string card;   //身份证 
		string address;//地址 
		string place;  //单位 
};
void Bank::Save()      //存储信息
{
	ofstream ofile("用户信息.txt",ios::out);
	ofstream outfile("用户信息.txt",ios::out);
	int n=0;
	outfile<<Sum<<" ";
	for(;n<Sum;n++)
	{
	outfile<<desc[n]->ID<<" ";
	outfile<<desc[n]->money<<" ";
	outfile<<desc[n]->name<<" ";
	outfile<<desc[n]->passwd<<" ";
	outfile<<desc[n]->number<<" ";
	outfile<<desc[n]->card<<" ";
	outfile<<desc[n]->address<<" ";
	outfile<<desc[n]->place<<" ";
	}
	outfile.close(); 
}

void Bank::load()        // 功能界面
{
	ifstream infile("用户信息.txt",ios::in);
	if(!infile)
	{
	  return ;
	}
	int n=0;
	int id,m;
	string nam,passw,num,car,add,pla;
	infile>>Sum;
	for(;n<Sum;n++)
	{
		infile>>id;
		infile>>m;
		infile>>nam;
		infile>>passw;
		infile>>num;
	        infile>>car;
	        infile>>add;
	        infile>>pla;
		desc[n]->passwd;
		man *acc=new man(id,nam,passw,m,num,car,add,pla); 
		desc[n]=acc; 
	}
    infile.close();
}
void Bank::Trans(int x)       //转账
{   
    int id; 
	cout<<"请输入帐号:"; 
	cin>>id; 
	int flag = 1; 
	int i = 0; 
	while((flag)&&(i<Sum)) 
    { 
      if(id==desc[i]->Getid()) 
	  flag = 0;
	  else i++; 
    } 
    if(flag) 
	{ 
		cout<<"\t------------帐号不存在!------------"<<endl<<endl; 
		return ;
	} 
   double b;
   cout<<endl<<"请输入您要转帐的金额:";
   cin>>b;
   while(b<=0)
   {
	cout<<"请输入正确的数字!"<<endl;
	cout<<"请选择：";
	cin>>b;
   }
	if(desc[x]->Getmon()<b) 
	cout<<"—————————————金额不足"<<endl;
	else 
	{
	desc[x]->Trans_(b);desc[i]->ADD(b);
    cout<<"转帐成功!";
	}

   return;
}

void man::ADD(double x)
{
	money=x+money;
}
void man::Trans_(double x)
{
    money=money-x;
}
void Bank::addmoney(int x,double y)
{
   desc[x]->money=desc[x]->money-y;
}
double man::Getmon()
{
	return money;
}


void Bank::Choose()
{
	int n;

    while(true)  
	{
		system("cls"); load();
		cout<<endl<<"请输入编号以便进行操作！"<<endl;
		cout<<"\t\t1 账户登陆\n"<<endl<<"\t\t2 用户开户\n"<<endl<<"\t\t3 帐户注销\n"<<endl<<"\t\t4 退出系统 \n"<<endl;
		cout<<"您好，请输入您需要的服务：";
		cin>>n;
	    if(n==1)
	      Enter();
	    else if(n==2)
		Set();  
		 else if(n==3)
		   Del();
		 else if(n==4)
		 Exit();
	   	cin.get();
	}
}
void Bank::Enter()
{
	int id; 
	cout<<"请输入帐号:"; 
	cin>>id; 
	int flag = 1; 
	int i = 0; 
	while((i<Sum)&&(flag)) 
	{ 
		if(id==desc[i]->Getid()) flag = 0; else i++; 
	} 
	if(flag) 
	{ 
		cout<<"此帐号不存在!"<<endl<<endl; 
		system("pause"); 
		return; 
	} 
	cout<<"请输入密码:";
	string passw;
	cin>>passw;
	if(passw!=desc[i]->get_passwd()) return;
	desc[i]->show();cin.get();cin.get();
	int n;
	while(1)
	{
      	system("cls"); 
	  	cout<<"请选择您要进行的操作:"<<"\n"<<endl; 
		cout<<"\t1 用户转账！"<<endl;
		cout<<"\t2 用户取款！"<<endl;
		cout<<"\t3 存用户款！"<<endl;
		cout<<"\t4 修改密码！"<<endl;
		cout<<"\t5 查看信息！"<<endl;
		cout<<"\t6 账号退出！"<<endl;
		cout<<"请输入序号：" ;
      	cin>>n;
      	if(n==1)
      	{
		   Trans(i);Save();
		  }
		  else if(n==2)
		  {
		  	desc[i]->getmon();Save();
		  }
		  else if(n==3)
		  {
		  	desc[i]->Seve_();Save();
		  }
		  else if(n==4)
		  {
		  	desc[i]->change_();Save();
		  }
		  else if(n==5)
		  {
		  	desc[i]->show();
		  }
		  else if(n==6)
		  {
		  	return ;
		   } 
	    cin.get();cin.get();
   }
}
void Bank::Set()
{
	int id;
	string nam;
	string passw,num,car,add,pla;
	double m;
	cout<<endl<<"请输入开户号：";
	cin>>id;
	cout<<endl<<"请输入开户人姓名：";
	cin>>nam;
	cout<<endl<<"请输入开户密码：";
	cin>>passw;
	cout<<endl<<"请输入电话号码：";
	cin>>num;
	cout<<endl<<"请输入身份证号：";
	cin>>car;
	cout<<endl<<"请输入地址：";
	cin>>add;
	cout<<endl<<"请输入单位：";
	cin>>pla;
	cout<<endl<<"请输入存入金额:";
	cin>>m;
	man * acc = new man(id,nam,passw,m,num,car,add,pla); 
	desc[Sum] = acc; 
	cout<<"开户成功!"<<endl<<endl; 
	Sum++;
	Save();
	cin.get();
	return;
}
void Bank::Del()
{
	int id;
	cout<<endl<<"请输入您要注销的帐户号:";
	cin>>id;
	int flag = 1; 
	int i = 0; 
	while((i<Sum)&&(flag)) 
	{ 
		if(id == desc[i]->Getid()) 
		{ 
			flag=0; 
		} 
		else 
		{ 
			i++; 
		} 
	} 
	if(flag) 
	{ 
		cout<<"帐号不存在!"<<endl<<endl; 
		return; 
	} 
	for(int j=i;j<Sum;j++) 
	{ 
		desc[j]=desc[j+1]; 
	} 
	desc[Sum-1]=NULL; 
	Sum--; 
	cout<<"注销成功!!"<<endl<<endl; 
	Save();
	cin.get();
	return; 
} 
void man::change_()
{
	string pwd,repwd;
	cout<<"请输入新密码：";
	cin>>pwd;
	cout<<"请再确认一次新密码：";
	cin>>repwd;
	if(pwd!=repwd)
	cout<<"您输入的两次密码不一样,请重新输入!"<<endl;
	else{
	passwd=pwd;
	cout<<"密码修改成功，"<<endl;cin.get(); 	}
}
void man::getmon()
{
	double m;

		cout<<endl<<"您要提取多少钱:"<<"请输入金额："<<endl ;//__page_break__
		cin>>m;

		if(money<m)
		{
			cout<<"对不起，您的余额不足，无法进行取款！"<<endl;
		}
		else
		{
			money=money-m;
			cout<<endl<<"取钱成功！"<<endl;
		}
	}

void man::Seve_()
{
	double c;
		cout<<endl<<"您要存入多少钱:"<<"请输入金额："<<endl ;
		cin>>c;

		money=money+c;
		cout<<"-------------存钱成功!"<<endl;
		cout<<"-------------按任意键返回！";
}
void man::show()
{ 
	cout<<"\t\t-------------输出用户信息-------------"<<"\n"<<endl; 
	cout<<"\t\t  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"\t\t                                  "<<endl;
	cout<<"\t\t              姓名："<<name<<endl;
	cout<<"\t\t              帐号："<<ID<<endl;
	cout<<"\t\t              余额: "<<money<<endl;
    cout<<"\t\t          电话号码: "<<number<<endl;
	cout<<"\t\t              地址: "<<address<<endl;
	cout<<"\t\t              单位: "<<place<<endl;
	cout<<"\t\t          身份证号: "<<card<<endl;
	cout<<"\t\t                                  "<<endl;
	cout<<"\t\t  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"请按任意键返回！"; 
}
void Bank::Exit()
{
	cout<<"-------------谢谢您的使用，欢迎下次使用。再见！-------------"<<endl; 
	exit(0);
}
int main()
{
	cout<<"\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"\t$                                                $"<<endl;
	cout<<"\t$           欢 迎 进 入 本 银 行 系 统           $"<<endl;
	cout<<"\t$                 请按任意键继续                 $"<<endl;
	cout<<"\t$                                                $"<<endl;
    cout<<"\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
   Bank Bank;
   Bank.Choose();
}