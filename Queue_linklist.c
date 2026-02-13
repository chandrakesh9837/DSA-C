#include <stdio.h>
#include <stdlib.h>

typedef struct ele 
{
    int data ;
    struct ele*next;
}ele;

ele *front, *rear;

void enqueue()
{
    ele *node;
    node=(ele*)malloc(sizeof(ele));
    scanf("%d",&node->data);
    node->next=NULL;
    if(front==NULL)
    {
        front=rear=node;
    }
    else
    {
        rear->next=node;
        rear=node;
    }
}

void dequeue()
{
    ele *cur;
    if(front==NULL)
    {
        printf("\nQueue is empty: ");
        return;
    }
    else
    {
        cur=front;
        front=front->next;
        cur->next=NULL;
        printf("\n%d is deueue ",cur->data);
        free(cur);
    }
}

void Show_Queue()
{
    ele *cur;
    if(front==NULL)
    {
        printf("Queue is empty: ");
        return;
    }
    else
    {
    printf("Front ==>");
    }
    for(cur=front; cur!=NULL; cur=cur->next)
    {
        printf("  %d ==>",cur->data);
    }
    printf("Rear");
}

void peak()
{
    
    if(front==NULL)
    {
        printf("\n Queue is empty: ");
        return;
    }
    printf("\n%d is at front",front->data);
}

int main()
{
    front=rear=NULL;
    int ch;
    do
    {
        printf("\n\n\nQueue Operation:\n1.Enqueue\n2.dequeue\n3.Show Queue\n4.Peek\n0.exit\nEnter your choice ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: Show_Queue(); break;
            case 4: peak(); break;
            
        }
    }while(ch!=0);
    
    
    return 0;
}
