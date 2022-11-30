#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *tail, *temp;
int main()
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
            head = tail=newnode;
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
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (temp != tail)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

/////////////////yaaar nhi chal rha //////////////////