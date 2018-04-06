#include <stdio.h>

void swap(int*,int*);
void bubblesort(int[],int);
void printarray(int[],int);
void search(int[],int);

main()
{
 int ch,m,a[10],i,ch1;
 printf("Input number of elements of array: ");
 scanf("%d",&m);
 printf("Input array:-\n");
 for(i=0;i<m;i++)
 {
  scanf("%d",&a[i]);
 }
 do
 {
  printf("Menu Driven Program:-\n");
  printf("1. Sort\n");
  printf("2. Search\n");
  printf("Enter choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: bubblesort(a,m);
           break;
   case 2: search(a,m);
           break;
  }
 printf("Do you wish to comtinue?? yes=1 && no 0 : ");
 scanf("%d",&ch1);
 }
 while(ch==1);
 printf("Thank you for using \n");
}

void swap(int *xp, int *yp)
{
 int temp = *xp;
 *xp = *yp;
 *yp = temp;
}

void bubblesort(int arr[], int n)
{
 int i, j;
 for (i = 0; i < n-1; i++)      
 {
  for (j = 0; j < n-i-1; j++) 
  {
   if (arr[j] > arr[j+1])
   swap(&arr[j], &arr[j+1]);
  }
 }
 printf("Sorted array:-\n");
 printarray(arr,n);
}

void printarray(int arr[], int size)
{
 int i;
 for (i=0; i < size; i++)
 {    
  printf("%d ",arr[i]);
 }
 printf("\n");
}

void search(int arr[],int n)
{
 int ele,cnt=0,pos[20],i,j=0;
 printf("Enter element to be searched: ");
 scanf("%d",&ele);
 for(i=0;i<n;i++)
 {
  if(ele==arr[i])
  {
   cnt++;
   pos[j]=i+1;
   j++;
  }
 }
 if(cnt==0)
 {
  printf("Element not found\n");
 }
 else
 {
  printf("The element has appeared %d times. Elements are found at position ",cnt);
  for(i=0;i<cnt;i++)
  {
   printf("%d ",pos[i]);
  }
 }
 printf("\n");
}
