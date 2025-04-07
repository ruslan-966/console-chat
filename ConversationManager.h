#pragma once
#include <iostream>
#include <conio.h> // подключаем getch
#include <ios>		// for <streamsize>
#include <limits>	// for numeric_limits

#include "User.h"
#include "Array.h"
#include "PrivateMessage.h"
#include "CommonMessage.h"

class ConversationManager
{
public:
	void cleanConsole();
	void greeting();								//Ќачальное приветствие пользовател€
	char regOrComm();								//ћеню выбора регистрации нового участника или общени€
	bool userRegistration(Array<User>&);			//ƒиалог регистрации нового пользовател€
	int usersInput(Array<User>&);					//¬ход зарегистрированного пользовател€
	void userMessChoise(User&, Array<PrivateMessage>&, Array<CommonMessage>&);		//выбор между прочтением пришедших сообщений и набором новых сообщений
	
};

