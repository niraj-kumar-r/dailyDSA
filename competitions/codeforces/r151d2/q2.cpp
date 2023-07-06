#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        long long dxab = xb - xa;
        long long dyab = yb - ya;
        long long dxac = xc - xa;
        long long dyac = yc - ya;
        long long ansx = 0, ansy = 0;
        if (dxab * dxac > 0)
        {
            ansx = min(abs(dxab), abs(dxac));
        }
        if (dyab * dyac > 0)
        {
            ansy = min(abs(dyab), abs(dyac));
        }
        cout << ansx + ansy + 1 << endl;
    }
}