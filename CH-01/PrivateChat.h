#pragma once
#include "Array.h"

class PrivateChat
{
private:
	int _firstPartNumber{0};			//Ќомер  первого участника в DataManager
	int _secondPartNumber{0};			//Ќомер второго участника в DataManager
	int _lstMesOneNum{ 0 };				//Ќомер последнего выведенного сообдени€ в чате дл€ первого пользовател€
	int _lstMesSecondNum{0};			//Ќомер последнего выведенного сообдени€ в чате дл€ второго пользовател€
	Array<int> _massive;
	//int _massive[100]{};					//ћассив номеров сообщений из массива личных сообщений
	//int _count{0};						// оличество сообщений
public:
	PrivateChat() = default;
	PrivateChat(int, int);
	void setMesNumber(int);
	bool isItRightChat(int);			//возвращает информацию, есть ли пользователь в этом чате
	int getAnotherUser(int);			//возвращает номер второго пользовател€
};
