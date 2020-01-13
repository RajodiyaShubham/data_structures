#include <iostream>
#include "LinkedList.h"
using namespace std;

enum ListOperation
{
    INSERT = 1,
    INSERT_AT,
    REMOVE,
    REMOVE_AT,
    COUNT,
    IS_EMPTY,
    TRAVERSE,
    CLEAR,
    EXIT = 0
};

ListOperation showMenu()
{
    int choice;
    cout << "***** List Operations *****" << endl;
    cout << "1:"
         << " Insert" << endl;
    cout << "2:"
         << " InsertAt" << endl;
    cout << "3:"
         << " Remove" << endl;
    cout << "4:"
         << " RemoveAt" << endl;
    cout << "5:"
         << " Count" << endl;
    cout << "6:"
         << " IsEmpty" << endl;
    cout << "7:"
         << " Traverse" << endl;
    cout << "8:"
         << " Clear" << endl;
    cout << "0:"
         << " Exit" << endl;
    cin >> choice;
    return (ListOperation)choice;
}

int main()
{
    LinkedList list;
    int data, pos;
    ListOperation operation = showMenu();
    while (operation != EXIT)
    {
        switch (operation)
        {
        case INSERT:
            cout << "Data : ";
            cin >> data;
            list.insert(data);
            break;
        case INSERT_AT:
            cout << "Position : ";
            cin >> pos;
            cout << "Data : ";
            cin >> data;
            list.insertAt(pos, data);
            break;
        case REMOVE:
            cout << "Data : ";
            cin >> data;
            list.remove(data);
            break;
        case REMOVE_AT:
            cout << "Position : ";
            cin >> pos;
            list.removeAt(pos);
            break;
        case COUNT:
            cout << "count = " << list.count() << endl;
            break;
        case IS_EMPTY:
            cout << "Is list empty ? " << (list.isEmpty() ? "true" : "false") << endl;
            break;
        case TRAVERSE:
            list.traverse();
            break;
        case CLEAR:
            list.clear();
            break;
        default:
            break;
        }
        operation = showMenu();
    }
    list.clear();
}