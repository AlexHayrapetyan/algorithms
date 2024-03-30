#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int rear, front;
    int size;
    int* arr;
} Queue;

Queue* createQueue(int s) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = s;
    queue->arr = (int*)malloc(s * sizeof(int));
    return queue;
}

void enQueue(Queue* queue, int value) {
    if ((queue->front == 0 && queue->rear == queue->size - 1) || ((queue->rear + 1) % queue->size == queue->front)) {
        printf("\nQueue is Full");
        return;
    }

    else if (queue->front == -1) { 
        queue->front = queue->rear = 0;
        queue->arr[queue->rear] = value;
    }

    else if (queue->rear == queue->size - 1 && queue->front != 0) {
        queue->rear = 0;
        queue->arr[queue->rear] = value;
    }

    else {
        queue->rear++;
        queue->arr[queue->rear] = value;
    }
}

int deQueue(Queue* queue) {
    if (queue->front == -1) {
        printf("\nQueue is Empty");
        return -1;
    }

    int data = queue->arr[queue->front];
    queue->arr[queue->front] = -1;
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else if (queue->front == queue->size - 1)
        queue->front = 0;
    else
        queue->front++;

    return data;
}

void displayQueue(Queue* queue) {
    if (queue->front == -1) {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (queue->rear >= queue->front) {
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->arr[i]);
    }
    else {
        for (int i = queue->front; i < queue->size; i++)
            printf("%d ", queue->arr[i]);

        for (int i = 0; i <= queue->rear; i++)
            printf("%d ", queue->arr[i]);
    }
}

int main() {
    Queue* q = createQueue(5);

    enQueue(q, 12);
    enQueue(q, 34);
    enQueue(q, 67);
    enQueue(q, 9);

    displayQueue(q);

    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));

    displayQueue(q);

    enQueue(q, 89);
    enQueue(q, 4);
    enQueue(q, -8);

    displayQueue(q);

    enQueue(q, 21);
    return 0;
}
