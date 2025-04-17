#pragma once
#include "Array.h"

class PrivateChat
{
private:
	int _firstPartNumber{0};			//�����  ������� ��������� � DataManager
	int _secondPartNumber{0};			//����� ������� ��������� � DataManager
	int _lstMesOneNum{ 0 };				//����� ���������� ����������� ��������� � ���� ��� ������� ������������
	int _lstMesSecondNum{0};			//����� ���������� ����������� ��������� � ���� ��� ������� ������������
	Array<int> _massive;
	//int _massive[100]{};					//������ ������� ��������� �� ������� ������ ���������
	//int _count{0};						//���������� ���������
public:
	PrivateChat() = default;
	PrivateChat(int, int);
	void setMesNumber(int);
	bool isItRightChat(int);			//���������� ����������, ���� �� ������������ � ���� ����
	int getAnotherUser(int);			//���������� ����� ������� ������������
};
