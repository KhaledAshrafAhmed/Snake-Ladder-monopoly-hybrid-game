#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Choose the card you want to copy");
	CellPosition cardPosition = pIn->GetCellClicked();
	if (cardPosition.IsValidCell()) {
		Cell C(cardPosition);
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
		pOut->PrintMessage("Error this isn't a valid cell!");
		
	}
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	if (pCard) {
		pGrid->SetClipboard(pCard);
		pGrid->RemoveObjectFromCell(pCard->GetPosition());
		pOut->PrintMessage("The card is cut!");
	}
	
}

CutCardAction::~CutCardAction()
{
}
