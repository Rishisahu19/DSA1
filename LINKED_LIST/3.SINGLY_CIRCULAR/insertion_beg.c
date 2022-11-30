#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *tail;
struct node *creation()
{
    head = 0;
    int choice;
    scanf("%d", &choice);
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER DATA\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }

        printf("DO YOU WANT TO CREATE NODE: ");
        scanf("%d", &choice);
    }
    return head;
}

void print(struct node **head)
{
    tail = *head;
    while (tail->next != (*head))
    {
        printf("%d", tail->data);
        tail = tail->next;
    }

    printf("%d", tail->data);
}
struct node *insertion_at_beg(struct node **head)
{
    //  struct node *tail, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        (*head) = newnode;
    }
    return *head;
}
int main()
{
    struct node *head;
    head = creation();
    insertion_at_beg(&head);
    print(&head);
}

// WORK NHI