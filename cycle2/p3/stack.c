#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
 int top;
 char stk[100];
}S;

int main()
{
 S.top=-1;
 int i,length,c_count=0,o_count=0;
 char array[100];
 printf("Enter expression : ");
 scanf("%s",array);
 length=strlen(array);
 for(i=0;i<length;++i)
 {
  if(array[i]=='(')
    {
      S.top++;
      S.stk[S.top]='(';
      o_count++;
    }
    else if(array[i]==')')
    {
      c_count++;
      S.top--;
    }
  }
  if(S.top!=-1)
  {
    printf("\n Expression not balanced \n");
  }
  else
    printf("\n Expression balanced \n");
    
  printf("Opening parenthesis : %d  \n Clossing parenthesis : %d \n",o_count,c_count);
	return 0;
}
