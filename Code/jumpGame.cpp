#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    vector<bool> arr(nums.size(), false);
    arr[0] = true;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            for (int j = 1; i + j < n && j <= nums[i]; j++)
            {
                arr[i + j] = true;
            }
        }
        if (arr[n - 1])
        {
            return true;
        }
    }
    return arr[n - 1];
}

int main()
{
    vector<int> sample{2, 3, 1, 1, 4};
    cout << canJump(sample);
}