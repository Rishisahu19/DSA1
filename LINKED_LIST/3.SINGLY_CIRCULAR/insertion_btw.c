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
int length(struct node *head)
{
    struct node *temp;
    temp = head;
    int count = 0;
    do{
        count++;
        temp=temp->next;
    }
    while(temp!=head);
    return count;
}
struct node *insertion_at_btw(struct node **head)
{

    struct node *temp;
    temp=(*head);
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);

    printf("ENTER POSITION\n");
    scanf("%d", &pos);
    int count = length(temp);
    if (pos > count || pos < 0)
    {
        printf("INVALID POSITION");
    }

    else 
    {
        // printf("ENTER DATA YOU WANT TO INSERT\n");
        // scanf("%d", &newnode->data);

        newnode->next = 0;
        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return *head;
    }
}
// return *head;

int main()
{
    struct node *head;
    head = creation();
    insertion_at_btw(&head);
    print(&head);
}
// invalid pos