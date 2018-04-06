#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include<string.h>
struct BOOKS{
	char title[100];
	int ac_num,tag;
	struct BOOKS *ptr;
}*bhead;
struct date{
	int day[5],mon[5],year[5];
};
struct SUBSCRIBERS{
	char name[100];
	int b_num,ac_num[5],count;
	struct date issue[5];
	struct SUBSCRIBERS *ptr;
}*shead;
struct BOOKS* createln(){
	int i=1;
	typedef struct BOOKS NODE;
	NODE *head, *first, *temp = NULL;
	head  = (NODE *)malloc(sizeof(NODE));
	head->ac_num=0;
	head->tag=0;
	temp = head;
	printf("\nEnter data items : ");
	do{
		first  = (NODE *)malloc(sizeof(NODE));
		printf("\nEnter name : ");
		scanf("%s", first->title);
		printf("\nAccession number : ");
		scanf("%d", &first->ac_num);
		first->tag=0;
		temp->ptr = first;
		temp = first;
		printf("\nenter 1 to continue");
		scanf("%d", &i);
	}while(i==1);
	temp->ptr = NULL;
	return head;
}
void println(struct BOOKS *bhead){
	struct BOOKS *temp;
	temp = bhead->ptr;
	printf("\nLinked list is : \n\n");
	while (temp != NULL){
		printf("%s -> %d -> %d->", temp->title,temp->ac_num,temp->tag);
		temp = temp -> ptr;
	}
	printf("NULL\n");
}
void println2(struct SUBSCRIBERS *shead){
	struct SUBSCRIBERS *temp;
	temp = shead->ptr;
	printf("\nLinked list is : \n\n");
	while (temp != NULL){
		printf("%s -> %d-%d-%d -> %d ->", temp->name,temp->issue[temp->count].day[temp->count],temp->issue[temp->count].mon[temp->count],
		temp->issue[temp->count].year[temp->count],temp->ac_num[temp->count]);
		temp = temp -> ptr;
	}
	printf("NULL\n");
}
int check(int a){
	int t=0;
	struct BOOKS *temp;
	temp = bhead->ptr;
	while(temp !=NULL){
		if(temp->tag==0 && temp->ac_num==a)
			t=1;
		temp=temp->ptr;
	}
	return t;
}
void issueBook(int brnum,int ac_no){
	typedef struct SUBSCRIBERS NODE;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int q,r;
	r=ac_no;
	q=check(r);
	if(q==1){
		NODE *head, *first, *temp = NULL;
		if(shead==NULL){
			head  = (NODE *)malloc(sizeof(NODE));
			temp = head;
			first  = (NODE *)malloc(sizeof(NODE));
			printf("\nEnter name : ");
			scanf("%s", first->name);
			first->b_num=brnum;
			first->count=0;
			first->ac_num[first->count]=ac_no;
			first->issue[first->count].day[first->count]=tm.tm_mday;
			first->issue[first->count].mon[first->count]=tm.tm_mon + 1;
			first->issue[first->count].year[first->count]=tm.tm_year + 1900;
			temp->ptr = first;
			temp = first;
			temp->ptr = NULL;
		}
		else{
			int key=0;
			head = shead;
			temp = head->ptr;
			while(temp != NULL){
				if(temp -> b_num == brnum ){
					key=1;
					first = temp;
				}	
				temp = temp -> ptr;
			}
			if(key==1){
				if(first->count<=4){	
					first->count=first->count+1;
					first->ac_num[first->count]=ac_no;
					first->issue[first->count].day[first->count]=tm.tm_mday;
					first->issue[first->count].mon[first->count]=tm.tm_mon + 1;
					first->issue[first->count].year[first->count]=tm.tm_year + 1900;
				}
				else
					printf("\nmaximum number of book reached\n");
			}
			else{
				head = shead;
				temp = head->ptr;
				while(temp != NULL){
					first = temp;
					temp = temp -> ptr;
				}
				temp = (NODE *)malloc(sizeof(NODE));
				printf("\nEnter name : ");
				scanf("%s", temp->name);
				temp->b_num=brnum;
				temp->count=0;
				temp->ac_num[temp->count]=ac_no;
				temp->issue[temp->count].day[temp->count]=tm.tm_mday;
				temp->issue[temp->count].mon[temp->count]=tm.tm_mon + 1;
				temp->issue[temp->count].year[temp->count]=tm.tm_year + 1900;
				first -> ptr = temp;
				temp -> ptr = NULL;
			}	
		}
		shead = head;
		struct BOOKS *temp2;
		temp2=bhead->ptr;
		while(temp2!=NULL){
			if(temp2->ac_num==ac_no)
				temp2->tag=1;
			temp2=temp2->ptr;
		}
		println2(shead);		
	}
	else
	printf("\nThe book is not available");
}
void titlecheck(int a){
	int i,key=0;
	struct SUBSCRIBERS *temp,*first;
	struct BOOKS *temp2;
	temp=shead->ptr;
	while(temp!=NULL){
		for(i=0;i<=temp->count;i++)
			if(temp->ac_num[i]==a){
				first=temp;
			}
		temp=temp->ptr;
	}
	printf("owner = %s\n",first->name);
}
void listofbook(int b)
{
	int key=0,a[5],i;
	struct SUBSCRIBERS *temp,*first;
	struct BOOKS *temp2;
	if(shead!=NULL && bhead!=NULL){
		temp=shead->ptr;
		while(temp!=NULL){
			if(temp->b_num==b){
				key=1;
				first=temp;
			}
			temp=temp->ptr;
		}
		if(key==0)
			printf("\nThe borrower is not available");
		else
			for(i=0;i<=first->count;i++){
				temp2=bhead->ptr;
				while(temp2!=NULL){
					if(temp2->ac_num==first->ac_num[i])
						printf("%s\n",temp2->title);
					temp2=temp2->ptr;
				}
			}
	}	
	else
		printf("\ninvalid input");
}
void returnBook(int a,int b){
	int x,y;
	struct SUBSCRIBERS *temp,*first;
	struct BOOKS *temp2,*f2;
	if(shead!=NULL && bhead!=NULL){
		temp = shead->ptr;
		while(temp != NULL){
			if(b==temp->b_num){
				first=temp;
				x=1;
			}
			temp = temp -> ptr;
		}
		temp2 = bhead->ptr;
		while(temp2 != NULL){
			if(a==temp2->ac_num){
				f2=temp2;
				y=1;
			}
			temp2 = temp2 -> ptr;
		}
		if(x==1 && y==1){
			first->count=first->count-1;
			f2->tag=0;
			printf("\nREturn successfull");
		}
		else
			printf("\ninvalid input");
	}
	else
		printf("\ninvalid input");
}	
void main(){
	char t[100];
	int ch,a,b,x,d,key=0;
	bhead = createln();
	println(bhead);
	do{
		printf("\nEnter your choice : \n1.issue\n2.return \n3.list of books of a subscriber\n4.Search for title\n5.exit\n");
		scanf("%d",&ch);
		if(ch==1){
			printf("\nAccession number : ");
			scanf("%d", &a);
			printf("\nborrower id : ");
			scanf("%d", &b);
			issueBook(b,a);
		}
		else if(ch==2){
			printf("\nAccession number : ");
			scanf("%d", &a);
			printf("\nborrower id : ");
			scanf("%d", &b);
			returnBook(a,b);	
		}
		else if(ch==3){
			printf("\nborrower id : ");
			scanf("%d", &b);
			listofbook(b);
		}
		else if(ch==4){
			printf("\nTitle : ");
			scanf("%s", t);
			struct BOOKS *temp,*first;
			temp=bhead->ptr;
			key=0;
			while(temp!=NULL){
				d=strcmp(t,temp->title);
				if(d==0){
					key=1;
					first=temp;
				}
				temp=temp->ptr;
			}
			if(key==1 && first->tag!=0){
				x=first->ac_num;
				titlecheck(x);
			}
			else
				printf("Title not found or the book is not yet issued\n");
		}
	}while(ch<=4);
}
