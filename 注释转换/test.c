#define _CRT_SECURE_NO_WARNINGS 1
#include"comment_convert.h"

int main()
{
	FILE *pfread = NULL;
	FILE *pfwrite = NULL;
	pfread = fopen("input.c","r");
	if(NULL == pfread)
	{
	    printf("open input.c");
		exit(EXIT_FAILURE);
	}
	pfwrite = fopen("output.c","w");
	if(NULL == pfwrite)
	{
	    printf("open input.c");
		fclose(pfread);
		exit(EXIT_FAILURE);
	}
	comment_convert(pfwrite,pfread);
	printf("×ª»»³É¹¦£¡\n");
	fclose(pfread);
	fclose(pfwrite);
    system("pause");
	return 0;
}