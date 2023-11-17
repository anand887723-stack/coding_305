#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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

    ll n;
    cin >> n;
    ll x;
    cin >> x;
    vll arr(n);
    fo(i, n) cin >> arr[i];
    unordered_map<ll, ll> mp;

    ll sum = 0;

    ll count = 0;
    fo(i, n)

    {

        sum += arr[i];
        if (sum == x)
            count++;
        if (mp.find(sum - x) != mp.end())
            count += mp[sum - x];

        mp[sum]++;
    }

    cout << count << endl;
}

