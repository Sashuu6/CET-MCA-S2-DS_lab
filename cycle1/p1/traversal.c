#include<stdio.h>
main()
{
 int arr[20],n,ele,cnt=0,pos[20],i,j=0;
 printf("Enter number of elements: ");
 scanf(" %d",&n);
 printf("Enter elements:- \n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 printf("Elements are:- \n");
 for(i=0;i<n;i++)
 {
  printf("%d\t",arr[i]);
 }
 printf("\n");
}
