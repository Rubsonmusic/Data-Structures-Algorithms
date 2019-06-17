#include "lion.h"

using namespace std;

Lion::Lion(int heartbeat, int max_heartbeat, int min_heartbeat,
		int weight, int num_of_legs, int speed):Animal(heartbeat,max_heartbeat,min_heartbeat,weight,num_of_legs){
	this->speed=speed;
	cout<<"Lion is constructed\n";
}

Lion::~Lion(){}

void Lion::move(int time){
	cout<<"The lion moved "<<(time*speed)<<"m in "<<time<<" seconds"<<endl;
}

void Lion::grow(int weight){
	Animal::grow(weight);
}

void Lion::print(){
	Animal::print();
}
