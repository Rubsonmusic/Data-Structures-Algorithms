/*
 * This should contain the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODOPLAYER_H_
#define TODOPLAYER_H_

//your code goes here

#include "Player.h"								//should this be here?
#include "Board.h"
#include "Property.h"


class TodoPlayerModel : public PlayerModel{
	public:
		TodoPlayerModel(string name, int cash, Color color);
		~TodoPlayerModel();
		virtual void gainProperty(PropertyModel * pm);
		virtual bool isOwning(PropertyModel *pm) const;
		int getRestaurantCount() const;
	private:
		int restaurantCount;
};

#endif /* TODOPLAYER_H_ */
