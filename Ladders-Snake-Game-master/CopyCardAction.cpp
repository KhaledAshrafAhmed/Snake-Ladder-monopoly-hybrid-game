#include "CopyCardAction.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Choose the card you want to copy");
	CellPosition cardPosition = pIn->GetCellClicked();
	Cell C(cardPosition);
	if (cardPosition.IsValidCell()) {
		C.SetGameObject(pGrid->GetObjectFromCell(cardPosition));
		pCard = C.HasCard();
		if (pCard) {
			cardNumber = pCard->GetCardNumber();
		}
		else {
			pOut->PrintMessage("Error there isn't a card!");
		}
	}
	else {
		pOut->PrintMessage("Erorr this isn't a valid cell!");
	}
}

void CopyCardAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	if (pCard) {
		pGrid->SetClipboard(pCard);
		pOut->PrintMessage("The card is copied!");
	}
}

CopyCardAction::~CopyCardAction()
{

}
