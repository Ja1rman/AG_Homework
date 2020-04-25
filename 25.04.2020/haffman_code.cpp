#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, string> p1, pair<int, string> p2)
{
    if (p1.first < p2.first or p1.first > p2.first)
        return p1.first < p2.first;
    else
    {
        if (p1.second.size() < p2.second.size())
            return 0;
        else
            return 1;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    vector <pair<int, string> > arr;

    string str;
    cout << "Введите текст для кодирования:" << endl;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        string temp = "";
        temp += str[i];
        int quant = 0;
        int num = 0;
        for (int j = 0; j < arr.size(); j++)
            if (arr[j].second == temp)
            {
                quant = arr[j].first + 1;
                num = j;
            }

        if (quant == 0)
            arr.push_back(make_pair(1, temp));
        else
            arr[num].first = quant;

    }

    sort(arr.begin(), arr.end(), cmp);
//norm
    vector <pair<string, string> > res;

    for (int i = 0; i < arr.size(); i++)
    {
        res.push_back(make_pair("", arr[i].second));
    }

    if (arr.size() > 1)
        while (arr.size() > 1)
        {
            int a = arr[0].first;
            string aa = arr[0].second;
            int b = arr[1].first;
            string bb = arr[1].second;

            for (int i = 0; i < aa.size(); i++)
                for (int j = 0; j < res.size(); j++)
                    if (res[j].second[0] == aa[i])
                    {
                        if (a > b)
                        {
                            string temp = "1" + res[j].first;
                            res[j].first = temp;
                        }
                        else
                        {
                            string temp = "0" + res[j].first;
                            res[j].first = temp;
                        }
                        break;
                    }

            for (int i = 0; i < bb.size(); i++)
                for (int j = 0; j < res.size(); j++)
                    if (res[j].second[0] == bb[i])
                    {
                        if (a > b)
                        {
                            string temp = "0" + res[j].first;
                            res[j].first = temp;
                        }
                        else
                        {
                            string temp = "1" + res[j].first;
                            res[j].first = temp;
                        }
                        break;
                    }

            arr[1].first += arr[0].first;
            arr[1].second += arr[0].second;

            arr.erase(arr.begin());

            sort(arr.begin(), arr.end(), cmp);
        }
    else
    {
        res[0].first = "1";
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first << ", " << res[i].second << endl;
    }
    string code = "";
    for (int i = 0; i < str.size(); i++)
        for (int j = 0; j < res.size(); j++)
            if (res[j].second[0] == str[i])
            {
                code += res[j].first;
                break;
            }

    cout << endl << "Закодированный текст: " << code << endl;


    return 0;
}
