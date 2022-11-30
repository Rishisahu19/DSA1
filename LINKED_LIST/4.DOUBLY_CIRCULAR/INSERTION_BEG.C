#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *tail;
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
    struct node* temp = *head;
    do{
        printf("%d", temp->data);
        temp=temp->next;
    }
    while (temp->next != (*head));
}
struct node *insertion_at_beg(struct node **head)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);

    if ((*head) == NULL){
        (*head) = tail = newnode;
        newnode->prev = tail;
        newnode->next = (*head);
    }
    else{
        newnode->next = (*head);
        (*head)->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        (*head) = newnode;
    }
    // return (*head);
}
    int main()
    {
        struct node *head;
        head = creation();
        insertion_at_beg(&head);
        print(&head);
    }
