
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

        long long int n, k;
        cin >> n >> k;
        vll arr(n);
        fo(i, n) cin >> arr[i];

        // deb(k);
        if (k == 2 || k == 3 || k == 5)
        {
            long long int dis = LONG_LONG_MAX;
            fo(i, n)
            {
                if (arr[i] % k == 0)
                {

                    dis = 0;
                    // deb(dis);
                    break;
                }
                dis = min(k - arr[i] % k, dis);

                // deb2(arr[i], arr[i] % k);
                // deb(dis);
            }
            cout << dis << endl;
        }
        else
        {

            long long int div2 = 0;

            long long int dis = LONG_LONG_MAX;
            fo(i, n)
            {
                if (arr[i] % 2 == 0)
                    div2++;

                if (div2 >= 2)
                {
                    dis = 0;
                    // deb(dis);
                    break;
                }

                if (arr[i] % 4 == 0)
                {

                    dis = 0;
                    // deb(dis);
                    break;
                }
                dis = min(k - arr[i] % k, dis);
            }

            if (div2 == 0)
            {
                dis=(min(dis,(ll) 2));
            }
            else if (div2 == 1)
            {
                dis = min(dis, (ll)1);
            }
            cout << dis << endl;
        }
    }
}