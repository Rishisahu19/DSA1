#include <stdio.h>
#include <stdlib.h>

    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head, *newnode, *temp;
    int main()
    {
        head = 0;
        int choice;
        scanf("%d",&choice);
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
        temp = head;
        while (temp != 0)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        
    }
 