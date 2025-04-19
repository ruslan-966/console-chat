#pragma once
#include <iostream>
#include <conio.h> // ���������� getch
#include <ios>		// for <streamsize>
#include <limits>	// for numeric_limits
#include <memory>	// ��� ����� ����������

#include "User.h"
#include "Array.h"
#include "Message.h"
#include "getRightInt.cpp"
#include "UserManager.h"
#include "PrivateChat.h"

class ConversationManager
{
public:
	//������������
	ConversationManager();
	ConversationManager(Array <Message>&, Array <Message>&);
	
	void cleanConsole();
	void start();
	void greeting();																//��������� ����������� ������������
	char regOrComm();																//���� ������ ����������� ������ ��������� ��� �������
	bool userRegistration();											//������ ����������� ������ ������������
	int usersInput();													//���� ������������������� ������������
	void userMessChoise(User&);											//���� ������ � ������� �����
	
	void outputPrivateMesage(User&);								//����� �� ������� ��������� �� ������� ����
	void outputCommonMessage();										//����� �� ������� ��������� �� ������ ����
	void inputPrivateMessage(User&);				//������ ��������� � ������� ���
	void inputCommonMessage(std::string& );						//������ ��������� � ����� ���
	int amountPrivateMessage(std::string& );						//���������� ������ ��������� ��� ������ ������������
	void privateMesMenu(std::string&);								//���� ������ � ������� �����������
	void readWritePrivateChat(int, int);									//������ � ���������� �����
	void createNewChart(int, Array<int>&);										//�������� ������ ����
	void writeNewChart(int, int);									//������ ������ ������ ����
	void printPrivateMessagePool();									//������� �� ������� ���������� �������

	Array <Message> privateMessagePool;
	Array <Message> commonMessagePool;
	UserManager allUsers;
	Array <PrivateChat*> ptrPrivCharts;
};

