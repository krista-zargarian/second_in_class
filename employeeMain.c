#include <string.h>
#include <stdlib.h>
#include "employee.h"

//In order to run must compile: employeeMain.c employeeTable.c employeeTwo.c
int main (void){
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, long salaryToFind);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber (EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
        if (matchPtr != NULL)
            printf("Employee is in record %d\n", matchPtr - EmployeeTable);
        else
            printf("Employee is NOT found in the record\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235" );
        if (matchPtr != NULL)
            printf("Employee phone number 909-555-1235 is in record %d\n", matchPtr - EmployeeTable);
        else
            printf("Employee phone number is NOT found in the record\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "a" );
        if (matchPtr != NULL)
            printf("Employee's phone number 909-555-1235 is in record %d\n", matchPtr - EmployeeTable);
        else
            printf("Employee's phone number is NOT found in the recond\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34 );
        if (matchPtr != NULL)
            printf("Employee salary $6.34 is in record %d\n", matchPtr-EmployeeTable);
        else 
            printf("Employee salary is NOT found within the record\n");

return EXIT_SUCCESS;
}
