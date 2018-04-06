#include<stdio.h>
struct game
{
 int arr[10][10];
 int cnt;
 int score;
}game[2];
void main()
{ 
 int n,i,j,k,r,c,ele,ch,diag1=0,diag2=0,row=0,col=0,flag=0;
 printf("Input n for n*n matrix: ");
 scanf("%d",&n);
 for(i=0;i<2;i++)
 {
  game[i].cnt=0;
  printf("\n Player %d :-\n",i+1);
  for(j=0;j<n;j++)
  {
   for(k=0;k<n;k++)
   {
    game[i].arr[j][k]=0;
    printf("%d \t",game[i].arr[j][k]);
   }
   printf("\n");
  }
  do
  {
   printf("Enter position of element to change (x,y): ");
   scanf("%d %d",&r,&c);
   printf("Input element: ");
   scanf("%d",&ele);
   game[i].arr[r-1][c-1]=ele;
   game[i].cnt++;
   for(j=0;j<n;j++)
   {
    for(k=0;k<n;k++)
    {
     printf("%d \t",game[i].arr[j][k]);
    }
    printf("\n");
   }
   printf("count : %d \n",game[i].cnt);
   printf("Do you want to enter more elements?yes=1:no=0 : ");
   scanf("%d",&ch);
  }
  while(ch==1);
  //for diagnal1
  for(j=0;j<n;j++)
  {
   diag1=diag1+game[i].arr[j][j];
  }
  //printf("Diagnal1 %d \n",diag1);
  //for diagnal2
  for(j=0;j<n;j++)
  {
   diag2=diag2+game[i].arr[j][n - i - 1];
  }
  //printf("Diagnal2 %d \n",diag2);
  //for rows
  for(j=0;j<n;j++)
  {
   for(k=0;k<n;k++)
   {
    row=row+game[i].arr[j][k];
   }
   if(diag1==row)
   {
    flag = 1;
   }
   else
   {
    flag = 0;
    continue;
   }
   //printf("row %d - %d \n",j+1,row);
   row=0;
  }
  //for columns
  for(j=0;j<n;j++)
  {
   for(k=0;k<n;k++)
   {
    col=col+game[i].arr[k][j];
   }
   if(diag2==col)
   {
    flag = 1;
   }
   else
   {
    flag = 0;
    continue;
   }
   //printf("col %d - %d \n",j+1,col);
   col=0;
  }
  if(flag == 1)
  {
   game[i].score=10*game[i].cnt;
   //printf("Magic Square\n");
   //printf("Score: %d %d \n",game[i].score,flag);
  }
  else
  {
   game[i].score=0;
   //printf("Not magic Square\n");
   //printf("Score: %d %d \n",game[i].score,flag);
  }
 }
 if(game[0].score>game[1].score)
 {
  if(game[1].score==0)
  {
   printf("Player 1 wins\n");
   printf("Score: %d \n",game[0].score);
  }
  else
  {
   printf("Player 2 wins\n");
   printf("Score: %d \n",game[1].score);
  } 
 }
 else if(game[0].score==game[1].score)
 {
  printf("Game Draw\n");
  printf("Score player 1: %d \n",game[0].score);
  printf("Score player 2: %d \n",game[1].score);
 }
 else
 {
  if(game[0].score==0)
  {
   printf("Player 2 wins\n");
   printf("Score: %d \n",game[1].score);
  }
  else
  {
   printf("Player 1 wins\n");
   printf("Score: %d \n",game[0].score);
  } 
 }
}
