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
    struct node *k1,*p1;
    k1 = createNode();
    if (start == 0)
    {
        start = k1;
        k1->next = start; 
    }
    else
    {
        k1->next = start;
        p1 = start;
        while (p1->next != start)
        {
            p1 = p1->next;
        }
        p1->next = k1;
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
        c1->next = start; 
        return;
    }

    struct node *b1;
        b1 = start;
        while (b1->next != start)
        {
            b1 = b1->next;
        }
        b1->next = c1;
        c1->next = start;

}


void insertMiddle()
{
    struct node *h1,*a1;
    h1 = createNode();
    if (start == 0)
    {
        start = h1;
        h1->next = start;
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
    struct node *g1;

    if (start == 0)
    {
        printf("There is no any node to delete.");
        return;
    }

    if (start->next == start) // Only one node in the list
    {
        free(start);
        start = 0;
        return;
    }

    g1 = start;
    while (g1->next != start) 
    {
        g1 = g1->next;
    }

    g1->next = start->next; 
    struct node *temp = start; 
    start = start->next; 
    free(temp); 
}


void deleteEnd()
{
    struct node *b1, *prev;

    //  Empty list
    if (start == 0)
    {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    // single node in the list
    if (start->next == start)
    {
        free(start);
        start = 0; 
        return;
    }

    b1 = start;
    while (b1->next != start) 
    {
        prev = b1; 
        b1 = b1->next;
    }

    prev->next = start; 
    free(b1);          
}



void deleteMiddle()
{
    struct node *s1, *b1;
    int w;

    if (start == 0) // Empty list
    {
        printf("There is no node to delete.\n");
        return;
    }

    printf("Enter the data you want to delete: ");
    scanf("%d", &w);

    // Single node in the list
    if (start->next == start && start->data == w)
    {
        free(start);
        start = 0; 
        return;
    }

    // Deleting the `start` node
    if (start->data == w)
    {
        s1 = start;

       
        while (s1->next != start)
        {
            s1 = s1->next;
        }

        s1->next = start->next;
        b1 = start;             
        start = start->next; 
        free(b1);              
        return;
    }

    // Deleting a middle node
    s1 = start;
    while (s1->next != start && s1->next->data != w)
    {
        s1 = s1->next;
    }

    // If the target node is not found
    if (s1->next == start)
    {
        printf("Data %d not found in the list.\n", w);
        return;
    }

    // Delete the target node
    b1 = s1->next;
    s1->next = s1->next->next; 
    free(b1);                 
}



void display()
{
    struct node *j1;
    j1 = start;

     if (start == 0)
    {
        printf("There is no any node to display.");
        return;
    }

    do
    {
        printf("%d ",j1->data);
        j1 = j1->next;
    } while (j1 != start);
    
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

            exit(0);
        }
    default:
        {
            printf("Wrong input");
        }
    }

    }
    
    return 0;
}