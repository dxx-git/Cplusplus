#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include<stdio.h>
#include<stdlib.h>
enum STATE
{
   NUL_STATE,
   C_STATE,
   CPP_STATE,
   END_STATE
};

void comment_convert(FILE* pfwrite,FILE* pfread);
void DO_NULL_STATE(FILE* pfwrite,FILE* pfread,enum STATE *state);
void DO_C_STATE(FILE* pfwrite,FILE* pfread,enum STATE *state);
void DO_CPP_STATE(FILE* pfwrite,FILE* pfread,enum STATE *state);

#endif //__COMMENT_CONVERT_H__