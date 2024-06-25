#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{

}

void CardTwo::setSteps(Grid* pGrid)
{
	Ladder* p = pGrid->GetNextLadder(this->GetPosition());
	int LadderPosiition = p->GetPosition().GetCellNum();
	stepsToNextLadder = LadderPosiition - (this->GetPosition().GetCellNum());
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, stepsToNextLadder);

}