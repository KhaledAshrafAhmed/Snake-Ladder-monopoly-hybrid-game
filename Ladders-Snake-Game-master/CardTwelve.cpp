#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You landed on Card Twelve, your most expensive station will be transfer to the player with the least wallet!");
	pPlayer = pGrid->GetCurrentPlayer();

}

CardTwelve::CardTwelve()
{
}
