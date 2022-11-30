

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp,*nextnode;
struct node *creation()
{
    struct node *head;
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
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
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
void deletion_at_btw(struct node **head)
{

    // struct node *temp, *nextnode;
    temp=(*head);
    if (head == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else
    {
        int pos;
        int i = 1;
        printf("ENTER POSTION");
        scanf("%d", &pos);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        
    }
}

int main()
{
    struct node *head;
    head = creation();
    deletion_at_btw(&head);
    print(&head);
}
