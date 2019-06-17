/*
 * This should contain the implementation of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file

//your code goes here

#include "TodoRestaurant.h"
#include <string>
#include <sstream>

TodoRestaurantModel::TodoRestaurantModel(string name, int price, Color color):TodoPropertyModel(name,price,color){

}

TodoRestaurantModel::~TodoRestaurantModel(){

}

int TodoRestaurantModel::getRate() const{			//testing priority: high
	if(owner==NULL)
		return price;
	else{
		return dynamic_cast<TodoPlayerModel*>(owner)->getRestaurantCount()*price;
	}
}

void TodoRestaurantModel::action(PlayerModel *p, const BoardController& b){		//testing priority: high
	if(owner==NULL){
		int option;
		stringstream s;
		s << "Do you want to buy " << name <<"?";
		const string options[2] = {"Yes" , "No"};

		option = b.requestInput(s.str(), options, 2);
		if (option == 0 && (p->getCash()>=price)) {
				p->gainProperty(this);
				owner=p; color=p->getColor();
				string message= "restaurant bought by"; message.append(p->getName());
				b.prompt(message);
		}
		else {
			b.prompt("Nothing happeneda");
		}
	}
	else if(owner==p){
		b.prompt("nothing happens");
	}
	else if(owner!=NULL && owner!=p){
		int rent= getRate();
		p->pay(rent);
		owner->collect(rent);
		b.prompt("payed rent");
	}
	else
		b.prompt("Nothing happened");
}


