/*
 * @lc app=leetcode id=2860 lang=cpp
 *
 * [2860] Happy Students
 */

// @lc code=start
class Solution
{
public:
    int countWays(vector<int> &nums)
    {

        // kind of intersection of intervals
        int n = nums.size();

        vector<int> numbers(n + 1, true); // total number of students that i can select

        for (int i = 0; i < n; i++)
        {
            numbers[nums[i]] = false;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n; i++)

        {

            if (numbers[i])
            {
                // cout << i << endl;

                // now check the lower bound of
                if (i == 0)
                    continue;

                else
                {
                    int leftcount = upper_bound(nums.begin(), nums.end(), i - 1) - nums.begin();

                    cout << leftcount << endl;

                    if (leftcount == i)
                        continue;
                    else
                        numbers[i] = false;
                }
            }
        }

        int counter = 0;

        for (int i = 0; i <= n; i++)
            if (numbers[i])
                counter++;
        return counter;
    }


    // NOTE : THE FIRST REALISATION IS BY LOOKING AT THE CONSTRAINTS. 
    // WE NEED TO CONVIENCE THAT NUMBER OF WAYS WILL BE IN BETWEEEN THE 0 AND NUMS.SIZE()
    // AND WE WILL CHECK THAT HOW MANY STUDENTS CAN BE SELECTED AND HOW MANY STUDENTS
    // IS THERE ANY CHANCE THAT THAT MANY STUDENTS ARE SLECTABLAE AND OR NOT , OBVIOSLY KEEPING 
    // THE CONDITION THAT OTHER STUDENTS ARE HAPPY AS WELL WHICH IS OBVOIUS
};
// @lc code=end


// note
// wow man i took time but i did it eventually to be precise i am telling you in gner