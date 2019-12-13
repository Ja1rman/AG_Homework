#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int* energ = new int[n + 1];
    energ[0] = 0;
    int* gold = new int[n];
    int* x = new int[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> energ[i + 1] >> gold[i];

    int max = 0;
    
    for (int i = 0; i < n; i++)
    {
        int temp = gold[i];
        int nn = i;
        while (1)
        {
            nn++;
            if (x[nn] - x[i] <= energ[nn] - energ[i])
            {
                temp += gold[nn];
            }
            else
                break;
        }
        if (temp > max)
            max = temp;
    }
    

    cout << max;
    
    return 0;
}
