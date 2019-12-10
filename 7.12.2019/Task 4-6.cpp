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
#include <string>

using namespace std;

struct LongInt
{
    int n;
    int* arr;
   
    LongInt(int* a, int b)
    {
        n = b;
        int* arr = new int[n];
        for (int i; i < n; i++)
            arr[i] = a[i];
    }
   
    LongInt(LongInt &X)
    {
        n = X.n;
        int* arr = new int[n];
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
        int* temp = new int[a.n + 1];
        for (int i = 0; i <= a.n; i++)
            temp[i] = 0;
           
        int j = a.n - 1;
        int jj = b.n - 1;
        while (j >= 0)
        {
            if (jj >= 0)
            {
                int p = a.arr[j] + b.arr[jj] + temp[j];
                if (p > 10)
                {
                    if (j != a.n - 1)
                        temp[j + 1] = p % 10;
                    else
                        temp[j + 1] = p % 10 + temp[j];
                    temp[j] = p / 10;
                }
            }
            else
                temp[j + 1] = a.n + temp[j];
           
            j--;
            jj--;
        }
   
        if (temp[0] != 0)
            return LongInt(temp, a.n + 1);
        else
        {
            int* temp2 = new int[a.n];
            for (int i = 0; i < a.n; i++)
                temp2[i] = temp[i + 1];
               
            return LongInt(temp2, a.n);
        }
    }
    else
    {
        int* temp = new int[b.n + 1];
        for (int i = 0; i <= b.n; i++)
            temp[i] = 0;
           
        int j = b.n - 1;
        int jj = a.n - 1;
        while (j >= 0)
        {
            if (jj >= 0)
            {
                int p = b.arr[j] + a.arr[jj] + temp[j];
                if (p > 10)
                {
                    if (j != b.n - 1)
                        temp[j + 1] = p % 10;
                    else
                        temp[j + 1] = p % 10 + temp[j];
                    temp[j] = p / 10;
                }
            }
            else
                temp[j + 1] = b.n + temp[j];
           
            j--;
            jj--;
        }
       
        if (temp[0] != 0)
            return LongInt(temp, b.n + 1);
        else
        {
            int* temp2 = new int[b.n];
            for (int i = 0; i < b.n; i++)
                temp2[i] = temp[i + 1];
               
            return LongInt(temp2, b.n);
        }
    }
};

LongInt operator- (LongInt a, LongInt b)
{
    if (a > b)
    {
        a - b;
    }
    else
    {
        -(b - a);
    }
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

bool operator> (Rational a, Rational b)
{
    if (a.n != b.n)
    {
        if (a.n > b.n)
            return 1;
        else 
            return 0;
    }
    else
    {
        int i = a.n - 1;
        while (i >= 0)
        {
            if (a.arr[i] > b.arr[i])
                return 1;
            if (a.arr[i] == b.arr[i] && i == 0)
                return 1;
        }
        return 0;
    }
};

ostream& operator<< (std::ostream& out, const LongInt &a)
{
    string str = string(a.arr);
    return out << str;
};

istream& operator>> (std::istream& in, LongInt &a)
{
    string str;
    in >> str;
    a.n = str.size();
    a.arr = new int[a.n];
    for (int i = 0; i < a.n; i++)
        a.arr[i] = str[i];
   
    return in;
};

int main()
{
    LongInt a();
    LongInt b();
    cin >> a >> b;
   
    cout << "+   " << a + b << endl;
    /*cout << "-   " << LongInt(arr, n) - LongInt(arr2, n2) << endl;
    cout << "*   " << LongInt(arr, n) * LongInt(arr2, n2) << endl;
    cout << "/   " << LongInt(arr, n) / LongInt(arr2, n2) << endl;
    cout << "%   " << LongInt(arr, n) % LongInt(arr2, n2) << endl;
    cout << "pow   " << LongInt(arr) ^ k << endl;*/
   
    return 0;
}
