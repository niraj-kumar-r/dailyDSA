#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 1;
        cin >> n;
        long long temp = 0, s = 0;
        cin >> temp;
        s = temp;
        for (int i = 1; i < n; i++)
        {
            cin >> temp;
            if (s == 0)
            {
                k++;
                s = temp;
            }
            else
            {
                s = s & temp;
            }
        }
        if (s != 0 && k > 1)
            k--;
        cout << k << endl;
    }
}