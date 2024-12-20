#include <stdio.h>
#include <stdlib.h>

int *queue;
int size;
int front = -1, rear = -1;

void initializeQueue() {
    queue = (int *)malloc(size * sizeof(int));
}

void enqueue(int element) {
    if (front == (rear + 1) % size) {
        printf("\n queue is full\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    queue[rear] = element;
    printf("\n%d is inserted\n",element);
}

int dequeue() {
    int element;
    if (front == -1 && rear == -1) {
        printf("\n queue is empty\n");
        return -1;
    }
    element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
    printf("\n%d is deleted from the queue\n", element);
    return element;
}

int searchElement(int element) {
    if (front == -1 && rear == -1) {
        printf("\n queue is empty\n");
        return -1;
    }
    int current = front;
    int position = 1;
    do {
        if (queue[current] == element) {
            return position;
        }
        current = (current + 1) % size;
        position++;
    } while (current != (rear + 1) % size);
    return -1;
}

void displayQueue() {
    if (front == -1 && rear == -1) {
        printf("\nqueue is empty\n");
        return;
    }
    printf("queue elements are ");
    int current = front;
    do {
        printf("%d ", queue[current]);
        current = (current + 1) % size;
    } while (current != (rear + 1) % size);
    printf("\n");
}

int main() {
    int choice, searchResult, element;
    printf("enter the size of the queue");
    scanf("%d", &size);
    initializeQueue();
    do {
        printf("\nselect your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search Element\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchResult = searchElement(element);
                if (searchResult != -1) {
                    printf("%d found at position %d\n", element, searchResult);
                } else {
                    printf("%d not found in the queue\n", element);
                }
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("exiting the programme\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 5);
free(queue);
    return 0;
}
