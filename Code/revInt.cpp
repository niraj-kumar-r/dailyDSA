#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int a = abs(x);
        int rev = 0;
        while (a != 0)
        {
            try
            {
                if (rev > (INT_MAX - a % 10) / 10)
                {
                    throw "Overflow";
                }
                rev = rev * 10 + a % 10;
                a /= 10;
            }
            catch (...)
            {
                return 0;
            }
        }

        if (x < 0)
        {
            return -1 * rev;
        }
        return rev;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-2147483648) << endl;
    return 0;
}