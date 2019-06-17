//submit this file.
//you must use this exact file name.

#include "Activity.h"	//needs Testing

Activity::Activity(string name, const Timeslot& timeslot):timeslot(timeslot.getStartTime(), timeslot.getEndTime()){
	this->name=name;
}

string Activity::getName() const{
	return name;
}

const Timeslot& Activity::getTimeslot() const{
	return timeslot;
}
