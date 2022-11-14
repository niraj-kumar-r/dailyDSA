#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> factorial = {};

long long fact(long long n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (factorial.find(n) != factorial.end())
    {
        return factorial[n];
    }
    else
    {
        factorial[n] = (n * fact(n - 1)) % 1000000007;
        return factorial[n];
    }
}

int main()
{
    // your code goes here
    long long t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += fact(arr[i]);
            sum %= 1000000007;
        }
        cout << sum << endl;
    }
}
