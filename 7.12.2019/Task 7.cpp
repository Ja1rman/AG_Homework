#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int res(vector <pair <int, pair <int, int>>> arr, int n0, int nn)
{
    
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

    int k = res(arr, 0, nn);

    cout << k;
    
    
    
    return 0;
}
