#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int m = nums[0];

        for (int i = 1, imax = m, imin = m, n = nums.size(); i < n; i++)
        {
            if (nums[i] < 0)
                swap(imax, imin);
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            m = max(m, imax);
        }
        return m;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 4, -4, 0, -2, -4, -1, -2, -3};
    cout << s.maxProduct(nums) << endl;
    return 0;
}