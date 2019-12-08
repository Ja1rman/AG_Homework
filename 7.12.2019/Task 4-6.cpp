/*
Реализуйте структуру LongInt, позволяющую использовать длинные натуральные числа, 
а также пример использования. 
Реализовать:
конструкторы
конструктор копий
деструктор
операторы >>,<< - ввод/вывод
сложение, вычитание
умножение (Карацуба)
деление, взятие остатка (например, бисекцией)
возведение в степень
…
Profit
*/

#include <iostream>
#include <iterator>

using namespace std;

struct LongInt
{
    int n;
    char* arr;
    
    LongInt(char* a, int b)
    {
        n = b;
        char* arr = new char[n];
        for (int i; i < n; i++)
            arr[i] = a[i];
    }
    
    LongInt(LongInt &X)
    {
        n = X.n;
        char* arr = new char[n];
        for (int i; i < n; i++)
            arr[i] = X.arr[i];
    }
    
    ~LongInt()
    {
        delete [] arr;
    }

};

LongInt operator+ (LongInt a, LongInt b)
{
    
    if (a.n > b.n)
    {
        char* temp = new char[a.n + 1];
        for (int i = 0; i <= a.n; i++)
            temp[i] = 0;
            
        for (int i = a.n; i > 0; i--)
        {
            for (int j = b.n; j > 0; j--)
            {
                int p = (int)a.arr[i] + (int)b.arr[i];
                if (p > 10)
                {
                    if (i != a.n)
                        temp[i] = p % 10;
                    else
                        temp[i] = p % 10 + temp[i];
                    temp[i + 1] = p / 10;
                }
            }
        }
    }
    else
    {
        char* temp = new char[b.n + 1];
        for (int i = 0; i <= b.n; i++)
            temp[i] = 0;
            
        for (int i = b.n; i > 0; i--)
        {
            for (int j = a.n; j > 0; j--)
            {
                int p = (int)a.arr[i] + (int)b.arr[i];
                if (p > 10)
                {
                    if (i != b.n)
                        temp[i] = p % 10;
                    else
                        temp[i] = p % 10 + temp[i];
                    temp[i + 1] = p / 10;
                }
            }
        }
    }
    
    
    
};

LongInt operator- (LongInt a, LongInt b)
{
    
};

LongInt operator* (LongInt a, LongInt b)
{
    
};

LongInt operator/ (LongInt a, LongInt b)
{
    
};

LongInt operator% (LongInt a, LongInt b)
{
    
};

LongInt operator^ (LongInt a, LongInt b)
{
    
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
    
    cout << "Enter exponent" << endl;
    int k;
    cin >> k;
    
    cout << "+   " << LongInt(&arr, &n) + LongInt(&arr2, &n2) << endl;
    /*cout << "-   " << LongInt(arr, n) - LongInt(arr2, n2) << endl;
    cout << "*   " << LongInt(arr, n) * LongInt(arr2, n2) << endl;
    cout << "/   " << LongInt(arr, n) / LongInt(arr2, n2) << endl;
    cout << "%   " << LongInt(arr, n) % LongInt(arr2, n2) << endl;
    cout << "pow   " << LongInt(arr) ^ k << endl;*/
    
    delete [] arr;
    delete [] arr2;
    
    return 0;
}
