
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

        ll n, x;
        cin >> n >> x;
        vll ands(n);
        vll psum(n + 1, 0);

        fo(i, n)
        {
            cin >> ands[i];
            psum[i + 1] = psum[i] + ands[i];
        }

        if (x == 1)
        {
            cout << -1 << endl;

            continue;
        }

        // so i have to find the longest subarray whose sum is not divivsble by x

        ll ans = -1;
        ll left = 0;

        for (ll i = 0; i < n; i++)
        {

            if (psum[i + 1] % x != 0)
                ans = max(ans, i + 1);
        }

        // here we will move the left pointer

        // deb(ans);

        while (left < n)
        {

            if ((psum[n] - psum[left + 1]) % x != 0)
                ans = max(ans, n - left - 1);
            left++;
        }
        cout << ans << endl;
    }
}