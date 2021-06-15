#include "base.h"
const char* file = "jurnal";
char* r(char* buf);
char a[256];
inline void eatline()
{
    while (cin.get() != '\n')
        continue;
}
struct Stud
{
    int number;
    char prizv[15];
    char name[15];
    char batk[15];
    double istor_ukr;
    double informatic;
    double fizika;
    double matem;
    double ukr_mov;
    double ukr_lit;
    double in_mov;
    double fizra;
    double biologia;
    double geografiy;
    double seredniy_bal;
    char clas[15];
};
void Base::menu()
{
    system("cls");
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "\n\t\t\t\t\t\t\tКонтроль успішності учнів ліцею №11\t\t\t\t\t\t" << endl << endl;
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "\n\t\t\t\t\t\t\t\t 1. Перегляд" << endl;
    cout << "\t\t\t\t\t\t\t\t 2. Ввід" << endl;
    cout << "\t\t\t\t\t\t\t\t 3. Редагування" << endl;
    cout << "\t\t\t\t\t\t\t\t 4. Пошук" << endl;
    cout << "\t\t\t\t\t\t\t\t 5. Сортування" << endl;
    cout << "\t\t\t\t\t\t\t\t 6. Видалення" << endl;
    cout << "\t\t\t\t\t\t\t\t 7. Вихід" << endl;

    a = _getch();
    switch (a)
    {
    case '1':
        view();
        //look();
        next();
        break;
    case '2':
        enter();
        next();
        break;
    case '3':
        redac();
        next();
        break;
    case '4':
        poshyk();
        next();
        break;
    case '5':
        sort();
        next();
        break;
    case '6':
        delet();
        next();
        break;
    case '7':
        exit(1);
        break;
    default:
        cout << "Помилка, повторіть ввід!";
    }
}
void Base::next() // вихід в головне меню
{
    cout << "Для виходу в головне меню натисніть (1)" << endl;
    a = _getch();
    switch (b)
    {
    case '1':
        menu();
        break;
    case '2':
        exit(1);
    }
}

void Base::que() // вихід для перегляду
{
    cout << "Для виходу в головне меню натисніть (1), в перегляд (2)" << endl;
    d = _getch();
    switch (d)
    {
    case '1':
        menu();
        break;
    case '2':
        view();
        break;
    }
}

void Base::view() // перегляд різних категорій учнів
{
    system("cls");
    cout << "Перегляд:\n1 - 1-4 класи\n2 - 5-11 класи\nЗ - Всіх" << endl;
    c = _getch();
    switch (c)
    {
    case '1':
        look_l();
        que();
        break;
    case '2':
        look_b();
        que();
        break;
    case '3':
        look();
        que();
        break;

    }
}

void Base::provirka() // провірка для файлу
{
    fstream fil;
    fil.open(file, ios::out | ios::in | ios::binary);
    if (!file)
    {
        cout << " Файл не знайдений !!!" << endl;
        system("pause");
    }
    fil.close();
}

