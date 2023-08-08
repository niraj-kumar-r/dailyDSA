#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        long long n = 0;
        cin >> n;
        long long k = 2;
        bool flag = false;
        while (1 + k + (k * k) <= n)
        {
            long double k_p = (n * (k - 1)) + 1;
            long int p = floor((long double)log10(k_p) / (long double)log10(k));
            if ((k_p == pow(k, p) || k_p == pow(k, p + 1)) && p > 1)
            {
                flag = true;
                break;
            }

            k++;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}