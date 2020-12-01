#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> ans;
    int flag;
    Solution()
    {
        ans = vector<int>(2, -1);
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        searchHelper(0, nums.size(), nums, target);
        return ans;
    }
    void searchHelper(int start, int end, vector<int> &nums, int &target)
    {
        if (start >= end)
            return;
        flag = (end - start) / 2;
        if (nums[flag] == target)
        {
            ans[0] = min(ans[0], flag);
            ans[1] = max(ans[1], flag);
            searchHelper(start, flag, nums, target);
            searchHelper(start + 1, end, nums, target);
        }
        else if (nums[flag] > target)
        {
            searchHelper(start, flag, nums, target);
        }
        else
        {
            searchHelper(flag + 1, end, nums, target);
        }
    }
};
