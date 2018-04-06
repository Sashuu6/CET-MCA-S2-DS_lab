#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
  int top;
  int stk[100];
}S;
void pop()
{
 S.top--;
 printf("%d\n",S.stk[S.top]); 
}
void reverse(int top)
{
  if(top==0)
    return;
  pop();
  reverse(--top);
}
int gcd(int a,int b)
{
  if(b==0)
    return a;
   return gcd(b,a%b);
}
int main()
{
  S.top=-1;
  int i,a,b;
  printf("Enter 5 numbers\n");
  for(S.top=0;S.top<5;S.top++)
  {
    scanf("%d",&(S.stk[S.top]));
  }
  printf("Reverse is\n");
  reverse(S.top);
  printf("\n Enter two number to find gcd\n");
  scanf("%d %d",&a,&b);
   printf("gcd(%d,%d) = %d\n",a,b,gcd(a,b));
	return 0;
}
