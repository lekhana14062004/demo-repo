#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[100];
    char usn[20];
    char branch[10];
    int sem;
    long int phno;
    struct node* link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("memory not available");
        return NULL;
    }
    return x;
}
NODE insertfront(NODE first)
{
    NODE temp;
    temp=getnode();
    printf("enter details");
    scanf("%s %s %s %d %ld",(temp->name),(temp->usn),(temp->branch),&(temp->sem),&(temp->phno));
    temp->link=first;
    return temp;
}
NODE insertrear(NODE first)
{
    NODE temp,cur,prev;
    temp=getnode();
    printf("enter details");
    scanf("%s %s %s %d %ld",(temp->name),(temp->usn),(temp->branch),&(temp->sem),&(temp->phno));
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    cur=first;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    return first;
}
NODE deletefront(NODE first)
{
    NODE next;
    if(first==NULL)
    {
        return first;
    }
    if(first->link==NULL)
    {
        free(first);
        return NULL;
    }
    next=first->link;
    printf("the deleted details are");
    printf("%s %s %s %d %ld",(first->name),(first->usn),(first->branch),(first->sem),(first->phno));
    next->link=first;
    free(first);
    return next;
}
NODE deleterear(NODE first)
{
    NODE cur,prev;
     if(first==NULL)
    {
        return first;
    }
    if(first->link==NULL)
    {
        free(first);
        return NULL;
    }
    prev=NULL;
    cur=first;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("deleted elem is");
      printf("%s %s %s %d %ld",(cur->name),(cur->usn),(cur->branch),(cur->sem),(cur->phno));
      free(cur);
      prev->link=NULL;
      return first;
}
void display(NODE first)
{
    NODE cur;
    cur=first;
    while(cur=NULL)
    {
        printf("%s %s %s %d %ld",(cur->name),(cur->usn),(cur->branch),(cur->sem),(cur->phno));
        cur=cur->link;
    }
     
}

int main()
{
    NODE first;
    first=NULL;
    int ch;
    printf("1.for insert front\n2.for insert rear\n2.for delete front\n4 for delete rear\n 5 for disaply");
    for(;;)
    {
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:first=insertfront(first);
            break;
            case 2:first=insertrear(first);
            break;
            case 3:first=deletefront(first);
            break;
            case 4:first=deleterear(first);
            break;
            case 5:display(first);
            break;
            default:exit(0);
        }
    }
}
  
