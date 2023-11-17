/*
 * @lc app=leetcode id=1594 lang=cpp
 *
 * [1594] Maximum Non Negative Product in a Matrix
 */

// @lc code=start
class Solution
{
public:
    int mod;
    pair<int, int> rec(int row, int col, vector<vector<int>> &grid, vector<vector<pair<int, int>>> &dp)
    {

        // so in that case , what I should pass ? or  I should not go there that would be a hell better
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return {grid[row][col], grid[row][col]};
        // righ
        if (dp[row][col].first != 1e9 && dp[row][col].second != -1e9)
            return dp[row][col];
        vector<int> ans;
        if (col + 1 != grid[0].size())
        {

            pair<int, int> temp = rec(row, col + 1, grid, dp);

            ans.push_back((grid[row][col] * temp.first) % mod);
            ans.push_back((grid[row][col] * temp.second) % mod);
        }

        // down
        if ( row+1!=grid.size())
        {
            pair<int, int> temp = rec(row + 1, col, grid, dp);

            ans.push_back((grid[row][col] * temp.first) % mod);
            ans.push_back((grid[row][col] * temp.second) % mod);

            
        }

        pair<int, int> finals;
        // i will pick the most postive and the most negative 
        sort ( ans.begin(),ans.end());

       if ( ans[ans.size()-1]<0)
       {
            return dp[row][col] = {ans[0],
                                   ans[0]};

       }
       else if ( ans[ans[0]]>=0)
       {
            return dp[row][col] = {
                       ans[ans.size() - 1], ans[ans.size() - 1]};
       }
       else 
       {
            return dp[row][col] = {
                       ans[0], ans[ans.size() - 1]};

       }
      
        return dp[row][col]=finals;
    }
    int maxProductPath(vector<vector<int>> &grid)
    {

        // this is clear cut grid dp
        mod = 1e9 + 7;
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<pair<int, int>>> dp(row, vector<pair<int, int>>(col, {1e9, -1e9}));

        if (max(rec(0, 0, grid, dp).first, rec(0, 0, grid, dp).second) < 0)
            return -1;

        else
            return max(rec(0, 0, grid, dp).first, rec(0, 0, grid, dp).second);
    }
};
// @lc code=end
