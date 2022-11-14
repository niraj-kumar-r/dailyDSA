#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            sum %= 998244353;
        }
        cout << sum * (sum - 1) << endl;
    }
    return 0;
}
