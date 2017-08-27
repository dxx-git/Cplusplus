#define _CRT_SECURE_NO_WARNINGS 1
#include"file_contact.h"


void menu()
{
    printf("1.增加联系人        2.删除联系人\n");
	printf("3.查找联系人        4.修改联系人\n");
	printf("5.显示所有联系人    6.清空所有联系人\n");
	printf("7.排序所有联系人    0.退出\n");
}
int main()
{
	int input = 1;
	CONTACT ppcon={0};
	init_contact(&ppcon);
	while(input)
	{
	    menu();
		printf("请输入选择:>");
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
			printf("输入选择错误，请重新输入:>");
              break;
		}
	}
	system("pause");
	return 0;
}