#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int cap;
    int *arr;
};

int isFull(struct stack *st) {
    return st->top == st->cap - 1;
}

int isEmpty(struct stack *st) {
    return st->top == -1;
}

void push(struct stack *st) {
    if (isFull(st)) {
        printf("Stack is Full.\n");
    } else {
        st->top++;
        printf("Enter a data: ");
        scanf("%d", &st->arr[st->top]);
    }
}

void pop(struct stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty.\n");
    } else {
        int data = st->arr[st->top];
        st->top--;
        printf("Popped element is: %d\n", data);
    }
}

int main() {
    int ch, size;
    struct stack *st;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    st = (struct stack *)malloc(sizeof(struct stack));
    st->top = -1;
    st->cap = size;
    st->arr = (int *)calloc(st->cap, sizeof(int));
    
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push(st);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                free(st->arr);
                free(st);
                exit(0);
            default:
                printf("Wrong Input.\n");
        }
    }

    return 0;
}
