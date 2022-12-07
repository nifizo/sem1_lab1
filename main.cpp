#include "Dot.h"
#include "Figure.h"
#include <Windows.h>
#include <iostream>
#include "Matrix.h"
#include "SkipList.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    Figure f;
    f.appendDots();
    cout << f.countP() << endl;
    cout << f.countArea() << endl;
    if (f.checkOPYK() == true)
        cout << "OPYK" << endl;
    else
        cout << "NOT OPYK" << endl;
    cout << f.checkType() << endl;
    cout << "\n\n----------------------------------------------" << endl;
    srand((unsigned)time(0));
    SkipList lst(3, 0.5);
    lst.insertElement(3);
    lst.insertElement(6);
    lst.insertElement(7);
    lst.insertElement(9);
    lst.insertElement(12);
    lst.insertElement(19);
    lst.insertElement(17);
    lst.insertElement(26);
    lst.insertElement(21);
    lst.insertElement(25);
    lst.displayList();
    cout << lst.searchKey(0);
}