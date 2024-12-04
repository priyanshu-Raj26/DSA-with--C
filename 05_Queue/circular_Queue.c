#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int rear;
    int front; 
    int cap;
    int *arr;
};

struct Queue *createQueue(int s) {
    struct Queue *G = (struct Queue *)malloc(sizeof(struct Queue));
    G->rear = -1;
    G->front = -1;
    G->cap = s;
    G->arr = (int *)calloc(G->cap, sizeof(int));
    return G;
}

int isEmpty(struct Queue *Q) {
    return Q->front == -1;
}

int isFull(struct Queue *Q) {
    return (Q->rear + 1) % Q->cap == Q->front;
}

void enQueue(struct Queue *Q) {
    int d;
    printf("Enter a data: ");
    scanf("%d", &d);

    if (isFull(Q)) {
        printf("Queue is Full.\n");
    } else {
        Q->rear = (Q->rear + 1) % Q->cap;
        Q->arr[Q->rear] = d;

        if (Q->front == -1) {
            Q->front = Q->rear;
        }
        printf("Data inserted: %d\n", d);
    }
}

void deQueue(struct Queue *Q) {
    if (isEmpty(Q)) {
        printf("Queue is Empty.\n");
    } else {
        int d = Q->arr[Q->front];
        if (Q->rear == Q->front) {
            Q->rear = -1;
            Q->front = -1;
        } else {
            Q->front = (Q->front + 1) % Q->cap;
        }
        printf("Deleted Data is %d\n", d);
    }
}

void queueSize(struct Queue *Q) {
    if (isEmpty(Q)) {
        printf("Size of the Queue is: 0\n");
    } else {
        int d = (Q->rear - Q->front + Q->cap) % Q->cap + 1;
        printf("Size of the Queue is: %d\n", d);
    }
}

void deleteQueue(struct Queue *Q) {
    if (Q) {
        if (Q->arr) {
            free(Q->arr);
        }
        free(Q);
        printf("Whole Queue is Deleted.\n");
    }
}

int main() {
    struct Queue *Q;
    int s, ch;

    printf("Enter the size of the Queue: ");
    scanf("%d", &s);

    Q = createQueue(s);

    printf("\n1. Insertion of Data.");
    printf("\n2. Deletion of Data.");
    printf("\n3. Size of the Queue.");
    printf("\n4. Delete Whole Queue.");
    printf("\n5. Exit.");

    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                enQueue(Q);
                break;
            case 2:
                deQueue(Q);
                break;
            case 3:
                queueSize(Q);
                break;
            case 4:
                deleteQueue(Q);
                exit(0);
            case 5:
                deleteQueue(Q);
                exit(0);
            default:
                printf("Wrong Input.\n");
        }
    }

    return 0;
}
