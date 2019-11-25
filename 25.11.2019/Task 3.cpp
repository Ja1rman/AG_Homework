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

        for (int i = 1; i <= sqrt(k); i++)
        {
            int j = i + i + 2;
            while (j < k + 2)
            {
                arr[j - 1] = 0;
                j += i + 1;
            }
        }


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
