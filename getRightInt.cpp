#pragma once
#include <iostream>
//#include <Windows.h>  //������ ����� ������

static int getIntValue()
{
    //SetConsoleCP(1251);       //������ ����� ������
    //SetConsoleOutputCP(1251); //������ ����� ������
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        std::cout << "\n������� �����: ";
        int a;
        std::cin >> a;

        // �������� �� ���������� ����������
        if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
            std::cin.clear(); // �� ���������� cin � '�������' ����� ������
            std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
            std::cout << "\n��� �� �� ������� ��������� �����. ���������� �����: ";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // ������� ������ ��������

            return a;
        }
    }
}