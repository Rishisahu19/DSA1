#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *tail,*temp;
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
            head = tail= newnode;
            tail->next=head;
        }
        else
        {
            tail->next = newnode;
            tail= newnode;
            tail->next=head;

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
        printf("%d", tail ->data);
        tail= tail->next;
    }

    printf("%d", tail->data);
}
struct node *deletion_at_last(struct node **head)
{
     
 struct node* temp,*current,*prev;
//  current=*head;
current=tail->next;
if(tail==0)
{
    printf("list is empty");
}
else if (current->next==current)
{
    tail=0;
    free(current);
}
else{
    while (current->next!=tail->next)
    {
        prev=current;
        current=current->next;
    }
    prev->next=tail->next;
    tail=prev;
    free(current);
    }
}


int main()
{
    struct node *head;
    head = creation();
    deletion_at_last(&head);
    print(&head);
}