#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

enum ObjectType {
	LaddersType,
	SnakesType,
	CardsType
};

GameObject::~GameObject()
{
}