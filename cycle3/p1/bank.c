#include<stdio.h>
#define size 5
int k=1;
struct queue
{
 int array[size],wait[20];
 int rear,front;
}m,c;

void rear(int x)
{
 static int i=1,j=1;
 if(k<=5)
 {
  if(x==1)
  {
   if(m.rear==size-1)
   {
    printf("Manager Queue is full\n");
   }
   else
   {
    if(m.rear==-1)
    {
     m.front++;
    }	
    m.rear++;
    m.array[m.rear]=i;
    printf("client%d is added to manager queue\n",i);
    i=i+1;
   }
  }
  if(x==2)
  {
   if(c.rear==size-1)
   {
    printf("Cashier queue is full\n");
   }
   else
   {
    if(c.rear==-1)
    {
     c.front++;
    }	
    c.rear++;
    c.array[c.rear]=j;
    printf("client%d is added to cashier queue\n",j);
    j=j+1;
   }
  }
  k++;
 }
 else
 {
  printf("Maximum number of clients\n");
 }	
}
	
void front(int y)
{
 if(y==2)
 {
  if(m.front==-1||m.front==size-1||m.front==m.rear+1)
  {
   printf("There is no client in manager array\n");
  }
  else
  {
   printf("Check balance ,Take out loan from the Manager of client %d is sucessful\n",(m.front+1));
   m.front++;
   k--;
   rear(2);
  }
 }
 if(y==3)
 {
  if(c.front==-1||c.front==size-1||c.front==c.rear+1)
  {
   printf("There is no client in cashier array\n");
  }
  else
  {
   printf("With Draw Money,Deposit Money and Update money from the cashier of client %d is sucessfil\n",(c.front+1));
   c.front++;
   k--;
   rear(1);
  }
 }	
}

void main()
{
 m.rear=m.front=-1;
 c.rear=c.front=-1;
 int o,n;
 do
 {
  printf("1. New Client\n");
  printf("2. Manager operation\n");
  printf("3. Cashier operation\n");
  printf("4. Exit\n");
  printf("Enter your coice\n");
  scanf("%d",&n);
  switch(n)
  {
   case 1: printf("1. Manager\n2. Cashier\n");
	   scanf("%d",&o);
	   rear(o);
	   break;
   case 2: front(2);
	   break;
   case 3: front(3);
	   break;
  }
 }
 while(n!=4);
}
