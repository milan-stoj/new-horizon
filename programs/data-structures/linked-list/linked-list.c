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
    sscanf_s(input, "%d", &num);
    return num;
}

int validated_choice()
{
    int num;
    fgets(input, BUFFER_SIZE, stdin);
    if (input[1] != '\n') num = 0;
    sscanf_s(input, "%d", &num);
    return num;
}

void display_menu()
{
    system("cls");
    printf("\n\t 1. Init List");
    printf("\n\t 2. Display List");
    printf("\n\t 3. Value At Index");
    printf("\n\t 4. Push Front");
    printf("\n\t 5. Push Back");
    printf("\n\t 6. Pop Front");
    printf("\n\t 7. Pop Back");
    printf("\n\t 8. Insert at Index");
    printf("\n\t 9. Delete at Index");
    printf("\n\t 10. Value of n From End");
    printf("\n\t 11. Reverse");
    printf("\n\t 12. Remove Value");
    printf("\n\t 69. Exit");
    printf("\n\n\t Enter your choice: ");
}


int main()
{
    linked_list* my_list;
    my_list = (linked_list*)malloc(sizeof(linked_list));
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
            getchar();
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
            getchar();
            break;
        }
        case 7:
        {
            int value = POP_BACK(my_list);
            printf("\nThe value popped from back is: %d", value);
            getchar();
            break;
        }
        case 8:
        {
            int index = get_value();
            int value = get_value();
            INSERT(my_list, index, value);
            break;
        }
        case 9:
        {
            int index = get_value();
            ERASE(my_list, index);
            break;
        }
        case 10:
        {
            int index = get_value();
            int result = VALUE_N_FROM_END(my_list, index);
            printf("\nThe value %d from the end is: %d", index, result);
            getchar();
            break;
        }
        case 11:
        {
            REVERSE(my_list);
            break;
        }
        case 12:
        {
            int value = get_value();
            int result = REMOVE_VALUE(my_list, value);
            if(result == 1) printf("\nThe value %d was removed from the list.", value);
            if(result == 0) printf("\nThe value %d was not found in the list.", value);
            getchar();
            break;
        }
        case 69:
        {
            exit(0);
            break;
        }
        default:
            printf("\n\n\t Wrong entry try again....,");
            break;
        }
    }
}