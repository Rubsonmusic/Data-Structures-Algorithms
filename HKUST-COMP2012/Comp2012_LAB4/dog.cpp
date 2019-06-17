#include "dog.h"

using namespace std;

Dog::Dog(int hb, int mhb, int minhb, int s, int w):Heart(hb,mhb,minhb),speed(s),weight(w){
	cout<<"Dog is constructed\n"<<endl;
}

Dog::~Dog(){
	cout<<"Dog is destructed"<<endl;
}

void Dog::move(int time){
	cout<<"The dog moved "<<(time*speed)<<"m in "<<time<<" seconds"<<endl;
}

void Dog::print(){
	print_heart_info();
	cout<<"\tweight: "<<weight<<"\tspeed: "<<speed<<endl;
}

int Dog::check_heartbeat(){
	return Heart::check_heartbeat();
}
int Dog::get_max_heartbeat(){
	return Heart::check_heartbeat();
}
int Dog::get_min_heartbeat(){
	return Heart::get_min_heartbeat();
}

int Dog::get_weight(){
	return weight;
}
int Dog::get_speed(){
	return speed;
}

void Dog::boost_heartbeat(){
	Heart::boost_heartbeat();
}
void Dog::decrease_heartbeat(){
	Heart::decrease_heartbeat();
}
