#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPrime(int n)
{
    if (n == 2 or n == 3) return false;
    if (n < 2 or n % 2 == 0) return true;
    if (n < 9) return false;
    if (n % 3 == 0) return true;

    int r = int(sqrt(n));
    int f = 5;

    while (f <= r)
    {
        if (n % f == 0) return true;
        if (n % (f + 2) == 0) return true;
        f += 6;
    }

    return false;
}

bool both(long long a, long long b)
{
    if (b % a == 0) return true;
    if (a % 2 == 0 and b % 2 == 0) return true;
    if (a % 3 == 0 and b % 3 == 0) return true;
    if (a % 5 == 0 and b % 5 == 0) return true;

    int r = int(sqrt(a));
    int f = 5;

    while (f <= r)
    {
        if (a % f == 0 and b % f == 0) return true;
        if (a % (f + 2) == 0 and b % (f + 2) == 0) return true;
        f += 6;
    }

    return false;
}

void keys(long long *e, long long *n, long long *d)
{
    srand(time(NULL));
    int p = 10000 + rand() % 99999;
    while (isPrime(p))
        p = 10000 + rand() % 99999;

    int q = 10000 + rand() % 99999;
    while (isPrime(q))
        q = 10000 + rand() % 99999;

    *n = p * q;

    long long func = (p - 1) * (q - 1);
    long long funcc = sqrt(func);
    *e = (9 + rand()) % funcc;
    long long ee = *e;
    while (both(ee, func))
    {
        *e = (9 + rand()) % funcc;
        ee = *e;
    }

    *d = 0;
    int k = 1;
    while (*d == 0)
    {
        long long temp = (func*k + 1) / *e;
        if ((func*k + 1) % *e == 0) *d = temp;
        k += 1;
    }
}

long long encryption(long long m, long long e, long long n)
{
    long long c = 1;
    for(int i = 0; i < e; i++)
        c = c * m % n;;

    return c;
}

long long decryption(long long c, long long d, long long n)
{
    long long m = 1;
    for(int i = 0; i < d; i++)
        m = m * c % n;

    return m;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите шифруемое сообщение (число)" << endl;
    long long m;
    cin >> m;

    long long e = 0;
    long long n = 0;
    long long d = 0;
    keys(&e, &n, &d);
    cout << endl << "Ключи: e = " << e << " n = " << n << " d = " << d << endl;

    long long c = encryption(m, e, n);
    cout << "Зашифрованное сообщение: " << c << endl;

    m = decryption(c, d, n);
    cout << "Расшифрованное сообщение: " << m;

    return 0;
}
