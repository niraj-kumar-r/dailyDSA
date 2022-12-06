#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int max_area = (min(height[left], height[right])) * (right - left);

    while (left < right)
    {
        if ((min(height[left], height[right])) * (right - left) > max_area)
        {
            max_area = (min(height[left], height[right])) * (right - left);
        }

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max_area;
}

int main()
{
    vector<int> h = {10, 7, 3, 9, 4};
    cout << maxArea(h);
}