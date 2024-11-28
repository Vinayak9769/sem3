#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
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
void insertBefore(struct Node **head, int value, int newValue)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
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
void deleteNode(struct Node **head, int value)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
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
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == NULL)
    { 
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

