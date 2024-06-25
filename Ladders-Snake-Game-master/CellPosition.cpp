#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if (8 < v || v <= -1) {
		return false;
	}                             //////////////////////khaled
	else {
		vCell = v;
		return true;
	}                   // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if (10 < h || h <= -1) {
		return false;
	}                            /////////khaled
	else {
		hCell = h;
		return true;
	}
	// this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if ((0 <= hCell && hCell <= 10) && (0 <= vCell && vCell <= 8)) {
		return true;
	}
	else {
		return false;
	}

	// this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellnum = ((8 - cellPosition.VCell()) * 11) + (cellPosition.HCell() + 1); //////////////////// khaled


	return cellnum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	int HCell = 0;
	int VCell = 8;
	for (int i = 2; i < cellNum + 1; i++) {
		HCell++;
		if (HCell == 11) {
			VCell--;
			HCell = 0;
		}
	}
	position.SetHCell(HCell);
	position.SetVCell(VCell);
	return position;


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int cellNum = GetCellNum() + addedNum;
	if (89 <= cellNum <= 99) {
		SetVCell(0);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (78 <= cellNum <= 88) {
		SetVCell(1);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (67 <= cellNum <= 77) {
		SetVCell(2);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (56 <= cellNum <= 66) {
		SetVCell(3);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (45 <= cellNum <= 55) {
		SetVCell(4);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (34 <= cellNum <= 44) {
		SetVCell(5);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (23 <= cellNum <= 33) {
		SetVCell(6);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (12 <= cellNum <= 22) {
		SetVCell(7);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}
	if (1 <= cellNum <= 11) {
		SetVCell(8);
		SetHCell(cellNum + (11 * VCell()) - 89);
	}


	// Note: this function updates the data members (vCell and hCell) of the calling object

}
