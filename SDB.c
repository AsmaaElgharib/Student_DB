#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"


student* start = NULL;

bool SDB_IsFull()
{
    return (SDB_GetUsedSize() >= MAX_STD);
}

 uint8 SDB_GetUsedSize()
 {
    int8 dbCounter = 0;
    student* std = start;
    while (std != NULL)
    {
        dbCounter ++;
        std = std -> link;
    }

    return dbCounter;
 }

bool SDB_AddEntry()
{
    if(SDB_IsFull())
    {
        return false;
    }
    else
    {
        student* start = NULL;
        student* newStd = (student*) malloc(sizeof(student));
        if(newStd != NULL)
        {
            return SDB_InsertStudentRecordes(newStd);
        }
        return false;
    }
}

bool SDB_InsertStudentRecordes(student* newStd)
{
        uint32 id, year, course1_ID, course1_grade, course2_ID, course2_grade, course3_ID, course3_grade;
        printf("Enter ID, Year, Course1_ID, Course1_Grade, Course2_ID, Course2_Grade, Course3_ID, Course3_Grade:\n");
        printf("Enter Student Id: \n");
        if(scanf("%u", &id) != 1) return false;
        if(SDB_IsIdExist(id)) return false;
        printf("Enter Student year: \n");
        if(scanf("%u", &year) != 1) return false;
        printf("Enter Course1 ID: \n");
        if(scanf("%u", &course1_ID) != 1) return false;
        printf("Enter Course1 grade: \n");
        if(scanf("%u", &course1_grade)!= 1) return false;
        printf("Enter Course2 ID: \n");
        if(scanf("%u", &course2_ID) != 1) return false;
        printf("Enter Course2 grade: \n");
        if(scanf("%u", &course2_grade) != 1) return false;
        printf("Enter Course3 ID: \n");
        if(scanf("%u", &course3_ID) != 1) return false;
        printf("Enter Course3 grade: \n");
        if(scanf("%d", &course3_grade) != 1) return false;

        // Populate the new node
        newStd->Student_ID = id;
        newStd->Student_year = year;
        newStd->Course1_ID = course1_ID;
        newStd->Course1_grade = course1_grade;
        newStd->Course2_ID = course2_ID;
        newStd->Course2_grade = course2_grade;
        newStd->Course3_ID = course3_ID;
        newStd->Course3_grade = course3_grade;
        newStd->link = start;

        // Add to the front of the list
        start = newStd;
        return true;
}
void SDB_DeletEntry(uint32 id)
 {
    if(start == NULL)
    {
        printf("No student records found. \n");
        return;
    }
    student *temp = start;
    student *prev = NULL;

    // SEARCH
    while (temp != NULL)
    {
        if(temp -> Student_ID == id)
        {
            if(prev == NULL)
            {
                start = temp -> link;
            }
            else
            {
                prev -> link = temp -> link;
            }
            free(temp);
            printf("student with ID: %d deleted successfully.\n",id);
            return;
        }
        prev = temp;
        temp = temp -> link;
    }
 }

bool SDB_ReadEntry (uint32 id)
 {
    if(SDB_IsIdExist(id))
    {
        student* temp = start;
        while (temp != NULL)
        {
            if(temp -> Student_ID == id)
            {
                SDB_DisplayStudentRecordes(temp);
                return true;
            }
            temp = temp -> link;
        }
    }
    printf("student with ID: %u was not found.\n",id);
    return false;
 }
void SDB_DisplayStudentRecordes(student* newStd)
 {
    printf("Student Id:   %d\n",newStd -> Student_ID);
    printf("Student year: %d\n",newStd -> Student_year);
    printf("Course1 ID:   %d\n",newStd -> Course1_ID);
    printf("Course1 grade:%d\n",newStd -> Course1_grade);
    printf("Course2 ID:   %d\n",newStd -> Course2_ID);
    printf("Course2 grade:%d\n",newStd -> Course2_grade);
    printf("Course3 ID:   %d\n",newStd -> Course3_ID);
    printf("Course3 grade:%d\n",newStd -> Course3_grade);
 }

void SDB_GetList (uint8 * count, uint32 * list)
 {
    *count = SDB_GetUsedSize();
    student* std = start;
    uint8 i = 0;
    while (std != NULL)
    {
        list[i++] = std -> Student_ID;
        std = std -> link;
    }
 }
 bool SDB_IsIdExist (uint32 id)
 {
    student* std = start;
    while (std != NULL)
    {
        if(std -> Student_ID == id)
        {
            return true;
        }
        std = std -> link;
    }
    return false;
 }
