#include <iostream>

using namespace std;

int res(int* x, int* zoloto, int* nrj, int n0, int nn)
{
    int i;
    int mm = n0;
    int n = nn;
    while (n0 < nn)
    {
        i = (n0 + nn) / 2;
        if ((x[nn - 1] - x[mm] >= nrj[nn] - nrj[mm]) && (x[nn - 2] - x[mm] <= nrj[nn - 1] - nrj[mm]) && (nn <= n))
            return zoloto[nn - 1] - zoloto[mm];
        else if ((x[nn - 1] - x[mm] <= nrj[nn] - nrj[mm]) && (x[nn - 2] - x[mm] <= nrj[nn - 1] - nrj[mm]) && (nn <= n))
            n0 = i + 1;
        else if ((x[nn - 1] - x[mm] >= nrj[nn] - nrj[mm]) && (x[nn - 2] - x[mm] >= nrj[nn - 1] - nrj[mm]) && (nn <= n))
            nn = i; 
        else if (nn >= n);
            return zoloto[nn - 1] - zoloto[mm];
    }
    return -1;
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
        int temp = res(x, zoloto, nrj, i, n);
        
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
