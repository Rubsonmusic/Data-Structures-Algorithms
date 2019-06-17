//submit this file.
//you must use this exact file name.

#include "Person.h"

Person::Person(string name){
	activityCount=0;
	this->name= name;
	activities=NULL;
}

Person::~Person(){
	for(int i=0;i<activityCount; i++){
		delete activities[i];
	}
	delete activities;
}

string Person::getName()const{
	return name;
}

bool Person::addActivity(const Activity& activity){		//needs thorough testing
	if(activities!=NULL){
		for(int i=0; i<activityCount; i++){
			if(activity.getName()==activities[i]->getName() || activity.getTimeslot().hasConflictsWith(activities[i]->getTimeslot()))
				return false;
		}
	}
	if(activities==NULL){
		activities  = new Activity*[1];
		activities[0]= new Activity(activity.getName(), activity.getTimeslot());
		activityCount++;
		return true;
	}
	else if(activities!=NULL){
		activityCount++;
		Activity ** tempAct= activities;
		activities= new Activity*[activityCount];

		int startTime1= activity.getTimeslot().getStartTime();
		int index=activityCount-1;
		if(startTime1 < tempAct[0]->getTimeslot().getStartTime()){
			index=0;
		}
		else{
			for(int i=0; i<activityCount-2; i++){
				if(startTime1 > tempAct[i]->getTimeslot().getStartTime() && startTime1 < tempAct[i+1]->getTimeslot().getStartTime()){
					index=i+1;
				}
			}
		}
		for(int i=0,j=0; i<activityCount; j++,i++){
			if(i==index){
				activities[i]= new Activity(activity.getName(), activity.getTimeslot());
				if(index==activityCount-1)
					break;
				i++;
			}
			activities[i]= tempAct[j];
		}
		delete tempAct;
		return true;

	}
	return false;
}

bool Person::removeActivity(string ActivityName){
	if(activityCount==0 && ActivityName==activities[0]->getName()){
		delete activities[0];
		activities=NULL;
		activityCount=activityCount-1;
		return true;
	}
	for(int i=0; i<activityCount; i++){
		if(ActivityName==activities[i]->getName()){
			delete activities[i];
			activityCount=activityCount-1;
			Activity ** tempAct= new Activity*[activityCount];
			for (int j=0,k=0; j<activityCount+1; j++,k++){
				if(j==i){
					k=k-1;
					continue;
				}
				tempAct[k]= activities[j];
			}
			delete activities;
			activities=tempAct;
			return true;
		}
	}
	return false;

}

bool Person::isFreeAtHour(int hour) const{
	Timeslot hours(hour,hour+1);
	for(int i=0; i<activityCount; i++){
		if(hours.hasConflictsWith(activities[i]->getTimeslot())){
			return false;
		}
	}
	return true;
}
