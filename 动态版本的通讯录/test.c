#define _CRT_SECURE_NO_WARNINGS 1
#include"file_contact.h"


void menu()
{
    printf("1.������ϵ��        2.ɾ����ϵ��\n");
	printf("3.������ϵ��        4.�޸���ϵ��\n");
	printf("5.��ʾ������ϵ��    6.���������ϵ��\n");
	printf("7.����������ϵ��    0.�˳�\n");
}
int main()
{
	int input = 1;
	CONTACT ppcon={0};
	init_contact(&ppcon);
	while(input)
	{
	    menu();
		printf("������ѡ��:>");
		scanf("%d",&input);
		switch(input)
		{
		case  ADD:
			  add_infor(&ppcon);
			  break;
        case  DEL:
			 del_infor(&ppcon);
			  break;
	    case  CHECK:
			  check_infor(&ppcon);
			  break;
	    case  MODIFY:
			  modify_infor(&ppcon);
			  break;
		case  DISPLAY:
			  display_infor(&ppcon);
			  break;
		case  CLEAR:
			  clear_infor(&ppcon);
			  break;
		case  SORT:
			  sort_infor(&ppcon);
			  break;
		case  EXIT:
			  save_infor(&ppcon);
			  free(ppcon.peo);
			  ppcon.peo=NULL;
			  exit(0);
			  break;
		default:
			printf("����ѡ���������������:>");
              break;
		}
	}
	system("pause");
	return 0;
}