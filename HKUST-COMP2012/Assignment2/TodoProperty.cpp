/*
 * This should contain the implementation of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file

#include "TodoProperty.h"



//your code goes here
#include <string>
#include <sstream>
TodoPropertyModel::TodoPropertyModel(string name, int price, Color color):PropertyModel(name,price,color){

}

TodoPropertyModel::~TodoPropertyModel(){

}

int TodoPropertyModel::getRate() const{
	if(owner==NULL)
		return price;
	else
		return (price*(houses+1)*3)/4;
}

void TodoPropertyModel::action(PlayerModel *p, const BoardController& b){		//testing priority: high
	if(owner==NULL){
		int option;
		stringstream s;
		s << "Do you want to buy " << name <<"?";
		const string options[2] = {"Yes" , "No"};

		option = b.requestInput(s.str(), options, 2);
		if (option == 0 && (p->getCash()>=price)) {
				p->gainProperty(this);
				owner=p;
				color=p->getColor();
				string message= "property bought by"; message.append(p->getName());
				b.prompt(message);
		}
		else {
				b.prompt("Nothing happened");
		}
	}
	else if(owner==p && houses!=5 && (p->getCash()>=BUILDING_COST)){
		houses++;
		p->pay(BUILDING_COST);
		b.prompt("payed building cost");
	}
	else if(owner!=NULL && owner!=p){
		int rent=getRate();
		p->pay(rent);
		owner->collect(rent);
		b.prompt("payed rent");
	}
	else
		b.prompt("Nothing happened");
}
