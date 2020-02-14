#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int a = 0;
    int b = 0;

    int res = 1;

    int i = 0;

    while(str[i] != '\0')
    {
        if (str[i] == '(')
            a++;
        else
            b++;

        if (b > a)
        {
            res = 0;
            break;
        }
        i++;
    }

    if (a != b)
        res = 0;

    if (res == 1)
        cout << "Good";
    else
        cout << "Bad";

    return 0;
}
