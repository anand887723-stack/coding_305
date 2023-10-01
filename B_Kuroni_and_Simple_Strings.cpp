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

    string str;
    cin >> str;

    // where is the first ( and where  is the last )
    int firstopen = -1;
    int lastclose = -1;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            firstopen = i;
            break;
        }
    }
    int n = str.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ')')
        {
            lastclose = i;
            break;
        }
    }
    if (firstopen == -1 || lastclose == -1 || (firstopen > lastclose))
    {
        cout << 0 << endl;
        return 0;
    }

    bool skip = false;
    // if (firstopen > 0 || lastclose < n - 1)
    //     skip = true;

    // {

    //     while (firstopen < lastclose)
    //     {
    //     }
    // }

    // else
    vector<int> ans;

    while (firstopen < lastclose)
    {

        ans.push_back(firstopen);
        ans.push_back(lastclose);
        firstopen++;
        lastclose--;

        while (firstopen < lastclose && str[firstopen] != '(')
        {
            firstopen++;
        }

        while (lastclose > firstopen && str[lastclose] != ')')
        {

            lastclose--;
        }
    }

    // so here if that is equal to that size then hit othewise go

    if (ans.size() == str.size())
    {
        // then skip one of them and then go

        sort(ans.begin(), ans.end());
        if (ans.size())
            int n = ans.size();

       

        cout << 1 << endl;
        cout << n  << endl;

        Fo(i, 0, n ) cout << ans[i]+1 << " ";
        cout << endl;
    }

    else
    {

        sort(ans.begin(), ans.end());
        int n = ans.size();
        cout << 1 << endl;

        cout << n << endl;
        fo(i, n) cout << ans[i] +1<< " ";
        cout << endl;
    }
}



// feel what does do not mean , it means it can be or it can not be 
// this is not the necessarily need to be true