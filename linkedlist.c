#include <stdio.h>
#define MAX 10
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertBeg(Node** head, int val) {
    Node* temp = createNode(val);
    temp->next = *head;
    *head = temp;
}

void deleteBeg(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void insertEnd(Node* head, int val) {
    Node* temp = head;
    Node* nn = createNode(val);
    if (head == NULL) {
        head = nn;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
}

void sortll(Node* head) {
    if (head == NULL) return;
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int arr[100];
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    int tmp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    temp = head;
    for (int i = 0; i < count; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }
}

void insertBefore(Node* head, int val, int pos) {
    if (pos == 1) {
        insertBeg(&head, val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("NOT FOUND\n");
        return;
    }
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletePos(Node* head, int pos) {
    if (head == NULL) return;
    Node* temp = head;
    if (pos == 1) {
        deleteBeg(&head);
        return;
    }
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("out of range\n");
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void deleteEnd(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

int main() {
    Node* head = NULL;
    int n;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    head = createList(n);
    printf("Linked list after creation:\n");
    displayList(head);

    insertBeg(&head, 30);
    displayList(head);

    insertEnd(head, 40);
    displayList(head);

    sortll(head);
    displayList(head);

    insertBefore(head, 50, 3);
    displayList(head);

    deletePos(head, 2);
    displayList(head);

    deleteEnd(head);
    displayList(head);

    return 0;
}
