#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main()
{
    setlocale(LC_ALL, "rus");

    map <string, int> chars;

    string text;
    cout << "Введите текст для кодирования:" << endl;
    getline(cin, text);

    for(unsigned int i = 0; i < text.size(); i++)
        chars.insert(pair<string,int>(text[i], 1));

    map <string, int>::iterator begin, at, end;
    begin = chars.begin();
    end = chars.end();

    int size = chars.size();
    vector <pair<int, string> > arr(size);

    for(at = begin; at != end; at++)
    {
        int a = at -> second;
        string b = at -> first;
        arr.push_back(make_pair(a,b));
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].first << ", " << arr[i].second << endl;
    }
    /*sort(arr.begin(), arr.end(), cmp);
    arr.erase(arr.begin(), arr.begin() + size);

 /*   vector <pair<string, char> > res(size);

    for (int i = 0; i < arr.size(); i++)
    {
        res.push_back(make_pair("", arr[i].second[0]));
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first << ", " << res[i].second << endl;
    }
/*
    while (arr.size() > 1)
    {
        int a = arr[0].first;
        string aa = arr[0].second;
        int b = arr[1].first;
        string bb = arr[1].second;

        for (int i = 0; i < aa.size(); i++)
            for (int j = 0; j < res.size(); j++)
                if (res[j].second == aa[i])
                {
                    if (a > b) res[j].first += '1';
                    else res[j].first += '0';
                    break;
                }

        for (int i = 0; i < bb.size(); i++)
            for (int j = 0; j < res.size(); j++)
                if (res[j].second == bb[i])
                {
                    if (a > b) res[j].first += '0';
                    else res[j].first += '1';
                    break;
                }

        arr[1].first += arr[0].first;
        arr[1].second += arr[0].second;

        arr.erase(arr.begin());

        sort(arr.begin(), arr.end(), cmp);
    }
*/
    return 0;
}
