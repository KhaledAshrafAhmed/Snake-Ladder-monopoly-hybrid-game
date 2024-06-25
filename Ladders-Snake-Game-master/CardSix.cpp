#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pout->PrintMessage("Choose Grid to move to:");
	cp = pin->GetCellClicked();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	ReadCardParameters(pGrid);
	Input* pin = pGrid->GetInput();
	pGrid->UpdatePlayerCell(pPlayer, cp);
}

Card6::~CardSix()
{
}