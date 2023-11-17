
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

        long long int summer = 0;
        bool pos = false;

        fo(i, n)
        {
            cin >> arr[i];
            if (arr[i] >= 0)
            {
                pos = true;
            }
        }

        if (pos == false)
        {
            cout << *max_element(all(arr)) << endl;
        }

        else
        {
            long long int odd = 0;
            long long int even = 0;

            for (int i = 0; i < n; i++)
                i % 2 == 0 ? arr[i] >= 0 ?even += arr[i] : even += 0: arr[i]>=0? odd+=arr[i]:odd+=0;
                    cout << max(even, odd) << endl;
        }
    }
}

// what is the things that I have missed here bro , I think I missed the pattern that after one removal what are the other removals
// that i can have
// I was just not looking at the case that how will array going to look like after 2 removeals and is there any kind of trend or not