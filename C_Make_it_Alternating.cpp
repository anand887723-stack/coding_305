
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

        string str;
        cin >> str;
        long long int mod = 998244353;
        long long int n = str.size();
        vector<long long int> streak;
        char last = str[0];
        long long int len = 1;
        for (long long int i = 1; i < n; i++)
        {

            if (str[i] == last)
            {
                len++;

                if (i == n - 1)
                {
                    if (len > 1)
                        streak.pb(len);
                }
            }
            else
            {
               
                if (len > 1)
                    streak.pb(len);
                len = 1;
                last = str[i];
            }

            // deb( len);
        }

        // printer

        // fo ( i  , streak.size())cout<<streak[i]<<" ";line_break
        // printer
        long long int ans = accumulate(all(streak), 0) - streak.size();
        long long int ans2 = 1;
        for (long long int i = 0; i < streak.size(); i++)
        {
            ans2 = ans2 * streak[i];
            ans2 %= mod;
        }

        cout << ans << " "
             << ans2 << endl;
    }
}