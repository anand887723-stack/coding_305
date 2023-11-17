
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
using namespace std;
int main()
{
    int d;
    int h;
    cin >> h;
    vector<long long int> heros(h);
    vector<pair<long long int, long long int>> dra(d);
    long long int summer = 0;

    for (int i = 0; i < h; i++)
    {
        cin >> heros[i];
        summer += heros[i];
    }

    sort(heros.begin(), heros.end());
// 2 3 3 6
    cin >> d;
    for (int i = 0; i < d; i++)
        cin >> dra[i].first >> dra[i].second; // def ,att

    // cout << 2 << endl;
    // return 0;
    for (int i = 0; i < d; i++)
    {
        // find close to def
        auto close = lower_bound(heros.begin(), heros.end(), dra[i].first) - heros.begin();
        // cout << 2 << endl;

        if ( close<h)deb(heros[close]);
        if (close < heros.size() && heros[close] == dra[i].first)
        {

            cout << min(0LL, -summer + heros[close] + dra[i].second) << endl;
            continue;
        }
        if (close == 0)
        {n

            long long int ans = 0;
            if (heros[close] < dra[i].first)
                ans += abs(heros[close] - dra[i].first);
            long long int rem = summer - heros[close];
            if (rem < dra[i].second)
                ans += abs(rem - dra[i].second);

            cout << ans << endl;
        }
        else if (close == heros.size())
        {
            long long int ans = 0;
            if (heros[close - 1] < dra[i].first)
                ans += abs(heros[close - 1] - dra[i].first);
            long long int rem = summer - heros[close - 1];
            if (rem < dra[i].second)
                ans += abs(rem - dra[i].second);

            cout << ans << endl;
        }
        else
        {
            long long int ans = INT_MAX;

            long long int tempans = 0;

            tempans += min(0LL, dra[i].first - heros[close]);
            long long int rem = summer - heros[close];
            tempans += abs(rem - dra[i].second);

            ans = min(tempans, ans);

            tempans = 0;
            tempans += min(0LL, dra[i].first - heros[close - 1]);
            rem = summer - heros[close - 1];
            tempans += abs(rem - dra[i].second);

            // write the code here
            ans = min(ans, tempans);

            cout << ans << endl;
        }
    }
}
