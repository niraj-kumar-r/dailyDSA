#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    if (n <= 1)
    {
        return s;
    }
    int maxLength = 0, maxLeft = 0, left, right;
    for (int start = 0; start < n && n - start > maxLength / 2;)
    {
        left = right = start;
        while (right < n - 1 && s[right + 1] == s[right])
        {
            right++;
        }
        start = right + 1;
        while (left > 0 && right < n - 1 && s[right + 1] == s[left - 1])
        {
            right++;
            left--;
        }
        if (maxLength < right - left + 1)
        {
            maxLength = right - left + 1;
            maxLeft = left;
        }
    }
    return s.substr(maxLeft, maxLength);
}

int main()
{
    string s = "aacabdkacaa";
    cout << longestPalindrome(s) << endl;
    return 0;
}