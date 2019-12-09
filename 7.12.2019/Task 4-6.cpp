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
#include <string>

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
    
    if ((int)a.n > (int)b.n)
    {
        char* temp = new char[(int)a.n + 1];
        for (int i = 0; i <= (int)a.n; i++)
            temp[i] = 0;
            
        int j = (int)a.n - 1;
        int jj = (int)b.n - 1;
        while (j >= 0)
        {
            if (jj >= 0)
            {
                int p = (int)a.arr[j] + (int)b.arr[jj] + temp[j];
                if (p > 10)
                {
                    if (j != (int)a.n - 1)
                        temp[j + 1] = p % 10;
                    else
                        temp[j + 1] = p % 10 + temp[j];
                    temp[j] = p / 10;
                }
            }
            else
                temp[j + 1] = (int)a.n + temp[j];
            
            j--;
            jj--;
        }
    
        if (temp[0] != 0)
            return LongInt(temp, a.n + 1);
        else
        {
            char* temp2 = new char[a.n];
            for (int i = 0; i < a.n; i++)
                temp2[i] = temp[i + 1];
                
            return LongInt(temp2, a.n);
        }
    }
    else
    {
        char* temp = new char[b.n + 1];
        for (int i = 0; i <= b.n; i++)
            temp[i] = 0;
            
        int j = (int)b.n - 1;
        int jj = (int)a.n - 1;
        while (j >= 0)
        {
            if (jj >= 0)
            {
                int p = (int)b.arr[j] + (int)a.arr[jj] + temp[j];
                if (p > 10)
                {
                    if (j != (int)b.n - 1)
                        temp[j + 1] = p % 10;
                    else
                        temp[j + 1] = p % 10 + temp[j];
                    temp[j] = p / 10;
                }
            }
            else
                temp[j + 1] = (int)b.n + temp[j];
            
            j--;
            jj--;
        }
        
        if (temp[0] != 0)
            return LongInt(temp, b.n + 1);
        else
        {
            char* temp2 = new char[b.n];
            for (int i = 0; i < b.n; i++)
                temp2[i] = temp[i + 1];
                
            return LongInt(temp, b.n);
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
    string str;
    cin >> str;
    int n = str.size();
    char* arr = new char[n];
    for (int i = 0; i < n; i++)
        arr[i] = str[i];
    
    cout << "Enter second number" << endl;
    string str2;
    cin >> str2;
    int n2 = str2.size();
    char* arr2 = new char[n];
    for (int i = 0; i < n2; i++)
        arr2[i] = str2[i];
    
    cout << "Enter exponent" << endl;
    int k;
    cin >> k;
    
    cout << "+   " << LongInt(arr, n) + LongInt(arr2, n2) << endl;
    /*cout << "-   " << LongInt(arr, n) - LongInt(arr2, n2) << endl;
    cout << "*   " << LongInt(arr, n) * LongInt(arr2, n2) << endl;
    cout << "/   " << LongInt(arr, n) / LongInt(arr2, n2) << endl;
    cout << "%   " << LongInt(arr, n) % LongInt(arr2, n2) << endl;
    cout << "pow   " << LongInt(arr) ^ k << endl;*/
    
    delete [] arr;
    delete [] arr2;
    
    return 0;
}
