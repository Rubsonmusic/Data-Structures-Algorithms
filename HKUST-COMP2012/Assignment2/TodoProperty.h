/*
 * This should contain the class of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file


#ifndef TODOPROPERTY_H_
#define TODOPROPERTY_H_

//your code goes here
#include "Property.h"
#include "Board.h"
#include "Player.h"
#include "TodoPlayer.h"
class TodoPropertyModel : public PropertyModel{
public:
	TodoPropertyModel(string name, int price, Color color);
	~TodoPropertyModel();

	virtual void action(PlayerModel * p, const BoardController& b);
	virtual int getRate() const;
};
#endif /* TODOPROPERTY_H_ */
