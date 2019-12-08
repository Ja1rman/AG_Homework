/*
–еализуйте структуру LongInt, позвол€ющую использовать длинные натуральные числа,
а также пример использовани€.
–еализовать:
конструкторы
конструктор копий
деструктор
операторы >>,<< - ввод/вывод
сложение, вычитание
умножение ( арацуба)
деление, вз€тие остатка (например, бисекцией)
возведение в степень
Е
Profit
*/

#include <iostream>
#include <iterator>

using namespace std;

struct LongInt
{

    LongInt()
    {

    }

    ~LongInt()
    {

    }



};

int main()
{
    cout << "Enter first number" << endl;
    char* arr = new char;
    cin.getline(arr, size_t(arr));
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter second number" << endl;
    char* arr2 = new char;
    cin.getline(arr2, size_t(arr2));
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "+   " << LongInt(arr) + LongInt(arr) << endl;
    cout << "-   " << LongInt(arr) - LongInt(arr) << endl;
    cout << "*   " << LongInt(arr) * LongInt(arr) << endl;
    cout << "/   " << LongInt(arr) / LongInt(arr) << endl;
    cout << "%   " << LongInt(arr) % LongInt(arr) << endl;
    cout << "pow   " << LongInt(arr) << endl;

    delete [] arr;
    delete [] arr2;

    return 0;
}
