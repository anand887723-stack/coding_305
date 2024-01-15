class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int in, int val)
    {

        // make a max  suffix array
        int n = nums.size();
        vector<pair<int, int>> maxi(n), mini(n);
        maxi[n - 1] = {nums[n - 1], n - 1};
        mini[n - 1] = {nums[n - 1], n - 1};

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > maxi[i + 1].first)
                maxi[i] = {nums[i], i};
            else
                maxi[i] = maxi[i + 1];
            if (nums[i] < mini[i + 1].first)
                mini[i] = {nums[i], i};
            else
                mini[i] = mini[i + 1];
        }

        pair<int, int> ans = {-1, -1};

        for (int i = 0; i < n - in; i++)
        {
            if (abs(nums[i] - maxi[i + in].first) >= val)
            {
                ans = {i, maxi[i + in].second};
                vector<int> finals;
                finals = {ans.first, ans.second};
                return finals;
            }

            if (abs(nums[i] - mini[i + in].first) >= val)
            {
                ans = {i, mini[i + in].second};
                vector<int> finals;
                finals = {ans.first, ans.second};
                return finals;
            }
        }

        return {-1, -1};
    }
};