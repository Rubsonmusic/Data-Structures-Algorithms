#include "StudentIDMap.h"
#include <algorithm>

StudentIDMap::StudentIDMap(int nums, string * name, int * ID){
	for(int i=0; i<nums; i++){
		nameIDMap.insert(pair<string, int>(name[i], ID[i]));
	}
}

bool StudentIDMap::findStudent(const string & name) const{
	if(nameIDMap.end() != nameIDMap.find(name))
		return true;
	return false;
}

int StudentIDMap::getID(const string & name){
	map<string, int>::const_iterator p =nameIDMap.find(name);
	return p->second;
}

ostream& operator<<(ostream& os, const StudentIDMap& studentIDMap){
	os<<'{';
	for( map<string, int>::const_iterator p= studentIDMap.nameIDMap.begin(); p!=studentIDMap.nameIDMap.end(); p++){
		if(p!= studentIDMap.nameIDMap.begin())
			os<<", ";
		os<<'('<<p->first<<','<<p->second<<')';
	}
	os<<'}';
	return os;
}

