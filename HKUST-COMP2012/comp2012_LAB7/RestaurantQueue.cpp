#include "RestaurantQueue.h"

void RestaurantQueue::addStudent(const string & name){
	cout<<name<<" gets into queue"<<endl;
	nameQueue.push(name);
}

void RestaurantQueue::serveStudent(){
	if(waitNum()>0){
		cout<<nameQueue.front(); cout<<" is served"<<endl;
		nameQueue.pop();
	}
	else{
		cout<<"Current queue is empty"<<endl;
	}
}

int RestaurantQueue::waitNum() const{

	return nameQueue.size();
}
