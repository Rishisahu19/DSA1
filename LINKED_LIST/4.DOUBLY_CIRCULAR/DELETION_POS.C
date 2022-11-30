#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *tail, *temp;
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
        newnode->prev = 0;
        newnode->next = 0;
        if (head == NULL)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("DO YOU WANT TO CREATE NODE: ");
        scanf("%d", &choice);
    }
    return head;
}

void print(struct node **head)
{
    tail = (*head);
    while (tail->next != (*head))
    {
        printf("%d", tail->data);
        tail = tail->next;
    }

    printf("%d", tail->data);
}
struct node *deletion_at_POS(struct node **head)
{
    int pos, i = 1;
    // struct node *temp;
    temp = (*head);
    printf("enter the postion");
    scanf("%d", &pos);
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp->next == (*head))
    {
        tail = temp->prev;
        free(temp);
    }
    else
    {
        free(temp);
    }
}

int main()
{
    struct node *head;
    head = creation();
    deletion_at_POS(&head);
    print(&head);
}