void Base::look() // перегляд всіх учнів
{
    system("cls");
    Stud ob;
    ifstream in;
    in.open(file, ios::in | ios::binary);
    if (!in)
    {
        cout << "Помилка" << endl;
    }
    cout << "**********************************************************************************************************************************************";
    cout << "\n\t\t\t\t\t\t\t\tВсі учні школи" << endl;
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "|Номер|Клас| Прізвище |  Ім'я  | По батькові |Укр.мова|Матем.|Ін.мова|Фіз-ра|Укр.літ|Укр.історія|Географія|Фізика|Біологія|Інформ.|Середн.бал|" << endl;
    while (in.read((char*)&ob, sizeof ob))
        cout << "|" << setw(4) <<  ob.number << " |" << setw(4) << ob.clas << "|" << setw(10) << ob.prizv << "|" << setw(8) << ob.name << "|"
             << setw(13) << ob.batk << "|   " << setw(2) << ob.ukr_mov << "   |  " << setw(2) << ob.matem << "  |  "
             << setw(2) << ob.in_mov << "   |  " << setw(2) << ob.fizra << "  |  " << setw(2) << ob.ukr_lit << "   |     "
             << setw(2) << ob.istor_ukr << "    |    " << setw(2) << ob.geografiy << "   |  " << setw(2) << ob.fizika << "  |   "
             << setw(2) << ob.biologia << "   |  " << setw(2) << ob.informatic << "   |  " << setw(4)
             << setprecision(2) << ob.seredniy_bal << "    |" << endl;
    cout << "**********************************************************************************************************************************************"  << endl;
    in.close();
}
void Base::enter() // ввід даних про учнів
{
    Stud ob;
    ofstream out;
    out.open(file, ios::out | ios::app | ios::binary);
    if (!out)
    {
        cout << "Помилка";
    }
    system("cls");
    detail();
    cout << "Клас: ";
    cin >> ob.clas;
    cout << "Особистий номер: ";
    cin >> ob.number;
    eatline();
    cout << "Прізвище: ";
    cin.getline(ob.prizv, 15);
    cout << "Ім'я: ";
    cin.getline(ob.name, 15);
    cout << "По батькові: ";
    cin.getline(ob.batk, 15);
    if (ob.number < 499)
    {
        cout << "Українська мова: ";
        cin >> ob.ukr_mov;
        cout << "Математика: ";
        cin >> ob.matem;
        cout << "Іноземна мова: ";
        cin >> ob.in_mov;
        cout << "Фіз-ра: ";
        cin >> ob.fizra;
        ob.ukr_lit = '\0';
        ob.informatic = '\0';
        ob.fizika = '\0';
        ob.istor_ukr = '\0';
        ob.geografiy = '\0';
        ob.biologia = '\0';
        ob.seredniy_bal = (ob.matem + ob.ukr_mov + ob.in_mov + ob.fizra) / 4;
    }
    else
    {
        cout << "Українська мова: ";
        cin >> ob.ukr_mov;
        cout << "Математика: ";
        cin >> ob.matem;
        cout << "Українська література: ";
        cin >> ob.ukr_lit;
        cout << "Іноземна мова: ";
        cin >> ob.in_mov;
        cout << "Інформатика: ";
        cin >> ob.informatic;
        cout << "Фізика: ";
        cin >> ob.fizika;
        cout << "Історія України: ";
        cin >> ob.istor_ukr;
        cout << "Географія: ";
        cin >> ob.geografiy;
        cout << "Біологія: ";
        cin >> ob.biologia;
        cout << "Фіз-ра: ";
        cin >> ob.fizra;

        ob.seredniy_bal = (ob.matem + ob.ukr_mov + ob.informatic + ob.ukr_lit + ob.in_mov + ob.biologia + ob.istor_ukr + ob.fizika + ob.fizra + ob.geografiy) / 10;
    }
    eatline();
    out.write((char*)&ob, sizeof ob);
    out.close();
    system("pause");
}
void Base::poshyk() // пошук з умовами
{
    system("cls");
    int temp;
    Stud ob;
    fstream poshyk(file, ios::in | ios::binary);
    look();
    detail();
    cout << "Пошук по особистому номером:" << endl;
    cin >> temp;
    eatline();
    while (true)
    {
        poshyk.read((char*)&ob, sizeof(Stud));
        if (poshyk.eof())
        {
            cout << "Немає " << temp << endl;
            return;
        }
        if (temp == ob.number)
        {
            if (ob.number < 499)
            {
                cout << "**************************************************************************************" << endl;
                cout << "| № |Клас| Прізвище |  Ім'я  | По батькові |Укр.мова|Матем.|Ін.мова|Фіз-ра|Середн.бал|" << endl;
                cout << "|" << setw(3) <<  ob.number << "|" << setw(4) << ob.clas << "|" << setw(10) << ob.prizv << "|" << setw(8) << ob.name << "|"
                     << setw(13) << ob.batk << "|   " << setw(2) << ob.ukr_mov << "   |  " << setw(2) << ob.matem << "  | "
                     << setw(2) <<  ob.in_mov << "   |  " << setw(2) << ob.fizra << "  |   " << setw(4)
                     << setprecision(2) << ob.seredniy_bal << "    |" << endl;
                cout << "**************************************************************************************" << endl;
                return;
            }
            else
            {
                cout << "**********************************************************************************************************************************************" << endl;
                cout << "|Номер|Клас| Прізвище |  Ім'я  | По батькові |Укр.мова|Матем.|Ін.мова|Фіз-ра|Укр.літ|Укр.історія|Географія|Фізика|Біологія|Інформ.|Середн.бал|" << endl;
                cout << "|" << setw(4) <<  ob.number << " |" << setw(4) << ob.clas << "|" << setw(10) << ob.prizv << "|" << setw(8) << ob.name << "|"
                     << setw(13) << ob.batk << "|   " << setw(2) << ob.ukr_mov << "   |  " << setw(2) << ob.matem << "  |  "
                     << setw(2) << ob.in_mov << "   |  " << setw(2) << ob.fizra << "  |  " << setw(2) << ob.ukr_lit << "   |     "
                     << setw(2) << ob.istor_ukr << "    |    " << setw(2) << ob.geografiy << "   |  " << setw(2) << ob.fizika << "  |   "
                     << setw(2) << ob.biologia << "   |  " << setw(2) << ob.informatic << "   |  " << setw(4)
                     << setprecision(2) << ob.seredniy_bal << "    |" << endl;
                cout << "**********************************************************************************************************************************************" << endl;
                return;
            }
        }
    }
}
void Base::sort() // сортування
{
    system("cls");
    fstream sort;
    sort.open(file, ios::in | ios::binary);
    Stud ob[1000];
    Stud tem;
    int count = 0;

    while (!sort.eof())
    {
        sort.read((char*)&ob[count], sizeof(Stud));
        count++;
    }
    count--;
    cout << "Сортування по:\n1 - Особистому номеру\n2 - По прізвищу\nЗ - Середньому балу\n4 - Класу" << endl;
    int a;
    cin >> a;
    eatline();
    if (a == 1)
    {
        for (int i = 0; i < count; i++)
            for (int j = 0; j < count; j++)
            {
                if (ob[i].number < ob[j].number)
                {
                    tem = ob[i];
                    ob[i] = ob[j];
                    ob[j] = tem;
                }
            }

    }

    if (a == 2)
    {
        for (int i = 0; i < count; i++)
            for (int j = 0; j < count; j++)
            {
                if (ob[i].prizv[0] < ob[j].prizv[0]
                        || ob[i].prizv[0] == ob[j].prizv[0] && ob[i].prizv[1] < ob[j].prizv[1])
                {
                    tem = ob[i];
                    ob[i] = ob[j];
                    ob[j] = tem;
                }

            }
    }
    if (a == 3)
    {
        for (int i = 0; i < count; i++)
            for (int j = 0; j < count; j++)
            {
                if (ob[i].seredniy_bal < ob[j].seredniy_bal)
                {
                    tem = ob[i];
                    ob[i] = ob[j];
                    ob[j] = tem;
                }
            }

    }

    else if (a == 4)
    {
        for (int i = 0; i < count; i++)
            for (int j = 0; j < count; j++)
            {
                if (ob[i].number < ob[j].number)
                {
                    tem = ob[i];
                    ob[i] = ob[j];
                    ob[j] = tem;
                }
            }

    }


    sort.close();
    sort.clear();
    sort.open(file, ios::out | ios::binary);
    for (a = 0; a < count; a++)
    {
        sort.write((char*)&ob[a], sizeof(Stud));
    }
    cout << "Успішно!" << endl;
    sort.close();

}
//////////////////////////////////////////////////
void Base::redac() // редагування

