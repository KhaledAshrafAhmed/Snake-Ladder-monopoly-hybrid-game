#pragma once
#include "Card.h"
class CardNine : public Card
{
	int cardPrice = 0;
	int Fees = 0;
	bool Bought = 0;
	int cardOwner;
	Player* pOwner;
public:

	CardNine(const CellPosition& pos); // A Constructor takes card position

	int getFees();

	bool getBought();

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardNine();
};

