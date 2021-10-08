#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linked-list.h"

#define BUFFER_SIZE 128

char input[BUFFER_SIZE];

int get_value() 
{
    printf("\nPlease enter a value: ");
    int num;
    fgets(input, BUFFER_SIZE, stdin);
    if (sscanf(input, "%d", &num) != 1) num = 0;
    return num;
}

int validated_choice()
{
    int num;
    fgets(input, BUFFER_SIZE, stdin);
    if (input[1] != '\n' || sscanf(input, "%d", &num) != 1) num = 0;
    return num;
}

void display_menu()
{
    system("clear");
    printf("\n\t 1. Init List");
    printf("\n\t 2. Display List");
    printf("\n\t 3. Push Front");
    printf("\n\t 4. Push Back");
    printf("\n\t 8. Exit");
    printf("\n\n\t Enter your choice: ");
}


int main()
{
    linked_list my_list;
    for (;;)
    {
        display_menu();
        switch (validated_choice())
        {
        case 1:
        {
            INIT_LIST(my_list);
            break;
        }
        case 2:
        {
            DISPLAY_LIST(my_list);
            break;
        }
        case 3:
        {
            int value = get_value();
            PUSH_FRONT(my_list, value);
            break;
        }
        case 4:
        {
            int value = get_value();
            PUSH_BACK(my_list, value);
            break;
        }
        case 8:
            exit(1);
            break;
        default:
            printf("\n\n\t Wrong entry try again....,");
            break;
        }
    }
}