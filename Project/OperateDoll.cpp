#include "OperateDoll.h"

void OperateDoll::Initialize(){
	_doll->SetEndMoveMethod([&]() {return SetDollNextBlock();});
}

void OperateDoll::ReLoad(){
	_currentBlockNumber = 0;
	_routeBlockArray.clear();
}

void OperateDoll::SetRouteBlockArray(std::vector<Block*> blockArray)
{
	_routeBlockArray = blockArray;
	_doll->SetNextBlock(_routeBlockArray[_currentBlockNumber]);
}

void OperateDoll::SetDollNextBlock() {

	_currentBlockNumber++;

	if (_currentBlockNumber >= _routeBlockArray.size()) {
		_doll->EndMove();
		_currentBlockNumber = 0;
		return;
	}

	_doll->SetNextBlock(_routeBlockArray[_currentBlockNumber]);
}

void OperateDoll::Release(){

}