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
