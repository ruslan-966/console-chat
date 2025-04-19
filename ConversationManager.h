#pragma once
#include <iostream>
#include <conio.h> // ���������� getch
#include <ios>		// for <streamsize>
#include <limits>	// for numeric_limits

#include "User.h"
#include "Array.h"
#include "Message.h"
#include "getRightInt.cpp"

class ConversationManager
{
public:
	//������������
	ConversationManager();
	ConversationManager(Array <User>&, Array <Message>&, Array <Message>&);
	
	void cleanConsole();
	void start();
	void greeting();																//��������� ����������� ������������
	char regOrComm();																//���� ������ ����������� ������ ��������� ��� �������
	bool userRegistration(Array<User>&);											//������ ����������� ������ ������������
	int usersInput(Array<User>&);													//���� ������������������� ������������
	void userMessChoise(User&, Array<User>&, Array<Message>&, Array<Message>&);		//����� ����� ���������� ��������� ��������� � ������� ����� ���������
	
	void outputPrivateMesage(Array<Message>&, User&);								//����� �� ������� ��������� �� ������� ����
	void outputCommonMessage(Array<Message>&);										//����� �� ������� ��������� �� ������ ����
	void inputPrivateMessage(Array<User>& , User& , Array<Message>& );				//������ ��������� � ������� ���
	void inputCommonMessage(Array<Message>& , std::string& );						//������ ��������� � ����� ���
	int amountPrivateMessage(Array<Message>& , std::string& );						//���������� ������ ��������� ��� ������ ������������
	
//private:
	Array <Message> privateMessagePool;
	Array <Message> commonMessagePool;
	Array <User> allUsers;
	
};

