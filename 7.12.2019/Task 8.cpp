/*
Напишите программу, находящую k-ую порядковую статистику. Программа должна работать за время O(n) в среднем.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    vector <int> arr;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        arr.push_back(p);
    }

    int k;
    cin >> k;
    k--;
    nth_element( arr.begin(), arr.begin() + k, arr.end() );
    
    cout << arr[k];

    return 0;
}
