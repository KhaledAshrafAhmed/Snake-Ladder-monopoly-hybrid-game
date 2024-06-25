#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Choose how much a player should pay to get out of prison: ");
	Fees = pIn->GetInteger(pOut);
	
	
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{	
	Card::Apply(pGrid, pPlayer);
	ReadCardParameters(pGrid);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You stepped in the prison, either pay" + to_string(Fees) + " or stay 3 turns(Y/N)");
	string pay;
	pay = pIn->GetSrting(pOut);
	if (pay == "Y") {
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);

	}
	else {
		pPlayer->setIsJailed(true);
		pPlayer->setJailedTurns(3);
	}
}

CardEight::~CardEight()
{
}
