/*
�������� ����������� ���������,
������������ �� ������� ����� n ��� ��������, � ������� ������������ ��������� ���� ������ k.
� ������������ ��������, ������ ������� - �����������
*/

#include <iostream>

using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] != 0)
        {
            int temp = arr[i];

            if (arr[i] < 0)
                temp *= -1;

            int res = 1;
            while (temp >= 1)
            {
                int p = temp % 10;
                if (p > 0)
                    res *= p;

                temp /= 10;
            }
            if (res > k)
                cout << arr[i] << " ";
        }
        else
            if (0 > k)
                cout << arr[i] << " ";
    }



    return 0;
}

/*

*/
