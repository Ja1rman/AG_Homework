#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int res(vector <pair <int, pair <int, int>>> arr, int n0, int nn)
{
    int i;

    while (n0 < nn)
    {
        i = (n0 + nn) / 2;
        if (k > arr[i])
            n0 = i + 1;
        else if (k < arr[i])
            nn = i;
        else if (k == arr[i])
            return 1;
    }
}

int main()
{
    int n;
    cin >> n;

    vector <pair<int, pair<int, int>>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, g, d;
        cin >> x >> g >> d;
        arr.push_back(make_pair(x, make_pair(g, d)));
    }

    int* mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        for (int j = 0; j <= i; j++)
            p += arr[j].second.second;
        
        mas[i] = p;
    }
    
    int max = 0;
    int n0 = 0;
    
    for (int i = 0; i < n; i++)
    {
        int m = res(arr, n0, n);
        
    }
    

    cout << ;
    
    return 0;
}
