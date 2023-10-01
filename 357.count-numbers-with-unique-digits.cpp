/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution
{
public:
    long long int finder(int digits)

    {

        long long int ans = 9;

        digits--;
        int counter = 9;
        while (digits--)
        {

            ans *= counter;
            counter--;
        }

        return ans;
    }

    int countNumbersWithUniqueDigits(int n)
    {

        // how to go through the dp in general here i do not know bro to be precise in general as the scenes have been
        // concerened to be precise
        // what is the overall count of the game in the general sense which is again one
        // of the most integrating part of the game in the real sense to be precise overall
        // the structure of the game is not in that sense which are also the real game changer
        vector<long long int> ans(9);
        if (n == 0)
            return 1;
        ans[1] = 10;

        ans[2] = 81;
        for (int i = 3; i <= n; i++)
        {
            ans[i] = ans[i - 1] * (10 - i + 1);
        }

        // so just bolne ka dp in fact this is just partial dp calculation and then summing at the end  
        long long int temp=0;
        for( int i =1 ; i <=n;i++)temp+=ans[i];

        return temp;
    }
};
// @lc code=end

// oh in that sense we can say we can right down the iterative dp