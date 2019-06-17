/*
 * Timeslot.cpp
 */

#include "timeslot.h"


 // Initialize the static variable
string Timeslot::weekday_string[] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

// Constructor
Timeslot::Timeslot(weekday d1, weekday d2, int stime, int etime)
        : day1(d1), day2(d2), start(stime), end(etime) { }

// Accessors
bool Timeslot::match(weekday day) const
{
    return (day == day1 || day == day2);
}


bool Timeslot::match(int stime, int etime) const
{
    return (start == stime && end == etime);
}



/* TODO
 * Convert the day in enum type to a printable string
 * using the static string weekday_string[5].
 */
string Timeslot::convert(weekday day) const
{
	string r= weekday_string[day];
	return r;
}

/* TODO
 * Please refer to the sample output for output format
 */
ostream& operator<<(ostream& os, const Timeslot& time)
{
	if(time.start<10){
		os<<time.convert(time.day1)<<"|"<<time.convert(time.day2)<<" [0"<<time.start;
	}
	else{
		os<<time.convert(time.day1)<<"|"<<time.convert(time.day2)<<" ["<<time.start;
	}
	if(time.end<10){
		os<<":00--0"<<time.end<<":00]";
	}
	else{
		os<<":00--"<<time.end<<":00]";
	}

	return os;
}
