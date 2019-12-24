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

typedef struct LongInt
{
    int n;
    int* arr;
   
    LongInt(int* a, int b)
    {
        n = b;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
    }
   
    LongInt(LongInt const &X)
    {
        n = X.n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = X.arr[i];
    }
   
    ~LongInt()
    {
        delete[] (*this).arr;
    }
    
    LongInt& operator= (const LongInt& a)
    {
        return LongInt(a);
    }
    
} LongInt ;

istream& operator>> (std::istream& in, LongInt &a)
{
    string str;
    in >> str;
    a.n = str.size();
    a.arr = new int[a.n];
    for (int i = 0; i < a.n; i++)
        a.arr[i] = str[i] - '0';
    return in;
}

ostream& operator<< (std::ostream& out, LongInt &a)
{
    for(int i = 0; i < a.n; i++)
        out << (int) a.arr[i];
    return out;
}

bool operator> (const LongInt& a, const LongInt& b)
{
    if (a.n == b.n)
    {
        int i = 0;
        while (i < a.n)
        {
            if (a.arr[i] > b.arr[i])
                return 1;
            else if (a.arr[i] < b.arr[i])
                return 0;
            if (a.arr[i] == b.arr[i] && i == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else
    {
        if (a.n >= b.n)
            return 1;
        else 
            return 0;
    }
}


LongInt operator+ (const LongInt& a, const LongInt& b)
{
    if (a.n > b.n)
    {
        int* temp = new int[a.n + 1];
        for (int i = 0; i <= a.n; i++)
            temp[i] = 0;
           
        int j = a.n;
        int jj = b.n - 1;
        while (j > 0)
        {
            if (jj >= 0)
            {
                int p = a.arr[j - 1] + b.arr[jj] + temp[j];
                if (p > 9)
                {
                    int tt = p % 10;
                    temp[j] = tt;
                    p /= 10;
                    temp[j - 1] = p;
                }
                else 
                    temp[j] = p;
                    
                jj--;
            }
            else
                temp[j] = a.arr[j] + temp[j];
           
            j--;
        }
   
        if (temp[0] != 0)
        {
            LongInt xX(temp, a.n + 1);
            return xX;
        }
        else
        {
            int* temp2 = new int[a.n];
            for (int i = 0; i < a.n; i++)
                temp2[i] = temp[i + 1];
                
            LongInt xX(temp2, a.n);
            return xX;               
        }
    }
    else
    {
        int* temp = new int[b.n + 1];
        for (int i = 0; i <= b.n; i++)
            temp[i] = 0;
           
        int j = b.n;
        int jj = a.n - 1;
        while (j > 0)
        {
            if (jj >= 0)
            {
                int p = b.arr[j - 1] + a.arr[jj] + temp[j];
                if (p > 9)
                {
                    int tt = p % 10;
                    temp[j] = tt;
                    p /= 10;
                    temp[j - 1] = p;
                }
                else 
                    temp[j] = p;
                    
                jj--;
            }
            else
                temp[j] = b.arr[j] + temp[j];
           
            j--;
        }
   
        if (temp[0] != 0)
        {
            LongInt xX(temp, b.n + 1);
            return xX;
        }
        else
        {
            int* temp2 = new int[b.n];
            for (int i = 0; i < b.n; i++)
                temp2[i] = temp[i + 1];
            LongInt xX(temp2, b.n);
            return xX;               
        }
    }
}
/*LongInt operator- (LongInt a, LongInt b)
{
//    if (a >= b)
    {
        return a - b;
    }
//    else
    {
        //-(b - a);
    }
}
LongInt operator* (LongInt a, LongInt b)
{
   
}
LongInt operator/ (LongInt a, LongInt b)
{
   
}
LongInt operator% (LongInt a, LongInt b)
{
   
}
LongInt operator^ (LongInt& a, int k)
{
    if (k == 1)
        return LontInt(a.arr, a.n);
    else if (k == 0)
        return 1;
    else
    {
        while (k > 1)
        {
            //a = a * a;
            k--;
        }    
        
        //return LongInt(a); 
    }
}
*/

int main()
{
    int t[2] = {1, 0};
    LongInt a(t, 2);
    LongInt b(t, 2);
    cin >> a >> b;
    
    LongInt p = a + b;
    
    cout << "+ " << p << endl;
    /*cout << "- " << a - b << endl;
    cout << "*   " << a * b << endl;
    cout << "/   " << a / b << endl;
    cout << "%   " << a % b << endl;
    cout << "pow   " << a ^ k << endl;*/
   
    return 0;
}
