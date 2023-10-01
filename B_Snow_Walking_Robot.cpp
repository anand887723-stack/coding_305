
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

        // so first of all calculate the total of left and right, first of all equate them and then maximise them
        // then calculat the up and down , first of all equate them and then maximise the,
        int left = count(all(str), 'L');
        int right = count(all(str), 'R');
        int up = count(all(str), 'U');
        int down = count(all(str), 'D');
        // first find the min of right and left
        // then find the min of up and down
        // then find the min of all those

        int hori = min(left, right);
        int veri = min(up, down);
        if (hori == 0 && veri == 0)

        {
            cout << 0 << endl;
            line_break
            ; continue;
        }

        if (hori == 0)
        {

            cout << 2 << endl;

            cout << "UD" << endl;

            continue;
        }

        if (veri == 0)
        {

            cout << 2 << endl;

            cout << "RL" << endl;

            continue;
        }

        cout << hori * 2 + veri * 2 << endl;
        for (int i = 0; i < veri; i++)
        {

            cout << "U";
        }

        for (int i = 0; i < hori; i++)
        {
            cout << "R";
        }
        for (int i = 0; i < veri; i++)
        {
            cout << "D";
        }

        for (int i = 0; i < hori; i++)
        {
            cout << "L";
        }
        line_break
    }
}