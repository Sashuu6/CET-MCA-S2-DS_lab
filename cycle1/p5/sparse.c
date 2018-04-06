#include<stdio.h>
struct sparse
{
 int mat[10][10];
 int size;
}sp;

void sp_int(int,int);
void loca(int,int);

main()
{
 int m,n;
 printf("Input number of rows: ");
 scanf("%d",&m);
 printf("Input number of columns: ");
 scanf("%d",&n);
 sp_int(m,n);
 printf("The locations of non-zero elements are:-\n");
 loca(m,n);
}

void sp_int(int m,int n)
{
 int i,j;
 sp.size=0;
 printf("Input matrix:-\n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&sp.mat[i][j]);
   if(sp.mat[i][j]!=0)
   {
    sp.size++;
   }
  }
 }
}

void loca(int m,int n)
{
 int i,j,k=0;
 int locat[3][sp.size];
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   if(sp.mat[i][j]!=0)
   {
    locat[0][k]=i+1;
    locat[1][k]=j+1;
    locat[2][k]=sp.mat[i][j];
    k++;
   }
  }
 }
 for(i=0;i<3;i++)
 {
  if(i==0)
  {
   printf("row: \t");
  }
  else if(i==1)
  {
   printf("col: \t");
  }
  else
  {
   printf("val: \t");
  }
  for(j=0;j<sp.size;j++)
  {
   printf("%d \t",locat[i][j]);
  }
  printf("\n");
 }
}
