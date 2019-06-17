/*
 * This should contain the class of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODORESTAURANTMODEL_H_
#define TODORESTAURANTMODEL_H_

//your code goes here
#include "TodoProperty.h"

class TodoRestaurantModel : public TodoPropertyModel{
public:
	TodoRestaurantModel(string name, int price, Color color);
	~TodoRestaurantModel();

	virtual void action(PlayerModel * p, const BoardController& b);
	virtual int getRate() const;
};
#endif /* TODORESTAURANTMODEL_H_ */
