/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 6 : Binary Search Tree
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/25/2021
*******************************************************************************/

#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <string>

using namespace std;

class EmployeeInfo
{
private:
    int idNumber;           // IN - employee ID
    string employeeName;    // IN - employee Name
public:
    /******************************
     * CONSTRUCTORS & DESTRUCTORS *
     ******************************/
    EmployeeInfo(int id, string name) { idNumber = id; employeeName = name; };

    /*************
     * ACCESSORS *
     *************/
    string getName() const { return this->employeeName; };
    int getID() const { return this->idNumber; };
};

#endif // EMPLOYEEINFO_H
