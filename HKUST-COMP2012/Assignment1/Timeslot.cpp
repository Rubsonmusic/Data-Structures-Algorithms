//submit this file.
//you must use this exact file name.

#include "Timeslot.h"

Timeslot::Timeslot(int startTime, int endTime){				//Doesn't check if this is a valid timeslot
	this->startTime= startTime;
	this->endTime= endTime;
}

int Timeslot::getEndTime() const{
	return endTime;
}

int Timeslot::getStartTime()const{
	return startTime;
}

bool Timeslot::hasConflictsWith(const Timeslot& another) const{
	if((startTime<=another.getStartTime() && endTime>another.getStartTime()) || (startTime<another.getEndTime() && endTime>=another.getEndTime())){
		return true;
	}

	else if(another.getStartTime()>startTime && another.getEndTime()>startTime && another.getStartTime()<endTime && another.getEndTime()<endTime){
		return true;
	}

	else if(another.getStartTime()<endTime && another.getEndTime()>endTime && another.getStartTime()<startTime && another.getEndTime()>startTime){
		return true;
	}
	else
		return false;
}

