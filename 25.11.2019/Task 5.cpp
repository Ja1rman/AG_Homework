/*
�������� ���������, ��������� ��� ������� ����� ���� �� ������������� n.
��������� ������ �������� �� ����� ��� �� O(n*log log n) �����.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n - 1];

    for (int i = 0; i < n - 1; i++)
        arr[i] = 0;

    for (int i = 2; i < sqrt(n); i++)
        if (arr[i - 1] == 0)
            for (int j = i + i - 1; j < n ; j += i)
                arr[j] = i;

    for (int i = 2; i < n; i++)
        if (arr[i - 1] == 0 && arr[i + 1] == 0)
            cout << i << " ";
        else if (arr[i - 1] == 0 && arr[(i + 1) / arr[i + 1]] == 0)
            cout << i << " ";

    return 0;
}

/*
������� ���������� ���������� ����� �� 1 �� n, � ����� �� ����������� �������
������� ����� ����
*/
