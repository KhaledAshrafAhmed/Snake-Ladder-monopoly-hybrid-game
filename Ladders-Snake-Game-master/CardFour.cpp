#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You stepped on card four, your next turn will be skipped");
	pPlayer->setNextTurn(false);
}

CardFour::~CardFour()
{
}
