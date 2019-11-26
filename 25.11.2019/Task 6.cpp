/*
Напишите эффективную функцию, выписывающую из массива длины n все элементы,
у которых количество двоек в троичной записи меньше k.
Функция должна возвращать общее количество двоек в троичной записи всех чисел массива.
В комментариях напишите, почему перебор - эффективный
*/

#include<iostream>

using namespace std;

int res(int* arr, int n, int k)
{
    int amount = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        int sum = 0;
        while(temp > 0)
        {
            if (temp % 3 == 2)
                sum++;

            temp /= 3;
        }
        if (sum < k)
            amount += sum;
    }
    return amount;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << res(arr, n, k);

    delete [] arr;

    return 0;
}
