#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
using namespace std;

class Base
{
    int a, num, j, b, g, c, d;

public:
    //Stud ob;
    void menu();
    void next();// ����� � ������� ����
    void que(); // ����� ��� ���������
    void view(); // �������� ����� �������� ����
    void provirka(); // ������� ��� �����
    void look(); // �������� ��� ����
    void enter(); // ��� ����� ��� ����
    void poshyk(); // ����� � �������
    void sort(); // ����������
    void redac(); // �����������
    void delet(); // ���������
    void detail(); // ������� ��� ����� ���������� ������
    void look_l(); // �������� ���� 1-4 �����
    void look_b(); // �������� ���� 5-11 �����
    void entertoo(); // ��� ����� ��� ���� ��� ������� ������� (��� �����������)
};

#endif // BASE_H_INCLUDED
