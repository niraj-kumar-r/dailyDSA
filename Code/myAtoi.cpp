#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        bool isNeg = false;
        long val = 0;
        while (isspace(s[i]))
        {
            i++;
        }

        if (!isdigit(s[i]))
        {
            isNeg = s[i] == '-' ? true : false;
            i++;
        }
        while (isdigit(s[i]))
        {
            val = (val * 10) + s[i] - 48;
            if (val > INT_MAX)
            {
                break;
            }
            i++;
        }
        val = isNeg ? -1 * val : val;
        return (val > INT_MAX) ? INT_MAX : (val < INT_MIN ? INT_MIN : val);
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("42") << endl;
    // cout << s.myAtoi("   -42") << endl;
    // cout << s.myAtoi("4193 with words") << endl;
    // cout << s.myAtoi("words and 987") << endl;
    // cout << s.myAtoi("-91283472332") << endl;
    // cout << s.myAtoi("91283472332") << endl;
    // cout << s.myAtoi("3.14159") << endl;
    // cout << s.myAtoi("+-12") << endl;
    // cout << s.myAtoi("  -0012a42") << endl;
}
