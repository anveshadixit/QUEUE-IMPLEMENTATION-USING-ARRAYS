#include <stdio.h>
#include<stdlib.h>
#define max 20

int isEmpty(int fr,int re)
{
    if((fr==-1||fr>re))
    {
    	fr=re=-1;
		return 1;	
	}
    else
        return 0;
}

int isFull(int re)
{
    if(re==max-1)
        return 1;
    else
        return 0;
}

void enQueue(int q[max],int*f,int*r)
{
	int x;
    if(isFull(*r))
        printf("Overflow\n");
    else
    {
    	printf("\nEnter element:");
        	scanf("%d",&x);
        (*r)++;
        if(*f==-1)
            (*f)=0;
        q[*r]=x;    
        printf("Entered element=%d\n",q[*r]);    
    }
}

int deQueue(int q[max],int*f,int*r)
{
    if(isEmpty(*f,*r))
        printf("Underflow\n");
    else
    {
        printf("Deleted Element=%d\n",q[*f]);
        q[(*f)++];
        
    }
}

void display(int q[max],int*f,int*r) 
{
    int i;
    if(isEmpty(*f,*r))
		printf("Underflow.\n");
	else
	{
    	printf("Elements of queue are:");
    	for(i=*f;i<=*r;i++)
    	printf("%d  ",q[(*f)++]);
    }
}

int main()
{
    int i, el,ch,qu[max],front=-1,rear=-1;
    while (1)
    {
        printf("\nMENU\n");
        printf("1.Insert element:\n");
        printf("2.Delete element:\n");
        printf("3.Print queue:\n");
        printf("4.EXIT:\n");
        printf("Enter choice : ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: enQueue(qu,&front,&rear);
                    break;
                    
            case 2: el=deQueue(qu,&front,&rear);
                    break;
                    
            case 3: display(qu,&front,&rear);  
                    break;
                    
            case 4: printf("Exiting.");
                    exit(0);
                    
            default: printf("Invalid Choice.");
        }
    }
    return 0;
}
