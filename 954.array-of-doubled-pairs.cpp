/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start

// # define deb (x) cout<< #x <<" = "<<x<<endl
#define deb(x) cout << #x << "=" << x << endl;

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {

        int totalpair = 0;
        int n = arr.size();
        unordered_map<int, int> count;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {

                if (count[arr[i]] >= 2)
                {
                    count[arr[i]] -= 2;
                    if (count[arr[i]] == 0)
                        count.erase(arr[i]);
                    totalpair++;
                }

                // deb(i);
                // deb(totalpair);
                continue;
            }

            if (count.find ( arr[i])!=count.end()&&count.find(arr[i] * 2) != count.end())
            {
                totalpair++;
                count[arr[i]]--;
                count[2 * arr[i]]--;
                if (count[arr[i]] == 0)
                    count.erase(arr[i]);
                if (count[2 * arr[i]] == 0)
                    count.erase(2 * arr[i]);
            }

            // deb ( i) ; deb( totalpair);
        }

        // cout << totalpair << endl;

        return totalpair == arr.size() / 2;
    }
};
// @lc code=end
