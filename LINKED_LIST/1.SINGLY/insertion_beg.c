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
    temp = *head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
 struct node* insertion_at_beg(struct node**head)
    {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
    return *head;
}
int main()
{
    struct node *head;
    head = creation();
    insertion_at_beg(&head);
    print(&head);
}
