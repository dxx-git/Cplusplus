#define _CRT_SECURE_NO_WARNINGS 1
#include"file_contact.h"


void init_contact(pcon con)
{
	con->peo = (PEO*)malloc(sizeof(PEO)*PRESENT_CAPACITY);
	memset(con->peo,0,sizeof(PEO)*PRESENT_CAPACITY);
	if(NULL == con->peo)
	{
	    printf("out of memory.\n");
		exit(1);
	}
	con->size = 0;
	con->capacity = PRESENT_CAPACITY;
	load_infor(con);
}

void check_capacity(pcon con)
{
   if(con->size == con->capacity)//容量已达到可容纳人数的最大值
   {
       PEO *tmp = (PEO*)realloc(con->peo,(con->capacity+ENLARGE_CAPACITY)*sizeof(PEO));
	   memset(con->peo,0,sizeof(con->capacity+ENLARGE_CAPACITY));
	   if(tmp == NULL)
	   {
	       printf("out of memory.\n");
		   exit(1);
	   }
	   else
	   {
	        con->peo = tmp;
		    con->capacity += ENLARGE_CAPACITY;
	   }
   }
}
int find_name(pcon con,char arr[])//方便以后查找
{
    int i = 0;
	for(i=0; i<con->size; i++)
	{
		if(strcmp(con->peo[i].name,arr)==0)
			return i;//如果找到，返回所在下标
	}
	return -1;//没找到
}
void add_infor(pcon con)
{
	  check_capacity(con);
	  printf("请输入你要增加成员的名字:");
	  scanf("%s",con->peo[con->size].name);
	  printf("请输入你要增加成员的性别:");
	  scanf("%s",con->peo[con->size].sex);
	  printf("请输入你要增加成员的年龄:");
	  scanf("%d",&con->peo[con->size].age);
	  printf("请输入你要增加成员的电话:");
	  scanf("%s",con->peo[con->size].tel);
	  printf("请输入你要增加成员的地址:");
	  scanf("%s",con->peo[con->size].addr);
	  printf("添加成功\n");
	  con->size++;
}

void del_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("通讯录已空\n");
	}
	else
	{
		int ret = 0;
		char arr[NAME_MAX]={0};
        printf("请输入你要删除成员的名字:");
	    scanf("%s",&arr);
		ret = find_name(con,arr);
		if(ret>=0)
		{
			strcpy((con->peo[ret].name),(con->peo[con->size-1].name));
			                                                     //由于与顺序无关，
			                        //将最后一位联系人拷贝到需要删除的联系人位置即可
			strcpy((con->peo[ret].sex),(con->peo[con->size-1].sex));
			(con->peo[ret].age)=(con->peo[con->size-1].age);
			strcpy((con->peo[ret].tel),(con->peo[con->size-1].tel));
			strcpy((con->peo[ret].addr),(con->peo[con->size-1].addr));
			printf("删除成功\n");
		    con->size--;
		}
		else
		{
		    printf("没找到要删除的联系人\n");
		}
	}
}
void check_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("通讯录已空\n");
	}
	else
	{
		int ret = 0;
		char arr[NAME_MAX]={0};
        printf("请输入你要查找成员的名字:");
	    scanf("%s",&arr);
		ret = find_name(con,arr);
		if(ret>=0)
		{
			 printf("查找成功\n");
			 printf("%10s %10s %10d %15s %10s\n",con->peo[ret].name,
				                    con->peo[ret].sex,
				                    con->peo[ret].age,
				                    con->peo[ret].tel,
				                    con->peo[ret].addr);
		}
		else
		{
		    printf("没找到所查找的联系人\n");
		}
	}
}
void modify_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("通讯录已空\n");
	}
	else
	{
		int ret = 0;
		char arr[NAME_MAX]={0};
        printf("请输入你要修改成员的名字:");
	    scanf("%s",&arr);
		ret = find_name(con,arr);
		if(ret>=0)
		{
			  printf("请重新输入你要修改成员的名字:");
			  scanf("%s",con->peo[ret].name);
			  printf("请重新输入你要修改成员的性别:");
			  scanf("%s",con->peo[ret].sex);
			  printf("请重新输入你要修改成员的年龄:");
			  scanf("%d",&con->peo[ret].age);
			  printf("请重新输入你要修改成员的电话:");
			  scanf("%s",con->peo[ret].tel);
			  printf("请重新输入你要修改成员的地址:");
			  scanf("%s",con->peo[ret].addr);
			  printf("修改成功\n");
		}
		else
		{
		    printf("没找到要修改的联系人\n");
		}
	}
}
void display_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("通讯录已空\n");
	}
	else
	{
		int i = 0;
	    for(i=0; i<con->size; i++)
		{
		    printf("%10s %10s %10d %15s %10s\n",con->peo[i].name,
				                    con->peo[i].sex,
				                    con->peo[i].age,
				                    con->peo[i].tel,
				                    con->peo[i].addr);
		}
		printf("打印成功\n");
	}
}
void clear_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("通讯录已空\n");
	}
	else
		con->size=0;//将当前人数置空即可
}
void sort_infor(pcon con)//冒泡排序
{
    int i = 0;
	int j = 0;
	int flag = 0;//优化冒泡排序
	for(i=0; i<con->size-1; i++)
	{
		flag = 1;
	    for(j=0; j<con->size-1-i; j++)
		{
		    if(strcmp((con->peo[j].name),(con->peo[j+1].name))>0)//按名字首字母升序排列
			{
				
				PEO tmp=con->peo[j];
				con->peo[j]=con->peo[j+1];
				con->peo[j+1]=tmp;
				flag = 0;
			}
		}
		if(flag==1)
			break;
	}
	printf("排序成功\n");
}

void load_infor(pcon con)
{
	PEO tmp = {0};//保存每次读到的成员信息
    FILE *pfread = fopen("contact.dat","r");
	if(NULL == pfread)
	{
	    perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while(fread(&tmp,sizeof(PEO),1,pfread))//从文件中读数据
	{
	    check_capacity(con);
		con->peo[con->size++] = tmp;
	}
	fclose(pfread);
}
void save_infor(pcon con)
{
	int i = 0;
    FILE *pfwrite = fopen("contact.dat","w");
	if(NULL == pfwrite)
	{
	    perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<con->size; i++)
	{
	    fwrite(&con->peo[i],sizeof(PEO),1,pfwrite);
	}
	fclose(pfwrite);
}