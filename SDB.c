#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"


student* start = NULL;

//function to check whether database is full or not
bool SDB_IsFull()
{
    return (SDB_GetUsedSize() >= MAX_STD);
}

// function to calculate current number of students in database
 uint8 SDB_GetUsedSize()
 {
    int8 dbCounter = 0;
    student* std = start;
    while (std != NULL) // looping through loop
    {
        dbCounter ++;
        std = std -> link; //  next student  in db
    }

    return dbCounter;
 }

// function to add new student record to database
bool SDB_AddEntry()
{
    // check if database is full (with 10 records)
    if(SDB_IsFull())
    {
        printf("Database is full\n");
        return false;
    }
    else
    {
        // allocating new memory location for student
        student* newStd = (student*) malloc(sizeof(student));
        if(newStd != NULL)
        {
            // insert records into database
            return SDB_InsertStudentRecordes(newStd);
        }
        return false;
    }
}
// function for accepting new student records from user, adding it to database
bool SDB_InsertStudentRecordes(student* newStd)
{
        uint32 id, year,
        course1_ID, course1_grade,
        course2_ID, course2_grade,
        course3_ID, course3_grade;

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

        // binding data entered from user to new student allocation
        newStd->Student_ID = id;
        newStd->Student_year = year;
        newStd->Course1_ID = course1_ID;
        newStd->Course1_grade = course1_grade;
        newStd->Course2_ID = course2_ID;
        newStd->Course2_grade = course2_grade;
        newStd->Course3_ID = course3_ID;
        newStd->Course3_grade = course3_grade;
        newStd->link = NULL; // last node

        // Check if the list is empty (start is NULL)
         if (start == NULL) {
         start = newStd;  // If the list is empty, the new student becomes the first node
         } else {
         student* temp = start;
        // finding the end of the list
        while (temp->link != NULL) {
            temp = temp->link;
        }
        // link the last node to the new node
        temp->link = newStd;
        }
        return true;
}

// function to delete student record from database with it's id
void SDB_DeletEntry(uint32 id)
 {
     // empty db
    if(start == NULL)
    {
        printf("No student records found. \n");
        return;
    }
    // check whether student with that id exists in db or not
    if(!SDB_IsIdExist(id))
    {
        printf("No such student record with that id was found. \n");
        return;
    }
    // database minimum length is 3
    if(SDB_GetUsedSize()<= MIN_STD)
    {
        printf("No. of student records must be 3 or more. \n");
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
            free(temp); // remove from db
            printf("student with ID: %d deleted successfully.\n",id);
            return;
        }
        prev = temp;
        temp = temp -> link;
    }
 }

 // function to get student data with it's id
bool SDB_ReadEntry (uint32 id)
 {
     // check if this student exists in db
    if(SDB_IsIdExist(id))
    {
        student* temp = start;
        // go through db to get student records
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

 // function to display student records
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

/*
function to get list of ids in database
*/
void SDB_GetList (uint8 * count, uint32 * list)
 {
    *count = SDB_GetUsedSize(); // get count of students in db
    student* std = start; // pointer to start of db
    uint8 i = 0;
    // looping through db
    while (std != NULL)
    {
        list[i++] = std -> Student_ID; // store student id in the list
        std = std -> link; // move to next student
    }
 }

 // function to check if student exists in db or not
bool SDB_IsIdExist (uint32 id)
{
    student* std = start; // pointer to start of db
    while (std != NULL) // looping through all db records
    {
        if(std -> Student_ID == id) // student was dound
        {
            return true;
        }
        std = std -> link; //student not found move to the next
    }
    return false;
}
