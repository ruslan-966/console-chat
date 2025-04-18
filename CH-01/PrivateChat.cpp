#include "PrivateChat.h"

PrivateChat::PrivateChat(int firstPartNumber, int secondPartNumber) 
{
	if (firstPartNumber < secondPartNumber) 
	{
		_firstPartNumber = firstPartNumber;
		_secondPartNumber = secondPartNumber;
	}
	else
	{
		_firstPartNumber =  secondPartNumber;
		_secondPartNumber = firstPartNumber;
	}
}

void PrivateChat::setMesNumber(int mesNumber)
{
	_massive.add(std::move(mesNumber));
}

bool PrivateChat::isItRightChat(int userNumber)
{
	if (userNumber == _firstPartNumber || userNumber == _secondPartNumber)
			return true;
	
	return false;
}

int PrivateChat::getAnotherUser(int userNumber)
{
	if (_firstPartNumber == userNumber)
		return _secondPartNumber;
	return _firstPartNumber;
}

bool PrivateChat::isTwoUsersOk(int frstUserNum, int secondUserNum)
{
	if (frstUserNum == _firstPartNumber && secondUserNum == _secondPartNumber)
		return true;
	if (frstUserNum == _secondPartNumber && secondUserNum == _firstPartNumber)
		return true;
	return false;
}

Array<int> PrivateChat::getArr()
{
	return _massive;
}

