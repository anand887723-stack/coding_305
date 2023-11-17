
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
#include <cfloat>
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

double dist(double x1, double x2, double y1, double y2)

{
    double ans = 0;
    ans += pow(x2 - x1, 2);
    ans += pow(y2 - y1, 2);
    ans = sqrt(ans);

    return ans;
}
int main()
{
    fastio();
    ll t;
    cin >> t;
    double e = 0.0000001;
    while (t--)
    {

        double w, h, x1, x2, y1, y2, sw, sh;
        cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> sw >> sh;
        double ans = DBL_MAX;
        // deb2(sw, x2 - x1);
        // deb2(sh, );
        // deb(h);
        // deb(w);
        double tw = w - (x2 - x1);
        double th = h - (y2 - y1);
        // deb2(sw, sh);
        // deb2(tw, th);

        if (sw - tw > e && sh - th > e)
        {
            // printer
            cout << -1 << endl;
            continue;
        }

        vector<vector<double>> corner = {{sw, sh, x1, y1},
                                         {w - sw, sh, x2, y1},
                                         {sw, h - sh, x1, y2},
                                         {w - sw, h - sh, x2, y2}};

        for (int i = 0; i < 4; i++)
        {
            if (i < 2)
            // TWO NICHE WALA
            {

                if (corner[i][0] > corner[i][2] && corner[i][1] > corner[i][3])
                {
                    double temp = dist(corner[i][0], corner[i][1], corner[i][2], corner[i][3]);

                    if (ans - temp > e)
                        ans = temp;
                }
                else
                {
                    ans = 0.0;
                    break;
                }
            }

            else
            {

                if (corner[i][0] < corner[i][2] && corner[i][1] < corner[i][3])
                {
                    double temp = dist(corner[i][0], corner[i][1], corner[i][2], corner[i][3]);

                    if (ans - temp > e)
                        ans = temp;
                }
                else
                {
                    ans = 0;
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}