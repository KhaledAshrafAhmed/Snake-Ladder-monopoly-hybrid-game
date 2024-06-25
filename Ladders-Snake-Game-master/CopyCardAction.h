#pragma once
#include "Action.h"
#include "AddCardAction.h"
#include "Card.h"
class CopyCardAction : public Action
{
    int cardNumber;
    Card* pCard = NULL;
public:
    CopyCardAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~CopyCardAction();
};

