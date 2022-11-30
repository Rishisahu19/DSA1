#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *tail, *temp, *prev,*current,*nextnode;
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

        printf("DO YOU WANT TO CREATE NODE");
        scanf("%d", &choice);
    }
    return head;
}

void print(struct node **head)
{
    tail = (*head);
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
    do{
        count++;
        temp=temp->next;
    }
    while (temp != head);
}
     
    struct node *deletion_at_pos(struct node **head)
    {
        tail=(*head);
        int pos, i = 1;
         
        // struct node *current, *nextnode;
        current = tail->next;
        printf("ENTER THE POSITION");
        scanf("%d", &pos);
        int count = length(tail);

        if (pos > count || pos < 0)
        {
            printf("INVALID POSITION");
        }
        // else if(pos==1)
        // {
        // deletionafromeg();
        // }
        else
        {

            while (i < pos - 1)
            {
                current = current->next;
                i++;
            }
            nextnode = current->next;
            // newnode->next=current->next->next;
            current->next = nextnode->next; 
            free(nextnode);
        }
    }

    int main()
    {
        struct node *head;
        head = creation();
        deletion_at_pos(&head);
        print(&head);
    }