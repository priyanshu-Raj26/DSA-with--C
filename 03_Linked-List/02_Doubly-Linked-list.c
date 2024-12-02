#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    char data[10];
    struct node *next;
};

struct node *start = 0;     // global  declaration



struct node *createNode()
{
    struct node *k1;
    k1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%s",k1->data);
    k1->next = 0;
    k1->prev = 0;
    return k1;
}


void insertStart()
{
    struct node *h1;
    h1 = createNode();
    if (start == 0)
    {
        start = h1;
    }
    else 
    {
        h1->next = start;
        start->prev = h1;
        start = h1;
    }
}


void insertEnd()
{
    struct node *d1,*a1; 
    d1 = createNode();
    if (start == 0)
    {
        start = d1;
    }
    else 
    {
        a1 = start;
        while (a1->next != 0)
        {
            a1 = a1->next;
        }
        a1->next = d1;
        d1->prev = a1;
        
    }
    
}

void insertMiddle()
{
    struct node *p1, *c1;
    p1 = createNode();

    if (start == NULL)  // Initialize 'start' properly
    {
        start = p1;
    }
    else
    {
        char d[10];
        printf("Enter the data where you want to insert: ");
        scanf("%s", d);

        c1 = start;

        // Traverse and find the data
        while (c1->next != NULL && strcmp(c1->next->data, d) != 0)
        {
            c1 = c1->next;
        }

        // If data not found
        if (c1->next == NULL)
        {
            printf("Data not found. Insertion not possible.\n");
            return;
        }

        // Insert the new node
        p1->prev = c1;
        p1->next = c1->next;

        if (c1->next != NULL)  // Update next node's prev pointer if not the last node
        {
            c1->next->prev = p1;
        }

        c1->next = p1;
    }
}



void deleteStart()
{
    struct node *f1;
    
    if (start == 0)
    {
        printf("There is no any node to delete.");
    }
    else
    {
        f1 = start;
        
        start = start->next;
        start->prev = 0;
        f1->next = 0;
        free(f1);
    }
    
}


void deleteEnd()
{
    if (start == 0)
    {
        printf("There is no node to delete.");
    }
    else if (start->next == 0)
    {
        free(start);
        start = 0;
    }
    
    else
    {
        struct node *s1,*q1;
        s1 = start;
        while (s1->next->next != 0)
        {
            s1 = s1->next;
        }
        q1 = s1->next;
        q1->prev = 0;
        s1->next = 0;
        free(q1);

    }
    
}


void deleteMiddle() 
{
    struct node *s1, *b1;
    if (start == NULL) {
        printf("There is no node to delete.\n");
        return;
    }

    char w[10];
    printf("Enter the data you want to delete: ");
    scanf("%s", w);

    s1 = start;

    while (s1 != NULL && strcmp(s1->data, w) != 0) {
        s1 = s1->next;
    }

    // If not found
    if (s1 == NULL) {
        printf("Data not found in the list.\n");
        return;
    }

    // Node found, handle deletion
    if (s1->prev != NULL) {
        s1->prev->next = s1->next;
    } else {
        // Deleting the first node
        start = s1->next;
    }

    if (s1->next != NULL) {
        s1->next->prev = s1->prev;
    }

    free(s1);
    printf("Node with data '%s' deleted.\n", w);
}

void display()
{
    struct node *l1; 
    l1 = start;
    if (start == 0)
    {
        printf("There is no any node to display.");
    }
    else 
    {
        while (l1 != 0)
        {
            printf("%s  ",l1->data);
            l1 = l1->next;
        }
        
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
