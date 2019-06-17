/*
 * This should contain the implementation of the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file


#include "TodoPlayer.h"


//your code goes here
#include "TodoRestaurant.h"
TodoPlayerModel::TodoPlayerModel(string name, int cash, Color color): PlayerModel(name, cash, color),restaurantCount(0){

}

TodoPlayerModel::~TodoPlayerModel(){

}

int TodoPlayerModel::getRestaurantCount() const{
	return restaurantCount;
}

bool TodoPlayerModel::isOwning(PropertyModel* pm) const{		//test priority:low
	for(int i=0; i<propertyCount; i++){
		if(pm==properties[i])
			return true;
	}
	return false;
}

void TodoPlayerModel::gainProperty(PropertyModel* pm){		//decrements cash automatically, testing priority:medium
	if(dynamic_cast<TodoRestaurantModel*>(pm))
		restaurantCount++;

	propertyCount++;
	PropertyModel** temp= new PropertyModel*[propertyCount];
	for(int i=0;i<propertyCount-1;i++){
		temp[i]=properties[i];
	}
	temp[propertyCount-1]=pm;
	delete [] properties;
	properties=temp;

	cash= cash- pm->getRate();			//make sure getRate() is called before property is updated
}
