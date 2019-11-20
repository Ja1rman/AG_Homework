/*Напишите программу находящую первые n составных чисел.
Программа должна работать не более чем за O(n*log log n) шагов.*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int k = 1, count = 0;

    while (count < n)
    {
        int p = sqrt(k);
        int del = 2;
        while (del <= p)
        {
            if (k % del == 0)
            {
                cout << k << " ";
                count++;
                break;
            }
            del++;
        }
        k++;
    }

    return 0;
}
