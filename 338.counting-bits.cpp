/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    // int finder( int n)
    // {
    //     int one =0 ;
    //     while ( n>0)
    //     {
    //         one += ( n%2);
    //         n/=2;
    //     }

    //     return one;
    // }
    vector<int> countBits(int n)
    {

        if (n == 0)
            return {0};
        else if (n == 1)
            return {0, 1};
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        // oh wow this is dp bro 
     

        for (int i = 2; i <= n; i *= 2)
        {

            int j = i;
            int counter = 0;
            while ((j <= n) && counter < i)
            {

                ans.push_back(1 + ans[counter]);
                counter++;
                j++;
            }
        }

        return ans;
    }
};
// @lc code=end

