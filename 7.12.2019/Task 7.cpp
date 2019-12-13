#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int energ[n];
    int gold[n];
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> gold[i] >> energ[i];

    int nrj[n + 1];
    nrj[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= i; j++)
            temp += energ[j - 1];
        
        nrj[i] = temp;
    }
    
    int* zoloto = new int[n + 1];
    zoloto[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= i; j++)
            temp += gold[j - 1];
        
        zoloto[i] = temp;
    }
    
    int max = 0;
    
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        int nn = i;
        while (1)
        {
            nn++;
            if ((x[nn] - x[i] > nrj[nn + 1] - nrj[i]) && nn <= n)
            {
                temp = zoloto[nn] - zoloto[i];
                break;
            }
            else if (nn > n)
            {
                temp = zoloto[nn] - zoloto[i];
                break;
            }
        }
        if (temp > max)
            max = temp;
    }
    
    if (n == 1)
        max = zoloto[1];
    cout << max;
    
    delete [] zoloto;
    
    
    return 0;
}
