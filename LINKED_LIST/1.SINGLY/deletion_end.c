#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp,*prenode;
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
    temp = (*head);
    while (temp != 0)
    {
        // printf("ho rhaaa haaaa betii chod");
        printf("%d", temp->data);
        temp = temp->next;
    }
}
struct node *deletion_at_end(struct node **head)
{
    // struct node *temp, *prenode;
    temp=(*head);
    if ((*head) == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else 
    {
        
        while (temp->next != NULL)
        {
            prenode = temp;
            temp = temp->next;
            
        }
        if(temp==(*head))
        {
        (*head)==NULL;
        }
        else 
        {
        prenode->next=NULL;
         
        }
        free(temp);
        // return *head;
        
    }
}

int main()
{
    struct node *head;
    head = creation();
    deletion_at_end(&head);
    print(&head);
}
