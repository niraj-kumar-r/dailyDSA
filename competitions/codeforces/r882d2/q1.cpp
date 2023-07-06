#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k, l = 0, r = 0, sumD = 0;
        cin >> n >> k;
        priority_queue<int, vector<int>, greater<int>> pq;
        cin >> l;
        for (int i = 1; i < n; i++)
        {
            cin >> r;
            pq.push(abs(r - l));
            sumD += abs(r - l);
            if (pq.size() > k - 1)
                pq.pop();
            l = r;
        }
        while (pq.size() > 0)
        {
            sumD -= pq.top();
            pq.pop();
        }
        cout << sumD << endl;
    }
}