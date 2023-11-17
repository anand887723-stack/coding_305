/*
 * @lc app=leetcode id=2780 lang=cpp
 *
 * [2780] Minimum Index of a Valid Split
 */

// @lc code=start
class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> total, first;
        int maxi = 0;
        int n = nums.size();
        int element = -1;
        for (int i = 0; i < n; i++)
        {
            total[nums[i]]++;
            if (total[nums[i]] > maxi)
            {
                maxi = total[nums[i]];
                element = nums[i];
            }
        }

        if (maxi * 2 <= n)
            return -1;
        int firstmaxi = 0;
        int firstelement;

        for (int i = 0; i < n - 1; i++)
        {
            first[nums[i]]++;
            if (first[nums[i]] >= firstmaxi)
            {
                firstelement = nums[i];
                firstmaxi = first[nums[i]];
            }
            int secondmaxi = total[firstelement] - firstmaxi;

            if (firstelement == element && firstmaxi * 2 > (i + 1) && secondmaxi * 2 > (n - i - 1))
                return i;
        }

        return -1;
    }
};
// @lc code=end
