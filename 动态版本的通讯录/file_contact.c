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
   if(con->size == con->capacity)//�����Ѵﵽ���������������ֵ
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
int find_name(pcon con,char arr[])//�����Ժ����
{
    int i = 0;
	for(i=0; i<con->size; i++)
	{
		if(strcmp(con->peo[i].name,arr)==0)
			return i;//����ҵ������������±�
	}
	return -1;//û�ҵ�
}
void add_infor(pcon con)
{
	  check_capacity(con);
	  printf("��������Ҫ���ӳ�Ա������:");
	  scanf("%s",con->peo[con->size].name);
	  printf("��������Ҫ���ӳ�Ա���Ա�:");
	  scanf("%s",con->peo[con->size].sex);
	  printf("��������Ҫ���ӳ�Ա������:");
	  scanf("%d",&con->peo[con->size].age);
	  printf("��������Ҫ���ӳ�Ա�ĵ绰:");
	  scanf("%s",con->peo[con->size].tel);
	  printf("��������Ҫ���ӳ�Ա�ĵ�ַ:");
	  scanf("%s",con->peo[con->size].addr);
	  printf("��ӳɹ�\n");
	  con->size++;
}

void del_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("ͨѶ¼�ѿ�\n");
	}
	else
	{
		int ret = 0;
		char arr[NAME_MAX]={0};
        printf("��������Ҫɾ����Ա������:");
	    scanf("%s",&arr);
		ret = find_name(con,arr);
		if(ret>=0)
		{
			strcpy((con->peo[ret].name),(con->peo[con->size-1].name));
			                                                     //������˳���޹أ�
			                        //�����һλ��ϵ�˿�������Ҫɾ������ϵ��λ�ü���
			strcpy((con->peo[ret].sex),(con->peo[con->size-1].sex));
			(con->peo[ret].age)=(con->peo[con->size-1].age);
			strcpy((con->peo[ret].tel),(con->peo[con->size-1].tel));
			strcpy((con->peo[ret].addr),(con->peo[con->size-1].addr));
			printf("ɾ���ɹ�\n");
		    con->size--;
		}
		else
		{
		    printf("û�ҵ�Ҫɾ������ϵ��\n");
		}
	}
}
void check_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("ͨѶ¼�ѿ�\n");
	}
	else
	{
		int ret = 0;
		char arr[NAME_MAX]={0};
        printf("��������Ҫ���ҳ�Ա������:");
	    scanf("%s",&arr);
		ret = find_name(con,arr);
		if(ret>=0)
		{
			 printf("���ҳɹ�\n");
			 printf("%10s %10s %10d %15s %10s\n",con->peo[ret].name,
				                    con->peo[ret].sex,
				                    con->peo[ret].age,
				                    con->peo[ret].tel,
				                    con->peo[ret].addr);
		}
		else
		{
		    printf("û�ҵ������ҵ���ϵ��\n");
		}
	}
}
void modify_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("ͨѶ¼�ѿ�\n");
	}
	else
	{
		int ret = 0;
		char arr[NAME_MAX]={0};
        printf("��������Ҫ�޸ĳ�Ա������:");
	    scanf("%s",&arr);
		ret = find_name(con,arr);
		if(ret>=0)
		{
			  printf("������������Ҫ�޸ĳ�Ա������:");
			  scanf("%s",con->peo[ret].name);
			  printf("������������Ҫ�޸ĳ�Ա���Ա�:");
			  scanf("%s",con->peo[ret].sex);
			  printf("������������Ҫ�޸ĳ�Ա������:");
			  scanf("%d",&con->peo[ret].age);
			  printf("������������Ҫ�޸ĳ�Ա�ĵ绰:");
			  scanf("%s",con->peo[ret].tel);
			  printf("������������Ҫ�޸ĳ�Ա�ĵ�ַ:");
			  scanf("%s",con->peo[ret].addr);
			  printf("�޸ĳɹ�\n");
		}
		else
		{
		    printf("û�ҵ�Ҫ�޸ĵ���ϵ��\n");
		}
	}
}
void display_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("ͨѶ¼�ѿ�\n");
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
		printf("��ӡ�ɹ�\n");
	}
}
void clear_infor(pcon con)
{
    if(con->size==0)
	{
	    printf("ͨѶ¼�ѿ�\n");
	}
	else
		con->size=0;//����ǰ�����ÿռ���
}
void sort_infor(pcon con)//ð������
{
    int i = 0;
	int j = 0;
	int flag = 0;//�Ż�ð������
	for(i=0; i<con->size-1; i++)
	{
		flag = 1;
	    for(j=0; j<con->size-1-i; j++)
		{
		    if(strcmp((con->peo[j].name),(con->peo[j+1].name))>0)//����������ĸ��������
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
	printf("����ɹ�\n");
}

void load_infor(pcon con)
{
	PEO tmp = {0};//����ÿ�ζ����ĳ�Ա��Ϣ
    FILE *pfread = fopen("contact.dat","r");
	if(NULL == pfread)
	{
	    perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while(fread(&tmp,sizeof(PEO),1,pfread))//���ļ��ж�����
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