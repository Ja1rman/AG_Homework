/*
Напишите программу находящую первые n составных чисел.
Программа должна работать не более чем за O(n*log log n) шагов.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

    if (n < 5)
    {
        int arr[4] = {4, 6, 8, 9};
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    else
    {
        int k = n * 2;

        int arr[k];
        for (int i = 0; i < k; i++)
            arr[i] = 1;

        for (int i = 2; i < sqrt(k); i++)
            for (int j = i + i - 1; j < k; j += i)
                arr[j] = 0;

        int i = 3;
        int p = 0;
        while (i < n * 2 && p < n)
        {
            if (arr[i] == 0)
            {
                cout << i + 1 << " ";
                p++;
            }
            i++;
        }
    }
	return 0;
}

/*
Программа по самому эффективному алгоритму (Эратосфена) заполняет базу значений простых чисел. А далее выводит составные.
*/
