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
				cm->cleanConsole();
			cm->userRegistration(allUsers);
			isItNextLoop = true;
			break;
		case '2':
			uNum = cm->usersInput(allUsers);
			if (uNum > -1)
			{
				User user = allUsers[uNum];
				cm->userMessChoise(user, allUsers, privateMessagePool, commonMessagePool);
			}
			break;
		case '3':
			std::cout << "\n\nРабота программы завершена.\n";
			isRun = false;
			break;
		}
	}


	
	// 1. Здесь приветствуем предалгаем ввести пользователя

	// 2. После ввода пользователя, закончить регистрацию 
	// 
	// Очищаем консоль и выводим общие сообщения и частные сообщения, если есть.
	// хочет ли он написать сообщения всем, если нет - предлагаем зарегистрировать еще одного пользователя

	// Если да - пункт 1 если нет - пункт 3
	//3. Ввод сообщения с пометкой - всем, заносим их в массив "общие сообщения"
	//3.1 Спрашиваем, хотите ли написать еще сообщение. Если нет - выход на страничку регистрация пользователя или нового пользователя

	//4. Статус - новый пользователь

	//5. Завершить работу программы

	//6. Если общее стообщение - уже видел это сообщение 

	//7.
	/*
	User* ptrUserFrom = new User("logKol", "Коля","100");
	User* ptrUserTo = new User("logSas", "Саша", "101");

	
	PrivateMessage* ptrMes = new PrivateMessage;
	
	ptrMes->readMessage(ptrUserFrom, ptrUserTo);
	//заносим номер сообщения в Сообщение
	int lstCount = messagePool.getCount();
	ptrMes->setNumMessage(lstCount);
	//Заносим в массив сообщение
	messagePool.add(move( *ptrMes));
	delete ptrMes;

	// выводим сообщение из массива и выводим на консоль
	PrivateMessage mes = messagePool[0];
	mes.printMessage();

	cout << "Привет Мир!" << endl;
	
	delete ptrUserFrom;
	delete ptrUserTo;
	*/
	return 0;
}