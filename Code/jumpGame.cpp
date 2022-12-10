#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int max_jump_index = 0;
    for (int i = 0, n = nums.size(); max_jump_index >= i && max_jump_index < n; i++)
    {
        max_jump_index = i + nums[i] > max_jump_index ? i + nums[i] : max_jump_index;
    }
    return max_jump_index >= nums.size() - 1;
}

int main()
{
    vector<int> sample{2, 3, 1, 1, 4};
    cout << canJump(sample);
}