//Количество буферов: 4
#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int k = 4;

    string b[k];

    for (int i = 0; i < k - 1; i++)
    {
        cout << "Enter information in the" << i << "buffer";

        cin >> b[i];

        int size = b[i].size();

        char[size] A = b[i];

        bool* B = (bool*) A;

        for (int j = 0; j < sizeof (B); j++)
        {
            cout << B[j];

        }
        cout << endl;
    }

    return 0;
}
