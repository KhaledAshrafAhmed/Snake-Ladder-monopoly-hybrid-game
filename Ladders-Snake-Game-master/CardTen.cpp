#include "CardTen.h"

CardTen::CardTen(const CellPosition& pos) : Card(pos)
{
	cardNumber = 10;
}

int CardTen::getFees()
{
	return Fees;
}

bool CardTen::getBought()
{
	return Bought;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter the price of Card 10: ");
	cardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter the Fees of Card 10: ");
	Fees = pIn->GetInteger(pOut);

}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (cardPrice == 0) {
		ReadCardParameters(pGrid);
	}
	if (!Bought) {
		pOut->PrintMessage("Do you want to buy card 10?(Y/N) ");
		string Buy = pIn->GetSrting(pOut);
		if (Buy == "Y") {
			pPlayer->SetWallet(pPlayer->GetWallet() - cardPrice);
			pOwner = pPlayer;
			cardOwner = pPlayer->GetTurnCount();
			pPlayer->setOwnedCard(cardNumber);
		}
	}
	else {
		pOut->PrintMessage("You stepped into a player's station " + to_string(Fees) + " is deducted.");
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
		pOwner->SetWallet(pOwner->GetWallet() + Fees);
		
	}
}

CardTen::~CardTen()
{
}
