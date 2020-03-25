#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the number of character words: ";
    int n = 0;
    cin >> n;

    int res = n;

    char a[n];
    char b[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];

        if (a[i] == b[i]) res--;
    }
    cout << res;

    return 0;
}
