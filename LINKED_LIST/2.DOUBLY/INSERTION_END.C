#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *temp, *tail;
struct node *creation()
{
    head = NULL;
    int choice;
    scanf("%d", &choice);
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER DATA\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("DO YOU WANT TO CREATE NODE :");
        scanf("%d", &choice);
    }
    return head;
}
void print(struct node **head)
{
    temp = *head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
struct node *insertion_at_end(struct node **head)
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);
    temp = (*head);
    newnode->prev = 0;
    newnode->next = 0;
    if (temp == NULL)
    {
        temp = newnode;
        
    }
    else
    {
        // temp = (*head);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    // return *head;
}
int main()
{
    struct node *head;
    head = creation();
    insertion_at_end(&head);
    print(&head);
}