#include "StudentList.h"
#include <algorithm>
StudentList::StudentList(int num, string * nameLister){
	for(int i=0; i<num; i++){
		addStudent(nameLister[i]);
	}
}

bool StudentList::findStudent(const string &name) const{
	list<string>::iterator p;
	if(nameList.begin()!=nameList.end()){
		if(nameList.end() != find(nameList.begin(), nameList.end(), name))
			return true;
	}
	return false;
}
bool StudentList::addStudent(const string& name){
	if(!findStudent(name)){
		nameList.push_back(name);
		return true;
	}
	return false;
}

bool StudentList::deleteStudent(const string & name){
	if(findStudent(name)){
		nameList.remove(name);
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const StudentList& stlist){
	os<<'[';
	for(list<string>::const_iterator p= stlist.nameList.begin(); p!=stlist.nameList.end(); p++){
		if(p!=stlist.nameList.begin())
			os<<", ";
		os<<(*p);

	}

	return os<<']';
}
