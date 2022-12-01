#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp, *prenode, *nextnode;
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
    //  printf("TYPE 1 FOR INSERTION BEG\n");
    // printf("TYPE 2 FOR INSERTION Btw\n");
    // printf("TYPE 3 FOR INSERTION END\n");
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
struct node *insertion_at_beg(struct node **head)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
    return *head;
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
struct node *insertion_at_btw(struct node **head)
{
    temp = *head;
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
        while (i < pos - 1)
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
void insertion_at_end(struct node **head)
{
    struct node *temp;
    temp = *head; /// new
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    temp->next = newnode;
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    // temp = *head;  // this is remove bt me
}
struct node *deletion_at_beg(struct node **head)
{
    struct node *temp;

    if (*head == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return *head;
    }
}
void deletion_at_btw(struct node **head)
{

    // struct node *temp, *nextnode;
    temp = (*head);
    if (head == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else
    {
        int pos;
        int i = 1;
        printf("ENTER POSTION");
        scanf("%d", &pos);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}
struct node *deletion_at_end(struct node **head)
{
    // struct node *temp, *prenode;
    temp = (*head);
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
        if (temp == (*head))
        {
            (*head) == NULL;
        }
        else
        {
            prenode->next = NULL;
        }
        free(temp);
        // return *head;
    }
}
int main()
{
    struct node *head;
    // int t, i;
    // printf("Type How Many Time You Want To Run The Menu\n");
    // scanf("%d", &t);
    // for (i = 0; i < t; i++)
    // {
    printf("TYPE 1 BHAI\n");
    // printf("TYPE 7 CREATION AND DISPLAY\n");
    head = creation();
    printf("TYPE 1 FOR INSERTION BEG\n");
    printf("TYPE 2 FOR INSERTION BTW\n");
    printf("TYPE 3 FOR INSERTION END\n");
    printf("TYPE 4 FOR DELETION BEG\n");
    printf("TYPE 5 FOR DELETION BTW\n");
    printf("TYPE 6 FOR DELETION END\n");

    int n;
    scanf("%d", &n);
    switch (n)
    {
    // case 7:
    //     head = creation();
    //     break;
    case 1:
        insertion_at_beg(&head);
        print(&head);
        break;

    case 2:
        insertion_at_btw(&head);
        print(&head);
        break;
    case 3:
        insertion_at_end(&head);
        print(&head);
        break;
    case 4:
        deletion_at_beg(&head);
        print(&head);
        break;
    case 5:
        deletion_at_btw(&head);
        print(&head);
        break;
    case 6:
        deletion_at_end(&head);
        print(&head);

        break;

    default:

        break;
    }
}
// insertion_at_beg(&head);
// insertion_at_btw(&head);
// insertion_at_end(&head);
// print(&head);
// }
