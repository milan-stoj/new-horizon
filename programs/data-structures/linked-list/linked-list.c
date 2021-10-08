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
    printf("\n\t 3. Value At Index");
    printf("\n\t 4. Push Front");
    printf("\n\t 5. Push Back");
    printf("\n\t 6. Pop Front");
    printf("\n\t 7. Pop Back");
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
            int index = get_value();
            int result = VALUE_AT(my_list, index);
            printf("\nThe value at index %d is: %d", index, result);
            break;
        }
        case 4:
        {
            int value = get_value();
            PUSH_FRONT(my_list, value);
            break;
        }
        case 5:
        {
            int value = get_value();
            PUSH_BACK(my_list, value);
            break;
        }
        case 6:
        {
            int value = POP_FRONT(my_list);
            printf("\nThe value popped from front is: %d", value);
            break;
        }
        case 7:
        {
            int value = POP_BACK(my_list);
            printf("\nThe value popped from back is: %d", value);
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