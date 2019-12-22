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
        for (int i=0; i < n; i++)
            arr[i] = X.arr[i];
    }
   
    ~LongInt()
    {
        delete[] (*this).arr;
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
        while (i <= a.n)
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

/*
LongInt operator+ (const LongInt& a,const LongInt& b)
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
   
        if (temp[0] != 0){
            LongInt xX((int*)temp,(int) a.n+1);
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
       
        if (temp[0] != 0){
            LongInt xX(temp, b.n+1);
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
    if (a > b)
        cout << 1;
    else
        cout << 0;
    /*cout << "+ " << a + b << endl;
    /*cout << "- " << a - b << endl;
    cout << "*   " << a * b << endl;
    cout << "/   " << a / b << endl;
    cout << "%   " << a % b << endl;
    cout << "pow   " << a ^ k << endl;*/
   
    return 0;
}
