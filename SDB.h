#ifndef SDB_H
#define SDB_H

#define MAX_STD 10
#define MIN_STD 3

#include "STD.h"


typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    struct SimpleDb* link;
}student;

bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
bool SDB_InsertStudentRecordes(student* newStd);
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
void SDB_DisplayStudentRecordes(student* newStd);
void SDB_GetList (uint8 * count, uint32 * list);
bool SDB_IsIdExist (uint32 id);

#endif
