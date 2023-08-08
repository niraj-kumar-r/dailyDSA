#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        long long n, d, h;
        cin >> n >> d >> h;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long double area = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] + h < a[i + 1])
            {
                area += (long double)(d * h) / 2;
            }
            else
            {

                long double x = ((long double)(h - a[i + 1] + a[i]) / h) * d;
                area += (long double)(x + d) * (a[i + 1] - a[i]) / 2;
            }
        }
        area += (long double)(d * h) / 2;
        cout << fixed << setprecision(20) << area << endl;
    }
}