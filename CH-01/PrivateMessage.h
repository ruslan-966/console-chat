#pragma once
#include <string>
#include <iostream>
#include "User.h"

using namespace std;

class PrivateMessage
{
private:
	int _numMessage;
	string _message;
	string _sendFrom;
	string _sendTo;
	bool _isItPrinted{false};
public:
	// ������������:
	PrivateMessage();
	PrivateMessage(int, string&&, string&&, string&&);

	// ����������
	~PrivateMessage()=default;

	// �������:
	void setNumMessage(int);
	void setMessage(string&&);
	void setSendFrom(string&&);
	void setSendTo(string&&);

	//�������:
	int getNumMessage() const;
	string* getMessage();
	string* getSendFrom();
	string* getSendTo();
	bool isItPrinted() const;
	 // ����� ���������
	void printMessage();
	// ������ ��������� � �������
	void readMessage(User* , User* );
};

