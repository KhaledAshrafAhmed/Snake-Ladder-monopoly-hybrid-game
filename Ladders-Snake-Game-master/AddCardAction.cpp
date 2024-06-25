#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	pManager = pApp;
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("New Card: Enter the card number(1 to 12): ");
	cardNumber = pIn->GetInteger(pOut);

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click on the cell you want to place the card on: ");
	cardPosition = pIn->GetCellClicked();
	
	// 4- Make the needed validations on the read parameters
	if (cardPosition.IsValidCell() && cardNumber >= 1 && cardNumber <= 12) {
		pOut->PrintMessage("Error this isn't a cell location!");
		pOut->ClearStatusBar();
		return;
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;

		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		Output* pOut = pGrid->GetOutput();
		bool added = pGrid->AddObjectToCell(pCard);
		
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added && cardPosition.IsValidCell()) {
			pOut->PrintMessage("ERROR! Cell already has an object!");
		}
		else if (!cardPosition.IsValidCell()) {
			pOut->PrintMessage("Error! this is not a valid cell!");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
	
}
