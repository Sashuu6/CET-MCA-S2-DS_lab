#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;
};

void insertfirst(struct Node** head_ref,int new_data)
{
 struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 new_node->data = new_data;
 new_node->next = (*head_ref);
 (*head_ref) = new_node;
}

void insertafter(struct Node** head_ref,int new_data,int position)
{
 struct Node* add = (struct Node*) malloc(sizeof(struct Node));
 add->data = new_data;
 add->next = NULL;   
 if(head_ref == NULL)
 {       
  (*head_ref) = add;
 } 
 else if(position == 0)
 {
  add->next = (*head_ref);
  (*head_ref) = add;
 }
 else
 {
  struct Node* cur = (*head_ref);
  int d = 1;
  while(cur != NULL)
  {
   if(d == position)
   {
    add->next = cur->next;
    cur->next = add;
    break;
   }
   cur = cur->next;
   d++;
  }
 }
 return;
}

void insertlast(struct Node** head_ref,int new_data)
{
 struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 struct Node *last = *head_ref;
 new_node->data = new_data;
 new_node->next = NULL;
 if(*head_ref == NULL)
 {
  *head_ref = new_node;
  return;
 }
 while(last->next != NULL)
 {
  last = last->next;
 }
 last->next = new_node;
 return;
}

void printlist(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\n");
}

int main()
{
 struct Node* head = NULL;
 int ch,d1,d2,ch2;
 do
 {
  printf("Linked List Operations:- \n");
  printf("1. Insertion\n");
  printf("2. Deletion\n");
  printf("Do you want to continue? Y=1 : N=0 -> ");
  scanf("%d",&ch2);
 }
 while(ch2==1);
 /*
 do
 {
  printf("Linked List Insertion Operations:- \n");
  printf("1. Insertion (FRONT) \n");
  printf("2. Insertion (At a location) \n");
  printf("3. Insertion (END) \n");
  printf("4. Display \n");
  printf("Enter choice: ");
  scanf("%d",&ch);
  switch(ch)
  { 
   case 1: printf("Input number: ");
   	   scanf("%d",&d1); 
   	   insertfirst(&head,d1);
   	   printlist(head);
   	   break;
   case 2: printf("Input number: ");
   	   scanf("%d",&d1);
   	   printf("Input position: ");
   	   scanf("%d",&d2); 
   	   insertafter(&head,d1,d2);
   	   printlist(head);
   	   break;
   case 3: printf("Input number: ");
   	   scanf("%d",&d1); 
   	   insertlast(&head,d1);
   	   printlist(head);
   	   break;	
   case 4: printlist(head);
   	   break;
   default: printf("ERROR 2: Choice invalid");
   	    break;   
  }
  printf("Do you want to continue? Y=1 : N=0 -> ");
  scanf("%d",&ch2);
 }
 while(ch2==1);
 */
 return 0;
}
