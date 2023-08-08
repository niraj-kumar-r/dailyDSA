#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count = 0, a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            if (b < a)
                count++;
        }
        cout << count << endl;
    }
}