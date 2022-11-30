#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node  *newnode, *tail,*temp;
int main()
{
    
    int choice;
    scanf("%d", &choice);
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER DATA\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (tail == NULL)
        {
             tail= newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;

        }
    
        printf("DO YOU WANT TO CREATE NODE");
        scanf("%d", &choice);
    }

    temp=tail->next;
    while (temp->next != tail->next)
    {
        printf("%d", temp ->data);
        temp= temp->next;
    }

    printf("%d", temp->data);
}
