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
    cout << "\n\t\t\t\t\t\t\t�������� �������� ���� ���� �11\t\t\t\t\t\t" << endl << endl;
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "\n\t\t\t\t\t\t\t\t 1. ��������" << endl;
    cout << "\t\t\t\t\t\t\t\t 2. ���" << endl;
    cout << "\t\t\t\t\t\t\t\t 3. �����������" << endl;
    cout << "\t\t\t\t\t\t\t\t 4. �����" << endl;
    cout << "\t\t\t\t\t\t\t\t 5. ����������" << endl;
    cout << "\t\t\t\t\t\t\t\t 6. ���������" << endl;
    cout << "\t\t\t\t\t\t\t\t 7. �����" << endl;

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
        cout << "�������, �������� ���!";
    }
}
void Base::next() // ����� � ������� ����
{
    cout << "��� ������ � ������� ���� �������� (1)" << endl;
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

void Base::que() // ����� ��� ���������
{
    cout << "��� ������ � ������� ���� �������� (1), � �������� (2)" << endl;
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

void Base::view() // �������� ����� �������� ����
{
    system("cls");
    cout << "��������:\n1 - 1-4 �����\n2 - 5-11 �����\n� - ���" << endl;
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

void Base::provirka() // ������� ��� �����
{
    fstream fil;
    fil.open(file, ios::out | ios::in | ios::binary);
    if (!file)
    {
        cout << " ���� �� ��������� !!!" << endl;
        system("pause");
    }
    fil.close();
}

void Base::look() // �������� ��� ����
{
    system("cls");
    Stud ob;
    ifstream in;
    in.open(file, ios::in | ios::binary);
    if (!in)
    {
        cout << "�������" << endl;
    }
    cout << "**********************************************************************************************************************************************";
    cout << "\n\t\t\t\t\t\t\t\t�� ��� �����" << endl;
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "|�����|����| ������� |  ��'�  | �� ������� |���.����|�����.|��.����|Գ�-��|���.��|���.������|���������|Գ����|�������|������.|������.���|" << endl;
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
void Base::enter() // ��� ����� ��� ����
{
    Stud ob;
    ofstream out;
    out.open(file, ios::out | ios::app | ios::binary);
    if (!out)
    {
        cout << "�������";
    }
    system("cls");
    detail();
    cout << "����: ";
    cin >> ob.clas;
    cout << "��������� �����: ";
    cin >> ob.number;
    eatline();
    cout << "�������: ";
    cin.getline(ob.prizv, 15);
    cout << "��'�: ";
    cin.getline(ob.name, 15);
    cout << "�� �������: ";
    cin.getline(ob.batk, 15);
    if (ob.number < 499)
    {
        cout << "��������� ����: ";
        cin >> ob.ukr_mov;
        cout << "����������: ";
        cin >> ob.matem;
        cout << "�������� ����: ";
        cin >> ob.in_mov;
        cout << "Գ�-��: ";
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
        cout << "��������� ����: ";
        cin >> ob.ukr_mov;
        cout << "����������: ";
        cin >> ob.matem;
        cout << "��������� ���������: ";
        cin >> ob.ukr_lit;
        cout << "�������� ����: ";
        cin >> ob.in_mov;
        cout << "�����������: ";
        cin >> ob.informatic;
        cout << "Գ����: ";
        cin >> ob.fizika;
        cout << "������ ������: ";
        cin >> ob.istor_ukr;
        cout << "���������: ";
        cin >> ob.geografiy;
        cout << "�������: ";
        cin >> ob.biologia;
        cout << "Գ�-��: ";
        cin >> ob.fizra;

        ob.seredniy_bal = (ob.matem + ob.ukr_mov + ob.informatic + ob.ukr_lit + ob.in_mov + ob.biologia + ob.istor_ukr + ob.fizika + ob.fizra + ob.geografiy) / 10;
    }
    eatline();
    out.write((char*)&ob, sizeof ob);
    out.close();
    system("pause");
}
void Base::poshyk() // ����� � �������
{
    system("cls");
    int temp;
    Stud ob;
    fstream poshyk(file, ios::in | ios::binary);
    look();
    detail();
    cout << "����� �� ���������� �������:" << endl;
    cin >> temp;
    eatline();
    while (true)
    {
        poshyk.read((char*)&ob, sizeof(Stud));
        if (poshyk.eof())
        {
            cout << "���� " << temp << endl;
            return;
        }
        if (temp == ob.number)
        {
            if (ob.number < 499)
            {
                cout << "**************************************************************************************" << endl;
                cout << "| � |����| ������� |  ��'�  | �� ������� |���.����|�����.|��.����|Գ�-��|������.���|" << endl;
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
                cout << "|�����|����| ������� |  ��'�  | �� ������� |���.����|�����.|��.����|Գ�-��|���.��|���.������|���������|Գ����|�������|������.|������.���|" << endl;
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
void Base::sort() // ����������
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
    cout << "���������� ��:\n1 - ���������� ������\n2 - �� �������\n� - ���������� ����\n4 - �����" << endl;
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
    cout << "������!" << endl;
    sort.close();

}
//////////////////////////////////////////////////
void Base::redac() // �����������

{
    system("cls");
    Stud ob[1000];
    fstream del;
    del.open(file, ios::in | ios::out | ios::binary);
    if (!del.is_open())
    {
        cout << "�������!" << endl;
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
    cout << "������ ��������� ����� ���� ��� �����������: ";
    double number;
    cin >> number;
    del.close();
    del.clear();
    del.open(file, ios::out | ios::binary);
    for (int x = 0; x < count; x++)
        if (ob[x].number != number)
            del.write((char*)&ob[x], sizeof(Stud));
    entertoo();
    cout << "������!" << endl;
    del.close();
}

void Base::delet() // ���������
{
    system("cls");
    Stud ob[1000];
    fstream del;
    del.open(file, ios::in | ios::out | ios::binary);
    if (!del.is_open())
    {
        cout << "�������!" << endl;
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
    cout << "������ ��������� ����� ���� ����� ����� ��������: ";
    double number;
    cin >> number;
    del.close();
    del.clear();
    del.open(file, ios::out | ios::binary);
    for (int x = 0; x < count; x++)
        if (ob[x].number != number)
            del.write((char*)&ob[x], sizeof(Stud));
    cout << "������!" << endl;
    del.close();
}
void Base::detail() // ������� ��� ����� ���������� ������
{
    cout << "**************************************" << endl;
    cout << "|        ��� ���������� ������       |"<< endl;
    cout << "|____________________________________|"<< endl;
    cout << "| ���� |    �    |    �    |    �    |" << endl;
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

void Base::look_l() // �������� ���� 1-4 �����
{
    system("cls");
    Stud ob;
    ifstream in;
    in.open(file, ios::in | ios::binary);
    if (!in)
    {
        cout << "�������" << endl;
    }

    cout << "**************************************************************************************";
    cout << "\n\t\t\t\t�������� ����� (1-4 �����)" << endl;
    cout << "**************************************************************************************" << endl;
    cout << "| � |����| ������� |  ��'�  | �� ������� |���.����|�����.|��.����|Գ�-��|������.���|" << endl;
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

void Base::look_b() // �������� ���� 5-11 �����
{
    system("cls");
    Stud ob;
    ifstream in;
    in.open(file, ios::in | ios::binary);
    if (!in)
    {
        cout << "�������" << endl;
    }

    cout << "**********************************************************************************************************************************************";
    cout << "\n\t\t\t\t\t\t\t������ �� ������ ����� (5-11 �����)" << endl;
    cout << "**********************************************************************************************************************************************" << endl;
    cout << "|�����|����| ������� |  ��'�  | �� ������� |���.����|�����.|��.����|Գ�-��|���.��|���.������|���������|Գ����|�������|������.|������.���|" << endl;
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

void Base::entertoo() // ��� ����� ��� ���� ��� ������� ������� (��� �����������)
{
    Stud ob;
    ofstream out;
    out.open(file, ios::out | ios::app | ios::binary);
    if (!out)
    {
        cout << "�������";
    }
    detail();
    cout << "����: ";
    cin >> ob.clas;
    cout << "��������� �����: ";
    cin >> ob.number;
    eatline();
    cout << "�������: ";
    cin.getline(ob.prizv, 15);
    cout << "��'�: ";
    cin.getline(ob.name, 15);
    cout << "�� �������: ";
    cin.getline(ob.batk, 15);
    if (ob.number < 499)
    {
        cout << "��������� ����: ";
        cin >> ob.ukr_mov;
        cout << "����������: ";
        cin >> ob.matem;
        cout << "�������� ����: ";
        cin >> ob.in_mov;
        cout << "Գ�-��: ";
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
        cout << "��������� ����: ";
        cin >> ob.ukr_mov;
        cout << "����������: ";
        cin >> ob.matem;
        cout << "��������� ���������: ";
        cin >> ob.ukr_lit;
        cout << "�������� ����: ";
        cin >> ob.in_mov;
        cout << "�����������: ";
        cin >> ob.informatic;
        cout << "Գ����: ";
        cin >> ob.fizika;
        cout << "������ ������: ";
        cin >> ob.istor_ukr;
        cout << "���������: ";
        cin >> ob.geografiy;
        cout << "�������: ";
        cin >> ob.biologia;
        cout << "Գ�-��: ";
        cin >> ob.fizra;

        ob.seredniy_bal = (ob.matem + ob.ukr_mov + ob.informatic + ob.ukr_lit + ob.in_mov + ob.biologia + ob.istor_ukr + ob.fizika + ob.fizra + ob.geografiy) / 10;
    }
    eatline();
    out.write((char*)&ob, sizeof ob);
    out.close();
    system("pause");
}
