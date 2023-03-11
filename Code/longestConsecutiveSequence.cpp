#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> mySet(nums.begin(), nums.end());

        int max_consecutive = 0;

        for (const auto &elem : mySet)
        {
            if (mySet.find(elem - 1) == mySet.end())
            {
                int new_max = 1;
                for (int i = elem + 1; mySet.find(i) != mySet.end(); i++)
                {
                    new_max++;
                }
                max_consecutive = new_max > max_consecutive ? new_max : max_consecutive;
            }
        }
        return max_consecutive;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 76, 43, 5};
    Solution obj = Solution();
    cout << obj.longestConsecutive(nums) << "\n";
}