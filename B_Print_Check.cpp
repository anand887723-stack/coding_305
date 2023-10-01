
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

    long long  row, col, k;
    cin >> row >> col >> k;
    vector<vector<long long >> op(k, vector<long long >(3, 0));
    vector<vector<long long>> matrix(row, vector<long long >(col, 0));
    fo ( i , k)
    {
        fo ( j,3)
            cin>> op[i][j];
    }
    set<long long > validrows;
    set<long long > validcols;
    fo(i, row) validrows.insert(i);
    fo(i, col) validcols.insert(i);
    // start from the back and keep on going above
    for (long long  i = op.size() - 1; i >= 0; i--)
    {

        if (op[i][0] == 1)
        {
            if (validrows.find(op[i][1]-1) == validrows.end())
                continue;
            validrows.erase(op[i][1]-1);
            // now colour that row in all the cols which are valid

         
            for (auto k : validcols)
            {
                matrix[op[i][1]-1][k] = op[i][2];
            }
        }
        else
        {
            if (validcols.find(op[i][1]-1) == validcols.end())
                continue;

            validcols.erase(op[i][1]-1);
           

            // now colour that row in all the cols which are valid
            for (auto k : validrows)
            {
                matrix[k][op[i][1]-1] = op[i][2];
            }
        }
    }

    fo(i, row)
    {
        fo(j, col) cout << matrix[i][j] << " ";
        line_break
    }
}