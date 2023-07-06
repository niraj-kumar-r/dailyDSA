#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0)
        {
            return {};
        }

        vector<vector<int>> res = {};
        for (int i = 0, n = nums.size(); i < n - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (nums[j] == res[res.size() - 1][1] && j < k)
                    {
                        j++;
                    }
                    while (nums[k] == res[res.size() - 1][2] && j < k)
                    {
                        k--;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}