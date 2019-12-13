#include <iostream>

using namespace std;

int res(int* x, int* zoloto, int* nrj, int i)
{
    int nn = i;
        while (1)
        {
            nn++;
            if ((x[nn] - x[i] > nrj[nn + 1] - nrj[i]) && nn <= n)
            {
                return temp = zoloto[nn] - zoloto[i];
                
            }
            else if (nn > n)
            {
                return temp = zoloto[nn] - zoloto[i];
                
            }
        }
        
}

int main()
{
    int n;
    cin >> n;

    int energ[n];
    int gold[n];
    int* x = new int[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> gold[i] >> energ[i];

    int* nrj = new int[n + 1];
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
        int temp = res(x, zoloto, nrj, i);
        
        if (temp > max)
            max = temp;
    }
    
    if (n == 1)
        max = zoloto[1];
    cout << max;
    
    delete [] zoloto;
    delete [] x;
    delete [] nrj;
    
    return 0;
}
