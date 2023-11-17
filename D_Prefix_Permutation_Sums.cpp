
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

        // deb(t);

        long long int n;
        cin >> n;
        vector<long long int> arr(n - 1);
        unordered_set<long long int> nums;
        fo(i, n) nums.insert(i + 1);

        fo(i, n - 1) cin >> arr[i];
        long long int notfound;
        for (int i = 0; i < n - 1; i++)
        {

            // deb(i);
            if (i == 0)
            {
                if (nums.find(arr[i]) == nums.end())
                {
                    notfound = arr[i];
                }
                else
                    nums.erase(arr[0]);
            }

            else
            {
                if (nums.find(arr[i] - arr[i - 1]) == nums.end())
                {

                    notfound = arr[i ] - arr[i-1];
                }

                else
                {
                    nums.erase(arr[i] - arr[i - 1]);
                }
            }

            // deb(i);
        }
        if (nums.size() == 1)
        {
            // printer;
            cout << "YES" << endl;

           
            continue;
        }


    if ( nums.size()>2){

            cout << "NO" << endl;

            continue;
    }
        // deb(notfound);

        auto it = nums.begin();
        long long int summer = *it;
        it++;
        summer += *it;
        if (summer == notfound)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;

        // if htat
    }
}



// there are lot of reasons for this to be easy , there solid test cases are given , and also the logic itself is super easy 