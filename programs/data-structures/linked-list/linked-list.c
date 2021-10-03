#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

int main()
{
    int ch;
    do
    {
        printf("\n\n\t 1. Create linked list");
        printf("\n\n\t 2. Display linked list");
        printf("\n\n\t 3. Exit");
        printf("\n\n\t Enter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            break;
        case 2:
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