{
    system("cls");
    Stud ob[1000];
    fstream del;
    del.open(file, ios::in | ios::out | ios::binary);
    if (!del.is_open())
    {
        cout << "Помилка!" << endl;
        exit(1);
    }
    int count = 0;
    while (!del.eof())
    {
        del.read((char*)&ob[count], sizeof(Stud));
        count++;
    }
    look();
    count--;
    cout << "Введіть особистий номер учня для редагування: ";
    double number;
    cin >> number;
    del.close();
    del.clear();
    del.open(file, ios::out | ios::binary);
    for (int x = 0; x < count; x++)
        if (ob[x].number != number)
            del.write((char*)&ob[x], sizeof(Stud));
    entertoo();
    cout << "Успішно!" << endl;
    del.close();
}

void Base::delet() // видалення
{
    system("cls");
    Stud ob[1000];
    fstream del;
    del.open(file, ios::in | ios::out | ios::binary);
    if (!del.is_open())
    {
        cout << "Помилка!" << endl;
        exit(1);
    }
    int count = 0;
    while (!del.eof())
    {
        del.read((char*)&ob[count], sizeof(Stud));
        count++;
    }
    look();
    count--;
    cout << "Введіть особистий номер учня якого треба видалити: ";
    double number;
    cin >> number;
    del.close();
    del.clear();
    del.open(file, ios::out | ios::binary);
    for (int x = 0; x < count; x++)
        if (ob[x].number != number)
            del.write((char*)&ob[x], sizeof(Stud));
    cout << "Успішно!" << endl;
    del.close();
}
void Base::detail() // додаток для вводу особистого номеру
{
    cout << "**************************************" << endl;
    cout << "|        Для особистого номеру       |"<< endl;
    cout << "|____________________________________|"<< endl;
    cout << "| Клас |    А    |    Б    |    В    |" << endl;
    cout << "|   1  | 101-130 | 131-160 | 161-190 |" << endl;
    cout << "|   2  | 201-230 | 231-260 | 261-290 |" << endl;
    cout << "|   3  | 301-330 | 331-360 | 361-390 |" << endl;
    cout << "|   4  | 401-430 | 431-460 | 461-490 |" << endl;
    cout << "|   5  | 501-530 | 531-560 | 561-590 |" << endl;
    cout << "|   6  | 601-630 | 631-660 | 661-690 |" << endl;
    cout << "|   7  | 701-730 | 731-760 | 761-790 |" << endl;
    cout << "|   8  | 801-830 | 831-860 | 861-890 |" << endl;
    cout << "|   9  | 901-830 | 931-960 | 961-990 |" << endl;
    cout << "|  10  |1001-1030|1031-1060|1061-1090|" << endl;
    cout << "|  11  |1101-1130|1131-1160|1161-1190|" << endl;
    cout << "**************************************" << endl;

}

