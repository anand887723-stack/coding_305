/*
 * @lc app=leetcode id=2856 lang=cpp
 *
 * [2856] Minimum Array Length After Pair Removals
 */

// @lc code=start
class Solution
{
public:
    int minLengthAfterRemovals(vector<int> &nums)
    {

        // we just need to see that to be precise in general as per the overall structure of
        // the game to be precise and also the real game changer as per the scenes have changed to
        // be precise if it is less than the
        unordered_map<int, int> counter;
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {

            counter[nums[i]]++;
            maxi = max(maxi, counter[nums[i]]);
        }

        if (n % 2 == 0)

        {

            if (maxi <= n / 2)
            {
                return 0;
            }

            else
            {
                int left = n - maxi;
                return n-2 * left;
            }
        }

        else
        {

            if (maxi <= n / 2)
            {
                return 1;
            }

            else
            {
                int left = n - maxi;
                return  n- 2 * left;
            }
        }
    }
};
// @lc code=end
