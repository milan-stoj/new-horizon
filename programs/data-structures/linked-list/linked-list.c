#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked-list.h"

char buffer[128];

int display_menu(int ch)
{
    system("clear");
    printf("\n\t 1. Create Linked List");
    printf("\n\t 2. Display Linked List");
    printf("\n\t 3. Exit");
    printf("\n\n\t Enter your choice: ");
    if(fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%d", &ch) != 1)
        {
            ch = 0;
        }

    }
    return ch;
}

int main()
{
    int ch;
    do
    {
        switch (display_menu(ch))
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