#pragma once
#include "Action.h"
#include "AddCardAction.h"
#include "CopyCardAction.h"
#include "Card.h"
class CutCardAction : public Action
{
    Card* pCard = NULL;
    int cardNumber;
public:
    CutCardAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~CutCardAction();
};

