/*
Íàïèøèòå ýôôåêòèâíóþ ôóíêöèþ, âûïèñûâàþùóþ èç ìàññèâà äëèíû n âñå ýëåìåíòû,
ó êîòîðûõ êîëè÷åñòâî äâîåê â òðîè÷íîé çàïèñè ìåíüøå k.
Ôóíêöèÿ äîëæíà âîçâðàùàòü îáùåå êîëè÷åñòâî äâîåê â òðîè÷íîé çàïèñè âñåõ ÷èñåë ìàññèâà.
Â êîììåíòàðèÿõ íàïèøèòå, ïî÷åìó ïåðåáîð - ýôôåêòèâíûé
*/

#include<iostream>

using namespace std;

int res(int* arr, int n, int k)
{
    int amount = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
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
