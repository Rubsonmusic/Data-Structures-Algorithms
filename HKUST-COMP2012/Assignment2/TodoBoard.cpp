/*
 * This should contain the implementation of the class of TodoBoard.
 */

//You need to submit this file
//You need to modify this file

#include "TodoBoard.h"

//your code goes here

#include "TodoPlace.h"
#include <string>
#include <sstream>
using namespace std;
TodoBoardController::TodoBoardController(){

}

TodoBoardController::~TodoBoardController(){

}

void TodoBoardController::run(){
	int turn = 0;
	prompt("Game started");

	while (!checkBankrupt()) {			//test test test test
		//Print Board
		printBoard();

		//Roll dice
		int dice = rollDice();
		PlayerModel* thisTurnPlayer = players[turn];
		int currentPosition= thisTurnPlayer->getPosition();
		stringstream s;
		s << thisTurnPlayer->getName() << ", it is your turn." << endl;
		view.appendMessage(s.str());
		view.displayPlayer(thisTurnPlayer);


		//move player
		thisTurnPlayer->move(dice);
		printBoard();

		//give place money
		for(int i=currentPosition+1; i<=currentPosition+dice-1; i++){
			if(dynamic_cast<TodoPlaceModel*>(cells[i%16])){				//check if i need to #include "TodoPlace.h"
				cells[i%16]->action(thisTurnPlayer, *this);
			}

		}

		//rob money
		if(players[(turn+1)%NUMBER_PLAYERS]->getPosition()==((currentPosition+dice)%16)){
			players[(turn+1)%NUMBER_PLAYERS]->pay(ROB_CASH);
			thisTurnPlayer->collect(ROB_CASH);
			view.appendMessage("robbery");
		}
		if(players[(turn+2)%NUMBER_PLAYERS]->getPosition()==((currentPosition+dice)%16)){
			players[(turn+2)%NUMBER_PLAYERS]->pay(ROB_CASH);
			thisTurnPlayer->collect(ROB_CASH);
			view.appendMessage("robbery");
		}


		//Move and Trigger Event
		cells[thisTurnPlayer->getPosition()]->action(thisTurnPlayer, *this);

		printBoard();
		view.displayPlayer(thisTurnPlayer); //refresh
		prompt("onto the next turn");

		//Next player
		turn = (turn + 1) % NUMBER_PLAYERS;
	}
	prompt("End of Game");

}