void Base::look_l() // перегляд учнів 1-4 кдасів
{
    system("cls");
    Stud ob;
    ifstream in;
    in.open(file, ios::in | ios::binary);
    if (!in)
    {
        cout << "Помилка" << endl;
    }

    cout << "**************************************************************************************";
    cout << "\n\t\t\t\tПочаткові класи (1-4 класи)" << endl;
    cout << "**************************************************************************************" << endl;
    cout << "| № |Клас| Прізвище |  Ім'я  | По батькові |Укр.мова|Матем.|Ін.мова|Фіз-ра|Середн.бал|" << endl;
    while (in.read((char*)&ob, sizeof ob))
        if (ob.number < 499)
        {
            cout << "|" << setw(3) <<  ob.number << "|" << setw(4) << ob.clas << "|" << setw(10) << ob.prizv << "|" << setw(8) << ob.name << "|"
                 << setw(13) << ob.batk << "|   " << setw(2) << ob.ukr_mov << "   |  " << setw(2) << ob.matem << "  |   "
                 << setw(2) <<  ob.in_mov << "   |  " << setw(2) << ob.fizra << "  | " << setw(4)
                 << setprecision(2) << ob.seredniy_bal << "    |" << endl;

        }

    cout << "**************************************************************************************" << endl;

    in.close();
}

