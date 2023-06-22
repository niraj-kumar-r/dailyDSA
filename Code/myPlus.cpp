#include <iostream>
#include <vector>
using namespace std;

class Solution
{

public:
    vector<int> plusOne(vector<int> &digits)
    {
        int v = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int a = (digits[i] + v) % 10;
            v = (digits[i] + v) / 10;
            digits[i] = a;
            if (v == 0)
            {
                return digits;
            }
        }
        while (v != 0)
        {
            digits.insert(digits.begin(), v % 10);
            v /= 10;
        }
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> digits = {9, 9, 9};
    vector<int> res = s.plusOne(digits);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}