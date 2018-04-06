#include <stdio.h>

void swap(int*,int*);
void bubblesort(int[],int);
void merge(int[],int[],int,int);
void printarray(int[],int);
main()
{
 int m,n,a[10],b[10],i,j;
 printf("Input number of elements of array 1: ");
 scanf("%d",&m);
 printf("Input number of elements of array 2: ");
 scanf("%d",&n);
 printf("Input array 1 :-\n");
 for(i=0;i<m;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Input array 2 :-\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&b[i]);
 }
 bubblesort(a,m);
 printf("Sorted array 1:-\n");
 printarray(a,m);
 bubblesort(b,n);
 printf("Sorted array 2:-\n");
 printarray(b,n);
 merge(a,b,m,n);
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
}

void merge(int arr[],int arr1[],int m,int n)
{
 int arr11[20],i,j;
 for(i=0;i<m;i++)
 {
  arr11[i]=arr[i];
 }
 for(i=m,j=0;i<m+n,j<n;i++,j++)
 {
  arr11[i]=arr1[j];
 }
 printf("Merged array:-\n");
 printarray(arr11,m+n);
 bubblesort(arr11,m+n);
 printf("Merged and sorted array:-\n"); 
 printarray(arr11,m+n);
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
