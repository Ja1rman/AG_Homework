#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, char> p1, pair<int, char> p2)
{
    return p1.first < p2.first;
}

int main()
{
    setlocale(LC_ALL, "rus");

    map <char, int> chars;

    char str[500];
    cout << "Введите текст для кодирования:" << endl;
    gets(str);

    for(unsigned int i = 0; i < strlen(str); i++)
        chars[str[i]]++;

    map <char, int>::iterator begin, at, end;
    begin = chars.begin();
    end = chars.end();

    int size = chars.size();
    vector <pair<int, string> > arr(size);

    for(at = begin; at != end; at++)
    {
        int a = at -> second;
        string b(at -> first, 1);
        arr.push_back(make_pair(a,b));
    }

    sort(arr.begin(), arr.end(), cmp);
    arr.erase(arr.begin(), arr.begin() + size);

    vector <pair<string, string> > res(size);

    for (int i = 0; i < arr.size(); i++)
        res.push_back(make_pair('\0', arr[i].second));

    while (arr.size() > 1)
    {
        int a = arr[0].first;
        string aa = arr[0].second;
        int b = arr[1].first;
        string bb = arr[1].second;

        for (int i = 0; i < aa.size(); i++)
            for (int j; j < res.size(); j++)
                if (res[j].second[0] == aa[i])
                {
                    if (a > b) res[j].first += '1';
                    else res[j].first += '0';
                    break;
                }

        for (int i = 0; i < bb.size(); i++)
            for (int j; j < res.size(); j++)
                if (res[j].second[0] == bb[i])
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

    return 0;
}
