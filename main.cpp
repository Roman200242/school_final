#include "base.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Base ob;
    ob.provirka();
    while (1) {
        ob.menu();
    }
    return 0;
}
