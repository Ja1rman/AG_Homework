#include <iostream>
#include <vector>
#include <utility>

using namespace std;

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



    return 0;
}
