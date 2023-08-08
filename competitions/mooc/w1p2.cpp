#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int m, n;
    ll s, x;
    cin >> m >> n >> s >> x;
    vector<ll> v1, v2;
    ll inp = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                cin >> inp;
                v1.push_back(inp);
            }
            else if (i == m - 1)
            {
                cin >> inp;
                v2.push_back(inp);
            }
            else
            {
                if (j == 0)
                {
                    cin >> inp;
                    v2.push_back(inp);
                }
                else if (j == n - 1)
                {
                    cin >> inp;
                    v1.push_back(inp);
                }
                else
                {
                    cin >> inp;
                }
            }
        }
    }
    // reverse v1
    reverse(v1.begin(), v1.end());

    for (ll i = 0; i < s; i++)
    {
        // turn clockwise from v1 to v2
        ll temp = v1[0];
        v1.erase(v1.begin());
        v2.push_back(temp);

        // turn anticlockwise from v2 to v1
        temp = v2[0];
        v2.erase(v2.begin());
        v1.push_back(temp);
    }

    // reverse v1
    reverse(v1.begin(), v1.end());

    for (int i = 0; i < v1.size(); i++)
    {
        if (i % x == 0)
            cout << v1[i] << " ";
    }
    for (int i = v2.size() - 1; i >= 0; i--)
    {
        if ((i + 1) % x == 0)
            cout << v2[i] << " ";
    }
}