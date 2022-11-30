#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *temp,*tail;
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
        printf("DO YOU WANT TO CREATE NODE");
        scanf("%d", &choice);
    }
    return head;
}
void print(struct node **head)
{
    temp = (*head);
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
struct node *deletion_at_end(struct node **head)
{
     
    // struct node *tail;
    tail=(*head);
    if ( (*head)== 0)
    {
        printf("list is empty");
    }
    else
    {   
        while(tail->next->next!=NULL){
            tail=tail->next;
        }
        temp=tail->next;
        tail->next = NULL;
        free(temp);
    }
}
int main()
{
    struct node *head;
    head = creation();
    deletion_at_end(&head);
    print(&head);
}