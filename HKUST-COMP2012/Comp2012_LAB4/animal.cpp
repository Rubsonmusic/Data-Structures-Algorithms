#include "animal.h"

using namespace std;

Animal::Animal(int heartbeat, int max_heartbeat, int min_heartbeat, int weight,
		int num_of_legs):heart(heartbeat, max_heartbeat, min_heartbeat){
	this->weight=weight; this->num_of_legs=num_of_legs;
	cout<<"animal is constructed"<<endl;
}

Animal::~Animal(){
	cout<<"Destructor of animal"<<endl;
}

void Animal::grow(int weight){
	this->weight+=weight;
	cout<<"This animal grew by "<<weight<<"kgs and now it's weight is "<<this->weight<<endl;
}

void Animal::print(){
	cout<<"heatbeat: "<<heart.check_heartbeat()<<
			"\tmax_heartbeat: "<<heart.get_max_heartbeat()<<
			" 	min_heartbeat: "<<heart.get_min_heartbeat()<<
			" 	weight: "<<weight<<" 	num_of_legs: "<<num_of_legs<<endl;
}

int Animal::check_heartbeat(){
	return heart.check_heartbeat();
}

int Animal::get_max_heartbeat(){
	return heart.get_max_heartbeat();
}

int Animal::get_min_heartbeat(){
	return heart.get_min_heartbeat();
}

int Animal::get_legs(){
	return num_of_legs;
}
int Animal::get_weight(){
	return weight;
}
