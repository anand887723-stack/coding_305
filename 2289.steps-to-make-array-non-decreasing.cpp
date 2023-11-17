/*
 * @lc app=leetcode id=2289 lang=cpp
 *
 * [2289] Steps to Make Array Non-decreasing
 */

// @lc code=start

#define deb(x) cout << #x << "= " << x << endl;
class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {

        // first of all make the decreasing sequences collpased
        // then find the next greater element and length of those segements and then
        // find the largest segment and that will be the answer
        int n = nums.size();
        vector<int> newarr;
        int shift = 0;
        newarr.push_back(nums[0]);
        int diff = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
                diff++;
            else
            {
                diff = 0;
            }
            if (diff >= 2)
                continue;
            else
                newarr.push_back(nums[i]);
        }
        vector<int> ng(newarr.size(), -1);

        int dec = 1;
        stack<int> st;
        
        // from right we need to see where is next greater element
        for (int i = newarr.size() - 1; i >= 0; i--)
        {

            // deb( nums[st.top()]);
            // deb( nums[i]);

            while (st.empty() == false && newarr[st.top()] < newarr[i])
            {

                // cout<<"here"<<endl;
                ng[st.top()] = i;
                st.pop();
            }
            st.push(i);

        }

        

        // for (int i = 0; i < newarr.size(); i++)
        //     cout << abs(i - ng[i]) << " ";
        // cout << endl;

        for (int i = 0; i < newarr.size(); i++)
            cout << newarr[i] << " ";
        cout << endl;


        for (int i = 1; i < newarr.size(); i++)
        {

            // deb(i)
            // we have to find the next greater position to the left
            if (ng[i] !=-1)
        
            {
                shift = max(shift, abs(i - ng[i]));
            }
        deb(i);deb(shift);
        }

        return shift;
    }
};
// @lc code=end
