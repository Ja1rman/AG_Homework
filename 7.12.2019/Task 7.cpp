#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int energ[n + 1];
    energ[0] = 0;
    int gold[n];
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> gold[i] >> energ[i + 1];

    int nrj[n + 1];
    nrj[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= i; j++)
            temp += energ[j];
        
        nrj[i] = temp;
    }
    
    int max = 0;
    
    for (int i = 0; i < n; i++)
    {
        int temp = gold[i];
        int nn = i;
        while (1)
        {
            nn++;
            if (x[nn] - x[i] <= nrj[nn + 1] - nrj[i])
                temp += gold[nn];
            else
                break;
        }
        if (temp > max)
            max = temp;
    }
    

    cout << max;
    
    return 0;
}