void Base::look_b() // перегляд учнів 5-11 кдасів
{
    system("cls");
    Stud ob;
    ifstream in;
    in.open(file, ios::in | ios::binary);
    if (!in)
    {
        cout << "Помилка" << endl;
    }

    cout << "**********************************************************************************************************************************************";
    cout << "\n\t\t\t\t\t\t\tСередні та старші класи (5-11 класи)" << endl;
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "|Номер|Клас| Прізвище |  Ім'я  | По батькові |Укр.мова|Матем.|Ін.мова|Фіз-ра|Укр.літ|Укр.історія|Географія|Фізика|Біологія|Інформ.|Середн.бал|" << endl;
    while (in.read((char*)&ob, sizeof ob))
        if (ob.number > 500)
        {
            cout << "|" << setw(4) <<  ob.number << " |" << setw(4) << ob.clas << "|" << setw(10) << ob.prizv << "|" << setw(8) << ob.name << "|"
                 << setw(13) << ob.batk << "|   " << setw(2) << ob.ukr_mov << "   |  " << setw(2) << ob.matem << "  |  "
                 << setw(2) << ob.in_mov << "   |  " << setw(2) << ob.fizra << "  |  " << setw(2) << ob.ukr_lit << "   |     "
                 << setw(2) << ob.istor_ukr << "    |    " << setw(2) << ob.geografiy << "   |  " << setw(2) << ob.fizika << "  |   "
                 << setw(2) << ob.biologia << "   |  " << setw(2) << ob.informatic << "   |  " << setw(4)
                 << setprecision(2) << ob.seredniy_bal << "    |" << endl;

        }
    cout << "**********************************************************************************************************************************************" << endl;
    in.close();
}

void Base::entertoo() // ввід даних про учнів без очистки стоірнки (для редагування)
{
    Stud ob;
    ofstream out;
    out.open(file, ios::out | ios::app | ios::binary);
    if (!out)
    {
        cout << "Помилка";
    }
    detail();
    cout << "Клас: ";
    cin >> ob.clas;
    cout << "Особистий номер: ";
    cin >> ob.number;
    eatline();
    cout << "Прізвище: ";
    cin.getline(ob.prizv, 15);
    cout << "Ім'я: ";
    cin.getline(ob.name, 15);
    cout << "По батькові: ";
    cin.getline(ob.batk, 15);
    if (ob.number < 499)
    {
        cout << "Українська мова: ";
        cin >> ob.ukr_mov;
        cout << "Математика: ";
        cin >> ob.matem;
        cout << "Іноземна мова: ";
        cin >> ob.in_mov;
        cout << "Фіз-ра: ";
        cin >> ob.fizra;
        ob.ukr_lit = '\0';
        ob.informatic = '\0';
        ob.fizika = '\0';
        ob.istor_ukr = '\0';
        ob.geografiy = '\0';
        ob.biologia = '\0';
        ob.seredniy_bal = (ob.matem + ob.ukr_mov + ob.in_mov + ob.fizra) / 4;
    }
    else
    {
        cout << "Українська мова: ";
        cin >> ob.ukr_mov;
        cout << "Математика: ";
        cin >> ob.matem;
        cout << "Українська література: ";
        cin >> ob.ukr_lit;
        cout << "Іноземна мова: ";
        cin >> ob.in_mov;
        cout << "Інформатика: ";
        cin >> ob.informatic;
        cout << "Фізика: ";
        cin >> ob.fizika;
        cout << "Історія України: ";
        cin >> ob.istor_ukr;
        cout << "Географія: ";
        cin >> ob.geografiy;
        cout << "Біологія: ";
        cin >> ob.biologia;
        cout << "Фіз-ра: ";
        cin >> ob.fizra;

        ob.seredniy_bal = (ob.matem + ob.ukr_mov + ob.informatic + ob.ukr_lit + ob.in_mov + ob.biologia + ob.istor_ukr + ob.fizika + ob.fizra + ob.geografiy) / 10;
    }
    eatline();
    out.write((char*)&ob, sizeof ob);
    out.close();
    system("pause");
}
