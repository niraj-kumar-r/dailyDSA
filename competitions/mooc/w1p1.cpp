#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll sn = 0, sm = 0;
        ll x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            sn += x;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            sm += x;
        }
        if (sn > sm)
            cout << "Yudhisthira\n";
        else if (sn < sm)
            cout << "Duryodhana\n";
        else
            cout << "Draw\n";
    }
}