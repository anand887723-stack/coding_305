/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution
{
public:
    bool makesquare(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 4)
            return false;

        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum % 4 != 0)
            return false;

        // can we partition into that, this is the problem

        sort( nums.begin(),nums.end();)
        vector<int> sides(4, 0);
        return dfs(nums, sides, 0, sum / 4);
    }

private:
    bool dfs(vector<int> &nums, vector<int> &sums, int index, int target)
    {
        if (index == nums.size())
        {
            if (sums[0] == target && sums[1] == target && sums[2] == target)
            {
                return true;
            }
            return false;
        }

        for (int i = 0; i < 4; i++)
        {
            if (sums[i] + nums[index] > target)
                continue;
            sums[i] += nums[index];
            if (dfs(nums, sums, index + 1, target))
                return true;
            sums[i] -= nums[index];
        }

        return false;
    }
};

// @lc code=end
