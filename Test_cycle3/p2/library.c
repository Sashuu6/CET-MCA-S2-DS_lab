#include <stdio.h>
#include <malloc.h>
#include <time.h>

struct BOOKS
{
    char title[100];
    int ac_num,tag;
    struct BOOKS *ptr;
}*bhead;

struct BOOKS* createln()
{
    int i=1;
    typedef struct BOOKS NODE;
    NODE *head, *first, *temp = NULL;
    head  = (NODE *)malloc(sizeof(NODE));
    head->ac_num=0;
    head->tag=0;
    temp = head;
    printf("\nEnter data items : ");

    do
    {
        first  = (NODE *)malloc(sizeof(NODE));
printf("\nEnter name : ");
        scanf("%s", first->title);
printf("\nAccession number : ");
        scanf("%d", &first->ac_num);
	first->tag=1;
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
    while (temp != NULL)
    {
        printf("%s -> %d -> ", temp->title,temp->ac_num);
        temp = temp -> ptr;
    }
    printf("NULL\n");
}

{
int day[5],mon[5],year[5];
};
struct SUBSCRIBERS
{
    char name[100];
    int b_num,ac_num[5],count,date[5];
    struct date issue;
    struct SUBSCRIBERS *ptr;
}*shead;

void main()
{
bhead = createln();
println(bhead);
time_t t = time(NULL);
struct tm tm = *localtime(&t);

printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
}
