/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {

                // cout << i << " " << j << endl;
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
    
};
// @lc code=end

// these are square based questions to be precise in general a

