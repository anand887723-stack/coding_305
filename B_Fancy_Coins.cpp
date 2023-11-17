
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

        ll m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        // first check if it is zero or not

        if (m % k == 0)
        {

            ll temp = m - ak * k;

            if (m <= 0)
            {
                cout << "0" << endl;
                continue;
            }
            else
            {

                ll temp = m;
                temp -= ak * k;
                if (temp <= a1)
                {
                    cout << "0" << endl;
                    continue;
                }
                else
                {
                    temp -= (a1 / k) * k;
                    cout << temp / k << endl;
                    continue;
                }
            }
        }

        else
        {

            // first of all check for the zero case
            // so till the maxi of that to be precise
            ll temp = m;
            temp -= min((m / k), ak) * k;

            if (temp == 0)
            {

                cout << "0" << endl;
                continue;
            }

            else
            {

                ll temp = m;
                temp -= min((m / k), ak) * k;

                // now from here first check if it is possible to make zero from there
                if (temp <= a1)
                {
                    cout << "0" << endl;
                    continue;
                }

                else
                {

                    // so here i need to remove till that point where i do get into the range
                    ll diff = temp - a1;
                    if (temp < k)
                    {
                        cout << temp - a1 << endl;
                        continue;
                    }
                    else
                    {
                        // cout<<"ok"<<endl;

                        ll ans = 0;
                        ans += ceil(diff / (double)k);

                        temp -= ceil(diff / (double)k) * k;

                        if (temp < 0)
                        {
                            ans--;
                            temp += k;
                        }

                        temp = max(0LL, temp - a1);
                        if (temp == 0)

                        {
                            cout << ans << endl;
                        }

                        else
                        {

                            cout << ans + temp << endl;
                        }
                    }
                }
            }
        }
    }
}
