#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool leftGreater(pair<long long, long long> p1, pair<long long, long long> p2)
{
    if (p1.first > p2.first)
        return true;
    else if (p1.first == p2.first)
    {
        if (p1.second < p2.second)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        long long n = 1, m = 1, h = 1;
        vector<pair<long long, long long>> v = {};
        cin >> n >> m >> h;
        int countGreater = 0;
        pair<long long, long long> p = make_pair(0, 0);
        for (int i = 0; i < n; i++)
        {
            vector<long long> temp = {};
            for (int j = 0; j < m; j++)
            {
                long long x = 0;
                cin >> x;
                temp.push_back(x);
            }

            sort(temp.begin(), temp.end());
            long long points = 0, penalty = 0, count = temp[0];
            for (int j = 0; count <= h && j < m; j++)
            {
                points++;
                penalty += count;
                if (j + 1 < m)
                    count += temp[j + 1];
            }
            v.push_back(make_pair(points, penalty));
            if (i == 0)
            {
                p = make_pair(points, penalty);
            }
            else if (leftGreater(v[i], p))
                countGreater++;
        }
        cout << countGreater + 1 << endl;
    }
}