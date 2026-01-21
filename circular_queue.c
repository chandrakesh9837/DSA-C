#include <stdio.h>
#include<stdlib.h>
int r,f;
int que[5];
 
void enqueue()
{
    int n;
    if((r==4&&f==0)||(r==f-1))
    {
        printf("Queue is full");
        return;
    }
    
    printf("Enqueue any Value: ");
    scanf("%d",&n);
    if(r==-1)
    {
        r=f=0;
        
    }
    else if(r==4&&f>0)
    {
        r=0;
    }
    else
    {
        r++;
    }
    que[r]=n;
}

void dequeue()
{
    if(f==-1)
    {
        printf("%d Queue is Empty");
        return;
    }
    printf("%d is dequeue: ",que[f]);
    que[f]=0;
    
    if(f==4&&r<f)
    {
        f=0;
    }
    else if(f==r)
    {
        r=f=-1;
    }
    else
    {
        f++;
    }
}

void peek()
{
    if(f!=-1)
    {
        printf("\n%d it's peek element of queue:",que[f]);
    }
    else
    {
        printf("\nQueue is empty: ");
    }
}

void showQueue()
{
    if(f==-1||f==r)
    {
        printf("\nqueue is empty");
    }
    else if(f>r)
    {
        int i;
        printf("\nFront=>\t");
        for( i=f; i<=5; i++)
        {
            printf("%d\t",que[i]);
        }
        for(i=0;i<=r; i++)
        {
            printf("%d\t",que[i]);
        }
        printf("<=Rear");
    }
    else
    {
        int i;
        printf("\nFront=>\t");
        for( i=f; i<=r; i++)
        {
            printf("%d\t",que[i]);
        }
        printf("<=Rear");
    }
}

void showArray()
{
    printf("\nShow Arrays:\n");
    for(int i=0; i<=4; i++)
    {
        printf("\t%d",que[i]);
    }
}


int main()
{
    r=f=-1;
    do
    {   int ch;
        printf("\n\nQueue All Operation\n1.Enqueue Value\n2.Dequeue Value\n3.peek Queue\n4.Display Queue\n5.Display Array\n  ");  
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: showQueue(); break;
            case 5: showArray(); break;
            case 0: exit(0);
        }
    }while(1);
}
