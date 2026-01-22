#include <stdio.h>
#include <stdlib.h>

int r,f;
int que[5];

void enqueue_front()
{
    int n;
    if(f==0)
    {
        if(r==4)
        {
            printf("\n Queue is full:");
            return;
        }
        printf("\nenqueue front not possible:");
        return;
        
    }
    
    printf("Enqueue Any Value: ");
    scanf("%d",&n);
    if(f==-1)
    {
        r=f=0;
    }
    else
    {
        f--;
    }
    que[f]=n;
}

void enqueue_rear()
{
    int n;
    if(r==4)
    {   
        if(f==0)
        {   
            printf("\n Queue is full:");
            
            return;
        }
        printf("\nenqueue not possible from Rear: ");
        return;
        
    }
    
    printf("Enqueue Any Value");
    scanf("%d",&n);
    if(f==-1)
    {
        r=f=0;
    }
    else
    {
        r++;
    }
    que[r]=n;
}

void dequeue_front()
{
    if(f==-1)
    {
        printf("\nQueue is Empty: ");
        return;
    }
    
    printf("\n%d is dequeue on front:",que[f]);
    que[f]=0;
    f++;
    if(f>r)
    {
        r=f=-1;
    }
    
}

void dequeue_rear()
{
    if(f==-1)
    {
        printf("\nQueue is empty: ");
        return;
    }
    
    printf("\n%d is deueue from rear:",que[r]);
    que[r]=0;
    r--;
    if(r<f)
    {
        r=f=-1;
    }
}

void Array_show()
{
    for(int i=0; i<=4 ; i++)
    {
        printf("\t%d",que[i]);
    }
}


void queue_Show()
{
    if(f==-1)
    {
        printf("\n Queue is empty: ");\
        return;
    }
    else
    {
        printf("\nRear=>");
        
        int i;
        if(f==0)
        {
            
            for(i=0; i<=r;i++)
            {
                printf("  %d",que[i]);
            }
        }
        else
        {
            for(i=f; i<=4;i++)
            {
                printf("  %d",que[i]);
            }
            
        }
        printf("   <=front");
    }
}

void peek_rear()
{
    if(f==-1)
    {
        printf("\nQueue is empty: ");
        return;
    }
    else
    {
        printf("\n%d it's a rear peek of Queue: ",que[r]);
    }
}

void peek_font()
{
    if(f==-1)
    {
        printf("\nQueue is empty: ");
        return;
    }
    else
    {
        printf("\n%d it's a font peek of Queue: ",que[f]);
    }
}




int main()
{
    
    r=f=-1;
    int ch;
    do
    {
        printf("\nQueue All Operation\n1.Enqueue_front\n2.enqueue_rear");
        printf("\n3.dequeue_fornt\n4.deueue_rear\n5.Show_Array\n6.peek_font");
        printf("\n7.peek_rear\n8.Show Queue\n0.exit\n ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: enqueue_front(); break;
            case 2: enqueue_rear(); break;
            case 3: dequeue_front(); break;
            case 4: dequeue_rear(); break;
            case 5: Array_show(); break;
            case 6: peek_font(); break;
            case 7: peek_rear(); break;
            case 8: queue_Show(); break;
            case 0: exit(0);
        }
    }while(1);

    return 0;
}

