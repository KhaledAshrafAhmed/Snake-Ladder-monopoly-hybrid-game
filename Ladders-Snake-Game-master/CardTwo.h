#pragma once
#include"Card.h"
#include"Ladder.h"
class CardTwo: public Card
{
	// CardTwo Parameters:
	int stepsToNextLadder; // number of step untill the next ladder

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	 void setSteps(Grid* pGrid); // sets the parameters of CardTwo which is: stepsTotheNextLadder

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardTwo(); // A Virtual Destructor


};

