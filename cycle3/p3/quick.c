#include<stdio.h>

void swap(int* x, int* y)
{
 int z=*x;
 *x=*y;
 *y=z;
}

int split(int arr[],int low,int up)
{
 int pivot=arr[up];  
 int i=(low - 1); 
 int j; 
 for(j=low;j<=up-1;j++)
 {
  if (arr[j]<=pivot)
  {
   i++;   
   swap(&arr[i],&arr[j]);
  }
 }
 swap(&arr[i+1],&arr[up]);
 return i+1;
}

void quick(int arr[],int low,int up)
{
 if(low<up)
 {
  int pi=split(arr,low,up);
  quick(arr,low,pi-1);
  quick(arr,pi + 1,up);
 }
}

void print(int arr[],int n)
{
 int i;
 for(i=0;i<n;i++)
 printf("%d\n",arr[i]);
}

void main()
{
 int arr[100],i,n; 
 printf("enter the number of elements\n");
 scanf("%d",&n);
 printf("enter the array\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 } 
 quick(arr,0,n-1);
 printf("Sorted array:\n");
 print(arr,n);
}
