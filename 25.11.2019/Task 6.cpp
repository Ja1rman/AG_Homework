/*
�������� ����������� �������, ������������ �� ������� ����� n ��� ��������,
� ������� ���������� ����� � �������� ������ ������ k.
������� ������ ���������� ����� ���������� ����� � �������� ������ ���� ����� �������.
� ������������ ��������, ������ ������� - �����������
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
