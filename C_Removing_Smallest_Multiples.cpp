
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
int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        string ands;
        cin >> ands;
        vector<ll> nums(n + 1, 1);
        int count = n;
        for (int i = 0; i < n; i++)
        {
            if (ands[i] == '1')
            {
                nums[i + 1] = 0;
                count--;
            }
        }
        long long int ans = 0;

        for (int i = 1; i <= n; i++)
        {

            long long int t = i;
            // bool start = false;
            while (t <= n)
            {
                if (nums[t] == 0)
                    break;
                else
                {
                    if (nums[t] != 2)
                    {
                        nums[t] = 2;
                        ans += i;
                    }
                }

                t += i;
            }

            // cout << "---" << endl;

            if (count <= 0)
                break;

            // find first and then  check the continuity
        }

        cout << ans << endl;
    }
}