#ifndef LAB7_STL_STUDENTLIST_H
#define LAB7_STL_STUDENTLIST_H

#include <list>
#include <iostream>
using namespace std;

class StudentList {
public:
    StudentList(int num, string nameList[]);

    bool findStudent(const string& name) const;
    bool addStudent(const string& name);
    bool deleteStudent(const string& name);

    friend ostream& operator<<(ostream& os, const StudentList& studentList);

private:
    list<string> nameList;

};


#endif //LAB7_STL_STUDENTLIST_H
