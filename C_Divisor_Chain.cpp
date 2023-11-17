
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

        int x;
        cin >> x;
        int xt = x;

        // find the keep on getting the set bits and keep on doing that till we get the one to be precsie

        // find the first set bit and find the last set bits

        vector<int> setbits, ans;
        for (int i = 0; i < 32; i++)
        {

            if (x & 1 << i)
                setbits.push_back(i);
        }

        // for (int i = 0; i < setbits.size(); i++)
        // {
        //     cout << setbits[i] << " ";
        // }
        // printer;

        int sz = setbits.size();
        int counter = 0;

        while (sz > 1)
        {
            ans.pb(x - pow(2, setbits[counter]));

            // deb(pow(2, setbits[counter]));

            x -= pow(2, setbits[counter]);

            // deb(x);
            counter++;
            sz--;
        }

        x = pow(2, setbits[setbits.size() - 1]);
        while (x > 1)
        {
            ans.pb(x / 2);
            x /= 2;
        }

        cout << ans.size() + 1 << endl;
        cout << xt << " ";

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }
}