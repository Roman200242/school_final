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
    void next();// вихід в головне меню
    void que(); // вихід для перегляду
    void view(); // перегляд різних категорій учнів
    void provirka(); // провірка для файлу
    void look(); // перегляд всіх учнів
    void enter(); // ввід даних про учнів
    void poshyk(); // пошук з умовами
    void sort(); // сортування
    void redac(); // редагування
    void delet(); // видалення
    void detail(); // додаток для вводу особистого номеру
    void look_l(); // перегляд учнів 1-4 кдасів
    void look_b(); // перегляд учнів 5-11 кдасів
    void entertoo(); // ввід даних про учнів без очистки стоірнки (для редагування)
};

#endif // BASE_H_INCLUDED
