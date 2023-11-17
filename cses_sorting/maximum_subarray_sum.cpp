
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
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        // you need to find the state, which is index itselfx
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {

            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }

        int maxi = *max_element(dp.begin(), dp.end()); // return the max dp from here

        return maxi;

        // or we can go using the kadane algorithm
    }
};
int main()

{

    ll n;
    cin >> n;
    vector<ll> arr(n);
    fo(i, n) cin >> arr[i];
    ll sum = 0;
    ll ans = INT_MIN;
    fo(i, n)

    {
        sum += arr[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }

    cout << ans << endl;
}