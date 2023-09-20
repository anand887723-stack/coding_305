
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

void finder(int edge, vll &ands, vll &ans)
{
    ll n = ands.size();

    // first we need to find the position
    int pos = upper_bound(ands.begin(), ands.end(), edge) - ands.begin();
    ans.push_back(ands[pos - 1]);

    for (int i = pos; i < n; i++)
        ans.push_back(ands[i]);

    for (int i = 0; i <= pos - 3; i++)
        ans.push_back(ands[i]);

    ans.push_back(ands[pos - 2]);
}
int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        vll ands(n);
        unordered_map<ll, ll> counter;
        fo(i, n)
        {
            cin >> ands[i];
            counter[ands[i]]++;
        }
        sort(all(ands));
        vll ans;

        bool flag = true;
        tr(i, counter)
        {
            if (i->second >= 2)
            {

                finder(i->first, ands, ans);

                fo(i, n) cout << ans[i] << " ";
                line_break;

                flag = false;
                break;
            }
        }

        if (flag)
        {

            // find mina
            ll mina = INT_MAX;
            ll pos;

            for (int i = 1; i < n; i++)
            {
                if (ands[i] - ands[i - 1] <= mina)
                {

                    pos = i;
                    mina = ands[i] - ands[i - 1];
                }
            }

            // deb(pos);

            // now check the pos
            ans.push_back(ands[pos - 1]);
            for (int i = pos + 1; i < n; i++)
                ans.push_back(ands[i]);
            for (int i = 0; i < pos - 1; i++)
                ans.push_back(ands[i]);

            ans.push_back(ands[pos]);

            fo(i, n) cout << ans[i] << " ";
            line_break;
        }
    }
}