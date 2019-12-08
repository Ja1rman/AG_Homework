/*
Докажите эти тождества и напишите программу для вычисления ЧФ с помощью разделяй и властвуй.
*/

#include <iostream>
#include <cmath>

using namespace std;

int fib(int f)
{
    if (f < 2)
        return f;
    else if (f == 2)
        return 1;
    else if (f % 2 == 1)
        return pow(fib((f - 1) / 2), 2) + pow(fib((f - 1) / 2 + 1), 2);
    else
        return pow(fib(f / 2 + 1), 2) - pow(fib(f / 2 - 1), 2);
}

int main()
{
    int f;
    cin >> f;

    if (f < 0)
        cout << "/GG";
    else
        cout << fib(f);

    return 0;
}
