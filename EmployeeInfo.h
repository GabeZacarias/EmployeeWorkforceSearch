#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class EmployeeInfo
{
private:
    int EmployeeID;
    string EmployeeName;

public:
    EmployeeInfo(){}
    EmployeeInfo(int, string);
    ~EmployeeInfo();
    int getEmployeeID();
    string getEmployeeName();
    void setEmployeeID(int);
    void setEmployeeName(string);
    bool operator ==(const EmployeeInfo &eO1) { return EmployeeID == eO1.EmployeeID; }
    bool operator >(const EmployeeInfo &eO1) { return EmployeeID > eO1.EmployeeID; }
    bool operator <(const EmployeeInfo &eO1) { return EmployeeID < eO1.EmployeeID; }
    friend ostream &operator<<(ostream &strm, EmployeeInfo &obj)
    {
        strm << " ID Number: " << obj.EmployeeID << "\tName: " << obj.EmployeeName << endl;
        return strm;
    }

};

EmployeeInfo::EmployeeInfo(int empID, string name)
{
    EmployeeID = empID;
    EmployeeName = name;
}

EmployeeInfo::~EmployeeInfo()
{
}

int EmployeeInfo::getEmployeeID()
{
    return EmployeeID;
}

string EmployeeInfo::getEmployeeName()
{
    return EmployeeName;
}

void EmployeeInfo::setEmployeeID(int empID)
{
    EmployeeID = empID;
}

void EmployeeInfo::setEmployeeName(string name)
{
    EmployeeName = name;
}

#endif
