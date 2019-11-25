#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        int arr = pow (10, n / 2 - 1);

        while (arr < pow (10, n / 2))
        {
            cout << arr;
            int temp = arr;
            for (int i = 0; i < n / 2; i++)
            {
                cout << temp % 10;
                temp /= 10;
            }

            cout << " ";
            arr++;
        }
    }
    else
    {
        int arr = pow (10, (n + 1) / 2 - 1);

        while (arr < pow (10, (n + 1) / 2) - 1)
        {
            cout << arr;
            int temp = arr;
            for (int i = 0; i < (n + 1) / 2; i++)
            {
                if (i != 0)
                    cout << temp % 10;
                temp /= 10;
            }

            cout << " ";
            arr++;
        }
    }
    return 0;
}

/*
*/
