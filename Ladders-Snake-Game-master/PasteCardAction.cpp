#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Choose the cell you want to add the object in: ");
	CellPosition pos = pIn->GetCellClicked();
	pCard = new Card(pos);
	Card* CopiedCard = pGrid->GetClipboard();
	if (CopiedCard) {
		pCard->SetCardNumber(CopiedCard->GetCardNumber());
	}
	else {
		pOut->PrintMessage("There is no card to paste!");
	}
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (pGrid->GetClipboard()) {
		bool added = pGrid->AddObjectToCell(pCard);
		if (!added) {
			pOut->PrintMessage("ERROR! There's a game object in that place already!");
		}
	}
}

PasteCardAction::~PasteCardAction()
{
}
