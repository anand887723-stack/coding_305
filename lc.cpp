
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <limits.h>
#include <algorithm>
#include <random>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <map>
#include <unordered_map>
#include <set>
#include <iterator>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <cstdint>
#include <iomanip>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// constants
#define MOD 1000000007
#define INF 1e18
#define PI 3.1415926535897932384626
// stl functions
#define pb push_back
#define line_break cout << endl;
#define printer cout << 111111111 << endl;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
// debug
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// iterators
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)

class Solution
{
public:
    long long int rec(vector<int> &nums, long long int k, int index, vector<long long int> &dp)
    {

        if (index >= nums.size() - 2)
            return 0LL;
        if (dp[index] != -1)
            return dp[index];
        long long int maxval =0;
        int maxpos;
        int n = nums.size();

        for (int j = index; j <= min(index + 2, n - 1); j++)
        {
            if (maxval <= nums[j])
            {
                maxval = nums[j];
                maxpos = j;
            }
        }
        if (maxval >= k)
            return dp[index] = rec(nums, k, maxpos + 1, dp);
        long long int ans = INT_MAX;

        for (int j = index; j <= min(index + 2, n - 1); j++)

            ans = min(ans, k - (long long int ) nums[j] + rec(nums, k, j + 1, dp));

        deb2(index, ans);

        return dp[index] = ans;
    }
    long long minIncrementOperations(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<long long int> dp(nums.size() + 1, -1);

        return rec(nums,( long long int ) k, 0, dp);
    }
};

int main()
{
    Solution sol;
    vi input = {7, 7, 2, 7};

    cout << sol.minIncrementOperations(input, 9);
}

// 7 2 7 7 , k = 9
