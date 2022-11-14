#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t = 0;
    cin >> t;
    while (t--)
    {
        long long n = 0, k = 0, l = 0;
        cin >> n >> k >> l;
        if (k + l > n)
        {
            long long diff = k + l - n;
            cout << (k - diff) * (l - diff) << endl;
            return 0;
        }

        else
        {
            long long maxEdges = k * l;
            maxEdges += (n - k - l) * (k + l);
            maxEdges += ((n - k - l) / 2) * (n - k - l - 1);
            cout << maxEdges << endl;
        }
    }

    return 0;
}