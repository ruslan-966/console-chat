#include <iostream>
#include <Windows.h>
#include <memory>
#include "PrivateMessage.h"
#include "CommonMessage.h"
#include "Array.h"
#include "User.h"
#include "ConversationManager.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Array <PrivateMessage> privateMessagePool;
	Array <CommonMessage> commonMessagePool;
	Array <User> allUsers;
	bool isRun = true;

	//собственно текст программы:
	unique_ptr<ConversationManager> cm{ make_unique<ConversationManager>() };		//создаем экземпляр менеджера обмена данных с пользователем
	cm->greeting();
	bool isItNextLoop = false;
	int uNum{-1};
	while (isRun)
	{
		char choice = cm->regOrComm();
		switch (choice)
		{
		case '1':
			if (isItNextLoop)
			{
				cm->cleanConsole();
			}
			isItNextLoop = true;
			cm->userRegistration(allUsers);
			break;
		case '2':
			if (isItNextLoop)
			{
				cm->cleanConsole();
				isItNextLoop = true;
			}
			else
			{
				std::cout << "\n\nНет зарегистрированных пользователей, начните с п.1.\n\n";
				break;
			}
			uNum = cm->usersInput(allUsers);		//номер зарегистрировавшегося пользователя из массива Users
			if (uNum > -1)
			{
				User user = allUsers[uNum];			//получаем запись этого пользователя
				cm->userMessChoise(user, allUsers, privateMessagePool, commonMessagePool);
			}
			break;
		case '3':
			std::cout << "\n\nРабота программы завершена.\n";
			isRun = false;
			break;
		}
	}
	return 0;
}