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
        vll arr(n);
        fo(i, n) cin >> arr[i];
        ll ans = 0;
        ll ones = 0, zeros = 0;
        set<ll> one, zero;

        for (ll i = 0; i < n; i++)
        {
            arr[i] %= 2;
            if (arr[i])
            {
                ones++;
                one.insert(i);
            }
            else
            {
                zeros++;
                zero.insert(i);
            }
        }

        vector<int> newarr;

        if (abs(ones - zeros) > 1)
        {

            // printer;
            cout << -1 << endl;
            continue;
        }
        else if (ones == zeros)

        {
            bool first = arr[0];

            for (int i = 0; i < n; i++)
            {
                newarr.pb(first);
                first = !first;
            }
        }

        else
        {

            if (ones > zeros)
            {
                bool first = 1;

                for (int i = 0; i < n; i++)
                {
                    newarr.pb(first);
                    first = !first;
                }
            }
            else
            {
                bool first = 0;

                for (int i = 0; i < n; i++)
                {
                    newarr.pb(first);
                    first = !first;
                }
            }
        }

        for (ll i = 0; i < n - 1; i++)
        {
            if (arr[i] != newarr[i])
            {
                if (arr[i + 1] == 1)

                    auto pos = *ones.upper_bound(i + 1);
                swap(arr[i + 1], arr[pos]);

                // deb( pos);
                ans += pos - (i + 1);

                // deb(ans);

                // cout << "first" << endl;
                deb(i);
                deb(pos);
                // deb(ans);
                // for (int i = 0; i < n; i++)
                //     cout << arr[i] << " ";
                // cout << endl
                //      << "---" << endl;
                ones.erase(pos);
                zeros.insert(pos);
            }

            else
            {
                if (arr[i + 1] == 0)
                    continue;
                else
                {
                    auto pos = *zeros.upper_bound(i + 1);
                    swap(arr[i + 1], arr[pos]);
                    ans += pos - (i + 1);

                    // cout << "second" << endl;
                    deb(i);
                    deb(pos);
                    // deb(ans);
                    // for (int i = 0; i < n; i++)
                    //     cout << arr[i] << " ";
                    // cout << endl
                    //      << "---" << endl;
                    zeros.erase(pos);
                    ones.insert(pos);
                }
            }

            // deb ( ans);
        }

        cout << ans << endl;
    }
}