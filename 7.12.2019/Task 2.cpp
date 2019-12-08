/*
Напишите программу на основе разделяй и властвуй позволяющую эффективно проверять 
принадлежность пары значений массиву. Например, пара (2,3) 
принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет. Можно считать, 
что количество запросов многократно превышает размер массива.  
В комментариях напишите, почему перебор - эффективное
*/

#include <iostream>

using namespace std;

void Merge(int *arr, int n0, int nn, int p)
{
    int mas[p + 1];
    int m = (n0 + nn) / 2;
    int start = n0;
    int final = m + 1;

    for(int j = n0; j <= nn; j++)
        if (start <= m && (final > nn || arr[start] < arr[final]))
        {
            mas[j] = arr[start];
            start++;
        }
        else
        {
            mas[j] = arr[final];
            final++;
        }

    for (int j = n0; j <= nn; j++)
        arr[j] = mas[j];
}

void MergeSort(int* arr, int n0, int nn, int p)
{
    if (n0 < nn)
    {
        MergeSort(arr, n0, (n0 + nn) / 2, p);
        MergeSort(arr, (n0 + nn) / 2 + 1, nn, p);
        Merge(arr, n0, nn, p);
    }
}

int res(int* arr, int nn, int k)
{
    int n0 = 1;

    int i;

    while (n0 < nn)
    {
        i = (n0 + nn) / 2;
        if (k > arr[i])
            n0 = i;
        else if (k < arr[i])
            nn = i;
        else if (k == arr[i])
            return 1;
    }
    return 2;
}

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int k1, k2;
    cin >> k1 >> k2;

    MergeSort(arr, 1, n, n);

    int p1 = res(arr, n++, k1);
    int p2 = res(arr, n++, k2);

    if (p1 == 1 && p2 == 1)
        cout << "YES";
    else
        cout << "NO";

    delete [] arr;

    return 0;
}
/*
Сортировка бинарным поиском одна из самых быстрых по времени работы, поэтому задача решена эффективно
*/
