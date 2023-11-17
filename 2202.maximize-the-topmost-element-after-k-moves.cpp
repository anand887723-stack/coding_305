/*
 * @lc app=leetcode id=2202 lang=cpp
 *
 * [2202] Maximize the Topmost Element After K Moves
 */

// @lc code=start


#define deb(x) cout << #x << "=" << x << endl;

class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {

        if (k == 0)
            return nums[0];

        int n = nums.size();
        if (n == 1)
        {
            if (k % 2 == 1)
                return -1;
            else
                return nums[0];
        }

        auto maxpos = max_element(nums.begin(), nums.end());
        int temp = maxpos - nums.begin();

        deb( temp);
        int reqdrem = temp ;

        deb( k );deb( reqdrem);
        if (k == reqdrem || k >= reqdrem + 2)
            return *maxpos;
        else
        {

            // cout<<"here"<<endl;
            int maxi = nums[k];
            auto maxpos = max_element(nums.begin(), nums.begin() + k - 1);// see here if the k is 1 then it will
            // be giving the undefined behavior
            
            maxi = max(maxi, *maxpos);
            return maxi;
        }
    }
};
// @lc code=end
