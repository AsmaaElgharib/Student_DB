 #include "STD.h"
#include "SDB.h"

 void SDB_APP()
 {
    uint8 choice;
    do{
      printf("\n 1. press 1 to add entry \n 2. press 2 To get used size in database\n 3. press 3 To read student data \n 4. press 4 To get the list of all student IDs\n 5. press 5 To check is ID is existed\n 6. press 6 To delete student data\n 7. press 7 To check is database is full\n 8. press 0 To exit enter 0\n");
      scanf("%d", &choice);
      SDB_action(choice);
    }while (choice != 0);

 }

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
        printf("used size: %d", SDB_GetUsedSize());
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
            printf("%u", list[i]);
            i++;
        }
        printf("*------------------------------------------------------------*");
        break;
    case 5:
        printf("Enter student id:\n");
        scanf("%u",&id);
        printf(SDB_IsIdExist(id)? "student with that id exists":"student with that id not found");
        printf("*------------------------------------------------------------*");
        break;
    case 6:
        printf("Enter student id:\n");
        scanf("%u",&id);
        SDB_DeletEntry(id);
        printf("*------------------------------------------------------------*");
        break;
    case 7:
        printf(SDB_IsFull()? "DataBase is full":"DataBase is not full!, you can add more records now");
        printf("*------------------------------------------------------------*");
        break;
    case 0:
        printf("Exit Program");
        printf("*------------------------------------------------------------*");
        break;
    default:
        break;
    }
}
