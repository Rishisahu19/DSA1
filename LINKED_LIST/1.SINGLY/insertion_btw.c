#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp;
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
    struct node *temp;
    temp = *head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

 int length(struct node *head)
 {
     struct node *temp;
     temp = head;
     int count = 0;
     while (temp != 0)
     {
         count++;
         temp = temp->next;
     }
    return count;
 }
struct node*insertion_at_btw(struct node **head)
{
     temp=*head;
    int count = length(temp);
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
 
    printf("ENTER POSITION\n");
    scanf("%d", &pos);

    if (pos > count)
    {
        
        printf("INVALID POSITION");
    }
    else
    {
     
        temp = *head;
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }

    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
    }
}
int main()
{
    struct node *head;
    head = creation();
    insertion_at_btw(&head);
    print(&head);
}
