#pragma once
#include "Card.h"
#include "CardEleven.h"
#include "CardNine.h"
#include "CardTen.h"
class CardTwelve : public Card
{
	int maxFees;
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member
	CardTwelve(); // A Virtual Destructor
};

