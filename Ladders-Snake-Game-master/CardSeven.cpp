#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	cp.SetHCell(0);
	cp.SetVCell(8);
	pGrid->UpdatePlayerCell(pPlayer, cp);
}

CardSeven::~CardSeven()
{
}