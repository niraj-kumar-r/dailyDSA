#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 1, k = 1, x = 1;
        cin >> n >> k >> x;
        if (x != 1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else if (k == 1)
        {
            cout << "NO" << endl;
        }
        else if (n == k)
        {
            cout << "YES" << endl;
            cout << 1 << endl
                 << k << endl;
        }
        else if (n % 2 == 0)
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2; i++)
            {
                cout << 2 << " ";
            }
            cout << endl;
        }
        else if (k >= 3)
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2 - 1; i++)
            {
                cout << 2 << " ";
            }
            cout << 3 << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}