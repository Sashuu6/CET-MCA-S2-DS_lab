#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,SIZE,array[100];
int isFull()
{
 if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) 
 {
  return 1;
 }
 return 0;
}

int isEmpty()
{
 if(front==-1) 
 {
  return 1;
 }
 return 0;
}

void insert(int element)
{
 if(isFull()) 
 {
  printf("\n Queue overflow \n");
 }
 else
 {
  if(front == -1) 
  {
   front = 0;
  } 
  rear = (rear + 1) % SIZE;
  array[rear] = element;
 }
}

void print()
{
 int i,j;
 j=front;
 for(i=0;i<SIZE;++i)
 {
  printf("%d ",array[j]);
  j=(j+1)%SIZE;	
 }
}

main()
{
 int i,n,k,item,j,l,m,nn=0,temp;	
 printf("Enter N and K\n");
 scanf("%d %d",&n,&k);
 SIZE=n;
 printf("Enter numbers\n");
 for(i=0;i<n;++i)
 {
  scanf("%d",&item);
  insert(item);
 }
 j=front-1;
 l=SIZE-1;
 temp=k;
 for(i=0;i<l;++i)
 {
  temp=1;
  printf("Pass - %d : ",i+1);
  print();
  printf("\n");
  while(temp<=k)
  {
   
   j=(j+1)%SIZE;
   if(nn==SIZE-1)
   {
    break;
   }
   if(array[j]==0)
   {
    continue;
   }
   if(temp==k)
   {
    array[j]=0;
   }
   ++temp;
  }
  ++nn;
 }
 printf("Final result: ");
 print();
 printf("\n");
}
