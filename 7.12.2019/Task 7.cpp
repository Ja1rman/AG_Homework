#include <iostream>

using namespace std;

int res(int* x, int* zoloto, int* nrj, int n0, int nn)
{
    int i;

    while (n0 < nn)
    {
        i = (n0 + nn) / 2;
        if (x[nn] - x[n0] >= nrj[nn + 1] - nrj[n0] && x[nn - 1] - x[n0] <= nrj[nn] - nrj[n0])
            return zoloto[nn] - zoloto[i];
        else if (x[nn] - x[n0] >= nrj[nn + 1] - nrj[n0] && x[nn - 1] - x[n0] >= nrj[nn] - nrj[n0])
            n0 = i + 1;
        else if (x[nn] - x[n0] <= nrj[nn + 1] - nrj[n0] && x[nn - 1] - x[n0] <= nrj[nn] - nrj[n0])
            nn = i; 
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
