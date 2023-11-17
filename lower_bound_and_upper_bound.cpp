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

int lb(vi &arr, int x)
{

    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (high >= low)
    {

        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            return arr[mid];
    }

    return ans;
}

int ub(vi &arr, int x)
{

    int low = 0;
    int high = arr.size() - 1;

    int ans = -1;
    while (high >= low)
    {

        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
            low = mid + 1;
        else
        {
            ans = arr[mid];
            high = mid - 1;
        }
    }

    return ans;
}
int main()
{

    vector<int> arr = {1, 4, 4, 6, 7, 9, 12, 15};
    fo(i, arr.size()) cout << arr[i] << " ";
    cout << endl;

    fo(i, 20)
    {

        // deb2(i, lb(arr, i));
        deb2(i, ub(arr, i));
    }
}
