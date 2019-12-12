#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int merge(vector <pair <int, pair <int, int>>> arr, int n0, int nn)
{
    
}

int res(vector <pair <int, pair <int, int>>> arr, int n0, int nn)
{
    if (n0 < nn)
    {
        res(arr, n0, (n0 + nn) / 2);
        res(arr, (n0 + nn) / 2 + 1, nn);
        merge(arr, n0, nn);
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

    int k = res(arr, 0, nn);

    cout << k;
    
    return 0;
}
