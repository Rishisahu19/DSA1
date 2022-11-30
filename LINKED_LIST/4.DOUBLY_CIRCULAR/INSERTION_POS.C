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
    // struct node *temp;
    temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
    struct node *insertion_at_POS(struct node **head)
    {
        int pos, i = 1;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER DATA YOU WANT TO INSERT\n");
        scanf("%d", &newnode->data);
        printf("ENTER POSITION\n");
        scanf("%d", &pos);
        temp=(*head);
        int count = length(temp);
        if (pos > count || pos < 0)
        {
            printf("INVALID POSITION");
        }
        // else if(pos==1)
        // {
        // insertionatbeg();
        // }
        else
        {
            newnode->next = 0;
            temp = tail->next;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
             newnode->prev=temp;
             newnode->next=temp->next;
             temp->next->prev=newnode;
             temp->next=newnode;
        }
    }
    int main()
    {
        struct node *head;
        head = creation();
        insertion_at_POS(&head);
        print(&head);
    }
