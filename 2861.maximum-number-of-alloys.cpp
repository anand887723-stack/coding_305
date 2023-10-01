/*
 * @lc app=leetcode id=2861 lang=cpp
 *
 * [2861] Maximum Number of Alloys
 */

// @lc code=start
class Solution
{
public:
    bool valid(long long int reqd, int budget, vector<vector<int>> &comp, vector<int> &stock, vector<int> &cost)
    {
        // so what is the overall required cost to be precise in general sense
        // as per the overall structure has been concerned to be precise looking at the scenes in general
        // now let us start checking for each of the machines
        long long int machines = comp.size();
        long long int metals = cost.size();

        // cout << reqd << endl;

        for (int i = 0; i < machines; i++)
        {
            long long int reqdcost = 0;

            for (int j = 0; j < metals; j++)
            {
                long long int reqd2 = reqd * comp[i][j] - stock[j];
                if (reqd2 <= 0)
                    continue;

                reqdcost += reqd2 * (long long int)cost[j];
            }
// you need to see the question by heart ot bep recise 
            // cout << endl;

            if (reqdcost <= budget)
            {

                return true;
            }
        }

        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &comp, vector<int> &stock, vector<int> &cost)
    {

        long long int low = 0;
        long long int high = 1e9;

        long long int ans = 0;
        while (high >= low)
        {

            long long int mid = low + (high - low) / 2;

            if (valid(mid, budget, comp, stock, cost))
            {
                ans = mid;
                low = mid + 1;
            }

            else
            {

                high = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end
