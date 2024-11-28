#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(struct Node **head, int value, int newValue)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // If the node to insert before is the first node
    if ((*head)->data == value)
    {
        insertAtBeginning(head, newValue);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Node with value %d not found.\n", value);
    }
    else
    {
        struct Node *newNode = createNode(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node with a specific value
void deleteNode(struct Node **head, int value)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to delete the first node (beginning)
void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->next == NULL)
    { // Only one node
        free(temp);
        *head = NULL;
        return;
    }

    // Traverse to the second-last node
    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Delete the last node
    free(temp->next);
    temp->next = NULL;
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

