#include "corgi.h"

using namespace std;

Corgi::Corgi(int hb,int mhb,int minhb,int s,int w):Dog(hb,mhb,minhb,s,w){
	cout<<"Corgi is constructed"<<endl;
}

Corgi::~Corgi(){
	cout<<"Corgi has been destructed"<<endl;
}

void Corgi::print(){
	Dog::print();
}

void Corgi::move(int t){
	cout<<"The corgi moved "<<(t*Dog::get_speed())<<"m in "<<t<<" seconds"<<endl;
}

int Corgi::get_weight(){
	return Dog::get_weight();
}

int Corgi::get_speed(){
	return Dog::get_speed();
}

void Corgi::boost_heartbeat(){
	Dog::boost_heartbeat();
}
void Corgi::decrease_heartbeat(){
	Dog::decrease_heartbeat();
}
