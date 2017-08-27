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
		void Set(); //���п���
		void Del(); //��������  
		void Trans(int);   //ת��
		void Enter();//����ϵͳ
		void addmoney(int,double); //���
		void Exit();    // �˳�ϵͳ
		void Choose();//ѡ��
        void Save();     //�洢��Ϣ
		void load();   // ���ܽ���
	protected:
               man *desc[20];
               static int Sum;   //�˻���
    };
int Bank::Sum=0;
Bank::Bank() //���캯��
{
}
class man:public Bank  //��Bank���м̳� 
{
	public:
		friend class Bank;
		man(int id,string Name,string PassWord,double m,string num,string car,string add,string pla) //�вι���
		{
			ID=id;name=Name;money=m;passwd=PassWord;number=num;card=car;address=add;place=pla;
		}
		man()                                             //�޲ι���
		{
		    ID=0;name='0';money=0;passwd='0';number='0';card='0';address='0';place='0';
		}
		int Getid()//ȡ��ID
		  {
		    return ID;
		  }
		void Seve_();// �洢��Ϣ
		string get_passwd()// ȡ������
		{
		   return passwd;
		}
		void show(); 
		void getmon(); //ȡǮ
		void change_();  // ������ 
		void ADD(double);  //��Ǯ 
		void Trans_(double);  //ת�� 
		double Getmon();   //����ת��
    private:
		int ID; //�����ʺ�
		string passwd; // �û�����
		string name;   // �û����� 
		double money;  //��Ǯ
		string number; //�绰
		string card;   //���֤ 
		string address;//��ַ 
		string place;  //��λ 
};
void Bank::Save()      //�洢��Ϣ
{
	ofstream ofile("�û���Ϣ.txt",ios::out);
	ofstream outfile("�û���Ϣ.txt",ios::out);
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

void Bank::load()        // ���ܽ���
{
	ifstream infile("�û���Ϣ.txt",ios::in);
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
void Bank::Trans(int x)       //ת��
{   
    int id; 
	cout<<"�������ʺ�:"; 
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
		cout<<"\t------------�ʺŲ�����!------------"<<endl<<endl; 
		return ;
	} 
   double b;
   cout<<endl<<"��������Ҫת�ʵĽ��:";
   cin>>b;
   while(b<=0)
   {
	cout<<"��������ȷ������!"<<endl;
	cout<<"��ѡ��";
	cin>>b;
   }
	if(desc[x]->Getmon()<b) 
	cout<<"������������������������������"<<endl;
	else 
	{
	desc[x]->Trans_(b);desc[i]->ADD(b);
    cout<<"ת�ʳɹ�!";
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
		cout<<endl<<"���������Ա���в�����"<<endl;
		cout<<"\t\t1 �˻���½\n"<<endl<<"\t\t2 �û�����\n"<<endl<<"\t\t3 �ʻ�ע��\n"<<endl<<"\t\t4 �˳�ϵͳ \n"<<endl;
		cout<<"���ã�����������Ҫ�ķ���";
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
	cout<<"�������ʺ�:"; 
	cin>>id; 
	int flag = 1; 
	int i = 0; 
	while((i<Sum)&&(flag)) 
	{ 
		if(id==desc[i]->Getid()) flag = 0; else i++; 
	} 
	if(flag) 
	{ 
		cout<<"���ʺŲ�����!"<<endl<<endl; 
		system("pause"); 
		return; 
	} 
	cout<<"����������:";
	string passw;
	cin>>passw;
	if(passw!=desc[i]->get_passwd()) return;
	desc[i]->show();cin.get();cin.get();
	int n;
	while(1)
	{
      	system("cls"); 
	  	cout<<"��ѡ����Ҫ���еĲ���:"<<"\n"<<endl; 
		cout<<"\t1 �û�ת�ˣ�"<<endl;
		cout<<"\t2 �û�ȡ�"<<endl;
		cout<<"\t3 ���û��"<<endl;
		cout<<"\t4 �޸����룡"<<endl;
		cout<<"\t5 �鿴��Ϣ��"<<endl;
		cout<<"\t6 �˺��˳���"<<endl;
		cout<<"��������ţ�" ;
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
	cout<<endl<<"�����뿪���ţ�";
	cin>>id;
	cout<<endl<<"�����뿪����������";
	cin>>nam;
	cout<<endl<<"�����뿪�����룺";
	cin>>passw;
	cout<<endl<<"������绰���룺";
	cin>>num;
	cout<<endl<<"���������֤�ţ�";
	cin>>car;
	cout<<endl<<"�������ַ��";
	cin>>add;
	cout<<endl<<"�����뵥λ��";
	cin>>pla;
	cout<<endl<<"�����������:";
	cin>>m;
	man * acc = new man(id,nam,passw,m,num,car,add,pla); 
	desc[Sum] = acc; 
	cout<<"�����ɹ�!"<<endl<<endl; 
	Sum++;
	Save();
	cin.get();
	return;
}
void Bank::Del()
{
	int id;
	cout<<endl<<"��������Ҫע�����ʻ���:";
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
		cout<<"�ʺŲ�����!"<<endl<<endl; 
		return; 
	} 
	for(int j=i;j<Sum;j++) 
	{ 
		desc[j]=desc[j+1]; 
	} 
	desc[Sum-1]=NULL; 
	Sum--; 
	cout<<"ע���ɹ�!!"<<endl<<endl; 
	Save();
	cin.get();
	return; 
} 
void man::change_()
{
	string pwd,repwd;
	cout<<"�����������룺";
	cin>>pwd;
	cout<<"����ȷ��һ�������룺";
	cin>>repwd;
	if(pwd!=repwd)
	cout<<"��������������벻һ��,����������!"<<endl;
	else{
	passwd=pwd;
	cout<<"�����޸ĳɹ���"<<endl;cin.get(); 	}
}
void man::getmon()
{
	double m;

		cout<<endl<<"��Ҫ��ȡ����Ǯ:"<<"�������"<<endl ;//__page_break__
		cin>>m;

		if(money<m)
		{
			cout<<"�Բ����������㣬�޷�����ȡ�"<<endl;
		}
		else
		{
			money=money-m;
			cout<<endl<<"ȡǮ�ɹ���"<<endl;
		}
	}

void man::Seve_()
{
	double c;
		cout<<endl<<"��Ҫ�������Ǯ:"<<"�������"<<endl ;
		cin>>c;

		money=money+c;
		cout<<"-------------��Ǯ�ɹ�!"<<endl;
		cout<<"-------------����������أ�";
}
void man::show()
{ 
	cout<<"\t\t-------------����û���Ϣ-------------"<<"\n"<<endl; 
	cout<<"\t\t  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"\t\t                                  "<<endl;
	cout<<"\t\t              ������"<<name<<endl;
	cout<<"\t\t              �ʺţ�"<<ID<<endl;
	cout<<"\t\t              ���: "<<money<<endl;
    cout<<"\t\t          �绰����: "<<number<<endl;
	cout<<"\t\t              ��ַ: "<<address<<endl;
	cout<<"\t\t              ��λ: "<<place<<endl;
	cout<<"\t\t          ���֤��: "<<card<<endl;
	cout<<"\t\t                                  "<<endl;
	cout<<"\t\t  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"�밴��������أ�"; 
}
void Bank::Exit()
{
	cout<<"-------------лл����ʹ�ã���ӭ�´�ʹ�á��ټ���-------------"<<endl; 
	exit(0);
}
int main()
{
	cout<<"\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"\t$                                                $"<<endl;
	cout<<"\t$           �� ӭ �� �� �� �� �� ϵ ͳ           $"<<endl;
	cout<<"\t$                 �밴���������                 $"<<endl;
	cout<<"\t$                                                $"<<endl;
    cout<<"\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
   Bank Bank;
   Bank.Choose();
}