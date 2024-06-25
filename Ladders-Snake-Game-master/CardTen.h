#pragma once
#include "Card.h"
class CardTen :   public Card
{
	
	int cardPrice = 0;
	int Fees = 0;
	bool Bought = 0;
	int cardOwner;
	Player* pOwner;
public:
	CardTen(const CellPosition& pos); // A Constructor takes card position
	int getFees();

	bool getBought();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member

	virtual ~CardTen(); // A Virtual Destructor
};

