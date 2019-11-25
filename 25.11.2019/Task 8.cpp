/*
Напишите функцию вычисляющую праймориал числа. Программа должна работать не более чем за O(n*log log n) шагов.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = 1;

    for (int i = 2; i < sqrt(n); i++)
        for (int j = i + i - 1; j < n; j += i)
            arr[j] = 0;

    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            res *= i + 1;
    }

    cout << res;

	return 0;
}

/*
Поиск простых чисел делается так же, как и в 3 задаче, но теперь мы отмеченные числа перемножаем между собой.
*/
