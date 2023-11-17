
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
        ll c, d;
        cin >> c >> d;
        vll arr(n);
        fo(i, n) cin >> arr[i];

        // find the duplicate elements and then sort them
        map<int, int> mp;
        fo(i, n)
            mp[arr[i]]++;
        long long int duplicate = 0;
        vi res;

        tr(i, mp)
        {

            duplicate += (i->second - 1) * c;

            res.push_back(i->first);
            // deb ( duplicate);
        }

        // deb(duplicate);

        long long int cost = 0;
        int nsz = res.size();
        long long int mina = LONG_LONG_MAX;

        // deb(duplicate)

            // deb(nsz);

        // deb( res[0]);
        mina = min(mina, (res[0] - 1) * d + (nsz - 1) * c + duplicate);

        // deb( mina);

        // deb(mina);

        for (int i = 1; i < nsz; i++)
        {
            mina = min(mina, (res[i] - i - 1) * d + (nsz - i - 1) * c + duplicate);
            // deb2(i, mina);
        }

        mina = min(mina, duplicate + nsz * c + d);

        cout << mina << endl;
    }
}