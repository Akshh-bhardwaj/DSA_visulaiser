#include <stdio.h>
#include <stdlib.h>

// ---------------- STACK ----------------
#define MAX 100
int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

// ---------------- QUEUE ----------------
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("Dequeued: %d\n", queue[front++]);
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// ---------------- LINKED LIST ----------------
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteFromFront() {
    if (head == NULL)
        printf("Linked List is empty\n");
    else {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- MAIN MENU ----------------
void stackMenu() {
    int choice, val;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Back\nEnter: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: return;
            default: printf("Invalid choice\n");
        }
    }
}

void queueMenu() {
    int choice, val;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\nEnter: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: displayQueue(); break;
            case 4: return;
            default: printf("Invalid choice\n");
        }
    }
}

void linkedListMenu() {
    int choice, val;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at End\n2. Delete from Front\n3. Display\n4. Back\nEnter: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insertAtEnd(val); break;
            case 2: deleteFromFront(); break;
            case 3: displayList(); break;
            case 4: return;
            default: printf("Invalid choice\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== DSA Visualizer Console ===\n");
        printf("1. Stack\n2. Queue\n3. Linked List\n4. Exit\nEnter: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: stackMenu(); break;
            case 2: queueMenu(); break;
            case 3: linkedListMenu(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
