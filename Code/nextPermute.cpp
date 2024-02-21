#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int l = nums.size();
        for (int i = l - 2; i >= 0; i--)
        {
            for (int j = l - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                {
                    int k = nums[i];
                    nums[i] = nums[j];
                    nums[j] = k;
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 2};
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}