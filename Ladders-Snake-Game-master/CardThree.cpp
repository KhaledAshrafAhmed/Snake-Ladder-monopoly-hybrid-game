#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You stepped on card 3, roll your dice again!");
	pPlayer->setTurnCount(pPlayer->GetTurnCount() - 1);
}

CardThree::~CardThree()
{
}
