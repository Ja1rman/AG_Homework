#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int res(vector <pair <int, pair <int, int>>>, int n)
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

    int k = res(arr, n);

    cout << K;
    
    return 0;
}
