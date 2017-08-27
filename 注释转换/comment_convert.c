#define _CRT_SECURE_NO_WARNINGS 1
#include"comment_convert.h"
void comment_convert(FILE* pfwrite,FILE* pfread)
{
	enum STATE state = NUL_STATE;
	while(state != END_STATE)
	{
		switch(state)
		{
	      case NUL_STATE:
			  DO_NULL_STATE(pfwrite,pfread,&state);
			  break;
		  case C_STATE:
			  DO_C_STATE(pfwrite,pfread,&state);
			  break;
		  case CPP_STATE:
			  DO_CPP_STATE(pfwrite,pfread,&state);
			  break;
		  case END_STATE:
			  break;
		  default:
			  break;
		}
	}
}
void DO_NULL_STATE(FILE* pfwrite,FILE* pfread,enum STATE *state)
{
    int first = 0;
	int second = 0;
	first = fgetc(pfread);
	switch(first)
	{
	case '/':
		{
			second = fgetc(pfread);
			switch(second)
			{
				case '/':
					{
						fputc(first,pfwrite);
						fputc(second,pfwrite);
						*state = CPP_STATE;
					}
				    break;
				case '*':
					{
						fputc('/',pfwrite);
						fputc('/',pfwrite);
						*state = C_STATE;
					}
					break;
				default:
					fputc(first,pfwrite);
					fputc(second,pfwrite);
					break;
			}
		}
		break;
	/*case '\n':
		fputc('\n',pfwrite);
		break;*/
	case EOF:
		  *state = END_STATE;
		break;
	default:
		fputc(first,pfwrite);
		break;
	}
}

void DO_C_STATE(FILE* pfwrite,FILE* pfread,enum STATE *state)
{
    int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfread);
	switch(first)
	{
	case '*':
		second = fgetc(pfread);
		switch(second)
		{
		case '/':
			{
			    third = fgetc(pfread);
				if(third=='\n')
					fputc('\n',pfwrite);
				else
					fputc('\n',pfwrite);
				*state = NUL_STATE;
			}
			break;
		case '*':
			{
				third = fgetc(pfread);
				fputc(first,pfwrite);
				if(third=='/')
					*state = NUL_STATE;
			}
			break;
		default:
			fputc(first,pfwrite);
			fputc(second,pfwrite);
			break;
		}
		break;
	case '\n':
		fputc('\n',pfwrite);
		fputc('/',pfwrite);
		fputc('/',pfwrite);
		break;
	case EOF:
		*state = END_STATE;
		break;
	default:
		fputc(first,pfwrite);
		break;
	}

}
void DO_CPP_STATE(FILE* pfwrite,FILE* pfread,enum STATE *state)
{
    int first = 0;
	first = fgetc(pfread);
	switch(first)
	{
	case '\n':
		{	
		    fputc('\n',pfwrite);
			*state = NUL_STATE;
		}
		break;
	case EOF:
        *state = END_STATE;
		break;
	default:
		fputc(first,pfwrite);
	}
}

