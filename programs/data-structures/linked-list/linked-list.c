#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head; // head pointer holds the address of starting node



int createLinkedList()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node)); // create new node
    printf("\n\n\t Enter the data for the linkedlist: "); // enter data
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return 1;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return 1;
    }
}

void display()
{
    struct node *temp;
    if (head != NULL)
    {
        for (temp = head; temp != NULL; temp = temp->next)
        {
            printf("%d\t", temp->data);
        }
    }
    else
    {
        printf("\n\n\t The list is empty...");
    }
}

int main()
{
    int ch;
    head = NULL; // list is empty.
    do
    {
        clear();
        printf("\n\n\t 1. Create linked list");
        printf("\n\n\t 2. Display linked list");
        printf("\n\n\t 3. Exit");
        printf("\n\n\t Enter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createLinkedList();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("\n\n\t Wrong entry try again....,");
            break;
        }
    } while (ch != 3);
}