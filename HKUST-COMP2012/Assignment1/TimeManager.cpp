//submit this file.
//you must use this exact file name.

#include <iostream>
#include<string>
#include "TimeManager.h"

TimeManager::TimeManager(){
	personCount=0;
	persons=NULL;
}

TimeManager::~TimeManager(){
	for(int i=0; i<personCount; i++){
		delete persons[i];
	}
	delete persons;
}

bool TimeManager::addPerson(string name){
	for(int i=0; i<personCount; i++){
		if(name==persons[i]->getName())
			return false;
	}
	Person** tempManager;
	personCount++;
	tempManager= new Person*[personCount];
	if(persons!=NULL){
		for(int i=0; i<personCount-1;i++){
			tempManager[i]=persons[i];
		}
		delete persons;
	}
	tempManager[personCount-1]=new Person(name);
	persons=tempManager;
	return true;
}

bool TimeManager::removePerson(string name){
	if(personCount==1 && name==persons[0]->getName()){
		delete persons[0];
		personCount=personCount-1;
		persons=NULL;
		return true;
	}
	for(int i=0; i<personCount; i++){
		if(name==persons[i]->getName()){
			Person** tempManager= new Person*[personCount-1];
			personCount=personCount-1;
			for(int j=0,k=0; j<personCount+1; j++,k++){
				if(j==i){
					k=k-1;
					delete persons[j];
					continue;
				}
				tempManager[k]=persons[j];
			}
			delete persons;
			persons=tempManager;
			return true;
		}
	}
	return false;
}

bool TimeManager::addActivityForPerson(string personName, const Activity & activity){ //nottested
	for(int i=0; i<personCount; i++){
		if(personName==persons[i]->getName()){
			return persons[i]->addActivity(activity);
		}
	}
	return false;
}

bool TimeManager::removeActivityForPerson(string personName, string activityName){ 	//not tested
	for(int i=0; i<personCount; i++){
		if(personName==persons[i]->getName())
			return persons[i]->removeActivity(activityName);
	}
	return false;
}

bool TimeManager::doesPersonExist(string personName) const{							//not tested
	for(int i=0; i<personCount; i++){
		if(personName==persons[i]->getName())
			return true;
	}
	return false;
}

int longestCommonSlot(const Person *const*const persons, const int personCount, int startTime){
	int endTime;
	for(int end=startTime; end<24; end++){
		for(int j=0; j<personCount; j++){
			if(!persons[j]->isFreeAtHour(end))
				return end;
		}
		endTime=end+1;
	}
	return endTime;
}

int numberOfSlots(const Person *const*const persons, const int personCount){
	int number=0;
	for(int i=0; i<24; i++){
		if(!(i==longestCommonSlot(persons, personCount, i))){
			number++; i=longestCommonSlot(persons,personCount,i)-1;
		}
	}
	return number;
}

Timeslot* findCommonSlot(const Person*const*const persons, const int personCount, int startTime){
	Timeslot* timeslot=NULL;
	for(int i=startTime; i<24; i++){
		if(!(i==longestCommonSlot(persons, personCount, i))){
			timeslot=new Timeslot(i,longestCommonSlot(persons, personCount,i));
			return timeslot;
		}
	}
	return timeslot;
}
Timeslot* TimeManager::findFirstCommonTimeslot() const{
	return findCommonSlot(persons, personCount, 0);
}

void TimeManager::findAllCommonTimeslots(Timeslot**&results, int & timeslotCount) const{
	timeslotCount=numberOfSlots(persons, personCount); results=NULL;
	if(timeslotCount!=0){
		results= new Timeslot*[timeslotCount];
		for(int i=0,j=0; i<24; i++){
			if(!(i==longestCommonSlot(persons, personCount, i))){
				results[j]=findCommonSlot(persons, personCount, i); j++;
				i=longestCommonSlot(persons,personCount,i)-1;
			}
		}
	}
}
