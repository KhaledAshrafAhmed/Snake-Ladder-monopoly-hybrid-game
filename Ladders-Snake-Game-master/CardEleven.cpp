#include "CardEleven.h"

CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;
}

int CardEleven::getFees()
{
	return Fees;
}

bool CardEleven::getBought()
{
	return Bought;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter the price of Card 11: ");
	cardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter the Fees of Card 11: ");
	Fees = pIn->GetInteger(pOut);

}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (cardPrice == 0) {
		ReadCardParameters(pGrid);
	}
	if (!Bought) {
		pOut->PrintMessage("Do you want to buy card 11?(Y/N) ");
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

CardEleven::~CardEleven()
{
}
