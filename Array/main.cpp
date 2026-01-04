#include <iostream>
#include "Array.h"
using namespace std;
int main()
{
    Array<int> a;
    cout << "IsEmpty: " << a.IsEmpty() << endl;

    a.Add(10);
    a.Add(20);
    a.Add(30);

    cout << "Size: " << a.GetSize() << endl;
    cout << "Elements: ";
    for (int i = 0; i < a.GetSize(); i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Upper bound: " << a.GetUpperBound() << endl ;

    a.SetAt(1, 99);
    cout << "Element at index 1: " << a.GetAt(1) << endl;

    a.InsertAt(1, 50);

    a.RemoveAt(2);

    cout << "After insert/remove: ";
    for (int i = 0; i < a.GetSize(); i++)
        cout << a[i] << " ";
    cout << endl;

    Array<int> b;
    b.Add(100);
    b.Add(200);

    a.Append(b);

    cout << "After append: ";
    for (int i = 0; i < a.GetSize(); i++)
        cout << a[i] << " ";
    cout << endl;

    a.FreeExtra();

    a.RemoveAll();
    cout << "After Removeall, IsEmpty: " << a.IsEmpty() << endl;

    return 0;
}