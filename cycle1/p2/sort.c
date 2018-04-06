#include <stdio.h>

void swap(int*,int*);
void bubblesort(int[],int);
void printarray(int[],int);

main()
{
 int m,a[10],i;
 printf("Input number of elements of array: ");
 scanf("%d",&m);
 printf("Input array:-\n");
 for(i=0;i<m;i++)
 {
  scanf("%d",&a[i]);
 }
 bubblesort(a,m);
 printf("Sorted array:-\n");
 printarray(a,m);
}

void swap(int *xp,int *yp)
{
 int temp = *xp;
 *xp = *yp;
 *yp = temp;
}

void bubblesort(int arr[],int n)
{
 int i, j;
 for(i=0;i<n-1;i++)      
 {
  for(j=0;j<n-i-1;j++) 
  {
   if(arr[j]>arr[j+1])
   swap(&arr[j], &arr[j+1]);
  }
 }
}

void printarray(int arr[],int size)
{
 int i;
 for(i=0;i<size;i++)
 {    
  printf("%d ",arr[i]);
 }
 printf("\n");
}
