#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = 0;       // global declaration

struct node *createNode()
{
    struct node *h1;
    h1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d",&h1->data);
    h1->next = 0;
    return h1;
}

void insertStart()
{
    struct node *k1;
    k1 = createNode();
    if(start == 0)
    {
        start = k1;
    }    
    else
    {
        k1->next = start;
        start = k1;
    }
}

void insertEnd()
{
    struct node *c1;
    c1 = createNode();
    if (start==0)
    {
        start = c1;
    }
    else
    {
        struct node *b1;
        b1 = start;
        while (b1->next != 0)
        {
            b1 = b1->next;
        }
        b1->next = c1;
        
    }
    
}

void insertMiddle()
{
    struct node *h1,*a1;
    h1 = createNode();
    if (start == 0)
    {
        start = h1;
    }
    else
    {
        int d;
        printf("Enter a data where you want to insert: ");
        scanf("%d",&d);

        a1 = start;
        while (a1->next->data != d)
        {
            a1 = a1->next;
        }
        h1->next = a1->next;
        a1->next = h1;
        
    }
}

void deleteStart()
{
        struct node *y1;
    if (start==0)
    {
        printf("There is no any node to delete.");
    }
    else
    {
        y1 = start;
        start = start->next;
        y1->next = 0;
        free(y1);

    }
    

}

void deleteEnd()
{
    struct node *f1,*p1;
    if (start==0)    // Empty list case
    {
        printf("There is no any node to delete.");
    }
    else if (start->next == 0)  // Only one node case
    {
        free(start);
        start = 0;
    }
    else       // More than one node case
    {
        f1 = start;
        while(f1->next->next != 0)
        {
            f1 = f1->next;
        }
        p1 = f1->next;
        f1->next = 0;
        free(p1);
    }
    
}

void deleteMiddle()
{
    struct node *s1,*b1;
    if (start == 0)
    {
        printf("There is no any node to delete.");
    }
    else
    {
        s1 = start;
        int w;
        printf("Enter a data you want to delete: ");
        scanf("%d",&w);

        while (s1->next->data != w)
        {
            s1 = s1->next;
        }
        b1 = s1->next;
        s1->next = s1->next->next;
        b1->next = 0;
        free(b1);
        
    }
    
}

void display()
{
    if (start == 0)
    {
        printf("There is no any node to display.");
    }
    
    struct node *j1;
    j1 = start;

    while(j1 != 0)
    {
        printf("%d   ",j1->data);
        j1 = j1->next;
    }
}








int main(){
    int ch;

    printf("\n1. Insert at the start");
    printf("\n2. Insert at the end");
    printf("\n3. Insert at a specific position");
    printf("\n4. Delete from the start");
    printf("\n5. Delete from the end");
    printf("\n6. Delete from a specific position");
    printf("\n7. Display the list");
    printf("\n8. Exit");


    while (1)
    {

    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);


    switch (ch)
    {
    case 1:
        {
            insertStart();
            break;
        }
    case 2:
        {
            insertEnd();

            break;
        }
    case 3:
        {
            
            insertMiddle();
            break;
        }
    case 4:
        {
            deleteStart();
            break;
        }
    case 5:
        {

            deleteEnd();
            break;
        }
    case 6:
        {

            deleteMiddle();
            break;
        }
    case 7:
        {
            display();
            break;
        }
    case 8:
        {

            exit (0);
        }
    default:
        {
            printf("Wrong input");
        }
    }

    }
    
    return 0;
}