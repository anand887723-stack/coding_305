/*
 * @lc app=leetcode id=2857 lang=cpp
 *
 * [2857] Count Pairs of Points With Distance k
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

class Solution
{
public:
    int countPairs(vector<vector<int>> &coordinates, int k)
    {
      int n = coordinates.size();

        map<pair<int, int>, int> count;

        for ( int i =0;i<n;i++)
        {
            count[{coordinates[i][0], coordinates[i][1]}]++;
        }
        long long int ans = 0;
        for (int first = 0; first <= k; first++)
        {
            int second = k - first;

            cout << first << " " << second << endl;

            for (int i = 0; i < n; i++)

            {
                int x1 = coordinates[i][0];
                int y1 = coordinates[i][1];
                count[{x1, y1}]--;
                int x2 = x1 ^ first;
                int y2 = y1 ^ second;

             
                // deb2(first, second);

                if (count.find({x2, y2}) != count.end())
                {
                    deb2(x2, y2);
                deb2(x1, y1);

                int counter =count[{x2, y2}];

                deb( counter);

                    // cout << "ok" << endl;
                    ans += (1 * counter);
                }

                count[{x1, y1}]++;

                // cout << "***"<<endl;
            }
            cout << "----" << endl;
        }

        return ans / 4;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> input = {{1, 2}, {4, 2}, {1, 3}, {5, 2}};
   cout<< sol.countPairs(input, 5);
}