#include<stdio.h>
main()
{
 int arr[10][10],m,n,ele,cnt=0,pos_row[100],pos_col[100],i,j,k=0;
 printf("Enter number of rows: ");
 scanf(" %d",&m);
 printf("Enter number of columns: ");
 scanf(" %d",&n);
 printf("Enter elements:- \n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&arr[i][j]);
  }
 }
 printf("Enter element to be searched: ");
 scanf("%d",&ele);
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   if(ele==arr[i][j])
   {
    cnt++;
    pos_row[k]=i+1;
    pos_col[k]=j+1;
    k++;
   }
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
   printf("(%d , %d) ",pos_row[i],pos_col[i]);
  }
 }
 printf("\n");
}
