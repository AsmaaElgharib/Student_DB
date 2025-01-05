#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

// function to start project and receive user's choice
 void SDB_APP()
 {
    uint8 choice;
    do{
        // Display options to user
        printf("\n 1. Press 1 to add entry \n");
        printf(" 2. Press 2 to get used size in database\n");
        printf(" 3. Press 3 to read student data \n");
        printf(" 4. Press 4 to get the list of all student IDs\n");
        printf(" 5. Press 5 to check if ID exists\n");
        printf(" 6. Press 6 to delete student data\n");
        printf(" 7. Press 7 to check if the database is full\n");
        printf(" 8. Press 0 to exit\n");
        scanf("%d", &choice);
        // Call SDB_action function, passing the user's choice to execute db statement
        SDB_action(choice);
    }while (choice != 0); //the project continues until the user chose to exit(0)

 }
/*
core of the project for handling user's input for database system
input of type char (choice) through it the user will be able to execute new db statement
*/
 void SDB_action (uint8 choice)
{
    uint32 id, list[MAX_STD];
    uint8 count, i = 0;
    switch (choice)
    {
    case 1:
        SDB_AddEntry();
        printf("*------------------------------------------------------------*");
        break;
    case 2:
        printf("used size: %d\n", SDB_GetUsedSize());
        printf("*------------------------------------------------------------*");
        break;
    case 3:
    printf("Enter student id:\n");
    scanf("%u",&id);
        SDB_ReadEntry(id);
        printf("*------------------------------------------------------------*");
        break;
    case 4:
        SDB_GetList (&count, list);
        printf("students in database with IDs:\n");
        while (i < count)
        {
            printf("%u\t\t", list[i]);
            i++;
        }
        printf("*------------------------------------------------------------*");
        break;
    case 5:
        printf("Enter student id:\n");
        scanf("%u",&id);
        printf(SDB_IsIdExist(id)? "student with that id exists\n":"student with that id not found\n");
        printf("*------------------------------------------------------------*");
        break;
    case 6:
        printf("Enter student id:\n");
        scanf("%u",&id);
        SDB_DeletEntry(id);
        printf("*------------------------------------------------------------*");
        break;
    case 7:
        printf(SDB_IsFull()? "DataBase is full\n":"DataBase is not full!, you can add more records now\n");
        printf("*------------------------------------------------------------*");
        break;
    case 0:
        printf("Exit Program\n");
        printf("*------------------------------------------------------------*");
        break;
    default:
        break;
    }
}
