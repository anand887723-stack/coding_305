// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<vi> vvi;
// typedef vector<vll> vvll;

// #define fastio()                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// // constants
// #define MOD 1000000007
// #define INF 1e18
// #define PI 3.1415926535897932384626

// // stl functions
// #define pb push_back
// #define fi first
// #define se second
// #define all(x) (x).begin(), (x).end()

// #define set_bits __builtin_popcountll

// // debug
// #define deb(x) cout << #x << "=" << x << endl;
// #define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// // iterators
// #define fo(i, n) for (ll i = 0; i < n; i++)
// #define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
// #define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)

// int main()
// {

//     ll n, p;
//     cin >> n >> p;
//     string str;
//     cin >> str;

//     int tocomp = n % p == 0 ? p : n % p;
//     int rows = n % p == 0 ? n / p : n / p + 1;
//     if (n <= p)
//     {

//         fo(i, n) if (str[i] == '.') str[i] = '1';
//         cout << str << endl;
//         return 0;
//     }

//     bool end = false;
//     int count = 0;
//     vector<vector<char>> matrix(p, vector<char>(rows, '.'));
//     // now i need to go through the thorow thing
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < p; j++)
//         {

//             if (end)
//                 break;
//             matrix[i][j] = str[count];
//             count++;
//             if (count == n)
//                 end = true;
//         }
//         if (end)
//             break;
//     }

//     // count = 0;
//     // end = false;
//     // how many cols to check
//     int temp;

//     bool done = false;
//     if (n % p == 0)
//         temp = p;
//     else
//         temp = n % p;
//     for (int i = 0; i < temp; i++)
//     {

//         string temp = "";

//         for (int j = 0; j < rows; j++)
//         {

//             if (done)
//                 break;
//             temp += matrix[j][i];
//         }
//         int dots = count(all(temp), '.');
//         if (dots >= 2)
//         {
//             // find those and put 0 and 1 and put done = true
//             // int dot1 = temp.find ( '.');

//             int first;
//             for (int j = 0; j < rows; j++)
//             {

//                 if (matrix[j][i] == '.')
//                 {
//                     matrix[j][i] = '1';
//                     first = i;
//                     break;
//                 }
//             }
//             for (int j = first + 1; j < rows; j++)
//             {

//                 if (matrix[j][i] == '.')
//                 {
//                     matrix[j][i] = '0';
//                     first = i;
//                     break;
//                 }
//             }

//             done = true;
//         }
//         else if (dots == 1)
//         {

//             int one = count(temp.begin(), temp.end(), '1');
//             int zero = count(temp.begin(), temp.end(), '0');
//             char toput = one >= zero ? '0' : '0';

//             for (int j = 0; j < rows; j++)
//             {

//                 if (matrix[j][i] == '.')
//                 {
//                     matrix[j][i] = toput;

//                     break;
//                 }
//             }

//             done = true;
//         }

//         else
//         {
//             // check if already alag , if not then continue

//             int one = count(temp.begin(), temp.end(), '1');
//             int zero = count(temp.begin(), temp.end(), '0');
//             if (one == temp.size())
//             {
//                 continue;
//             }
//             else if (zero == temp.size())
//             {
//                 continue;
//             }
//             else
//             {
//                 done = true;
//                 break;
//             }
//         }

//         if (done)
//         {

//             break;
//         }
//     }

//     // now we have to see that done has been done or ot
//     if (!done)
//         cout << "No" << endl;
//     else
//     {
//         bool end = false;

//         for (int i = 0; i < rows; i++)
//         {
//             for (int j = 0; j < p; j++)
//             {

//                 if (end)
//                     break;
//                 if (matrix[i][j] == '.')
//                     cout << "1";
//                 else
//                     cout << matrix[i][j];
//                 count++;
//                 if (count == n)
//                     end = true;
//             }
//             if (end)
//                 break;
//         }
//     }
// }

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

    int n, p;
    string str;
    cin >> n >> p;
    cin >> str;
    if (n == p)
    {
        fo(i, n) str[i] == '.' ? cout << '1' : cout << str[i];
        line_break;
        return 0;
    }

    // now let us start doing that
    int intervals = n % p == 0 ? n / p : n / p + 1;
    int len = n % p == 0 ? p : n % p;

    bool valid = false;

    for (int i = 0; i < len; i++)

    {

        vector<int> temp;
        int ones = 0;
        int zeros = 0;
        for (int j = 0; j < intervals; j++)
        {
            if (str[i + j * p] == '.')
                temp.push_back(i + j * p);
            else if (str[i + j * p] == '1')
                ones++;
            else

                zeros++;
        }

        if (temp.size() >= 2)
        {

            str[temp[0]] = '1';
            str[temp[1]] = '0';
            valid = true;
            break;
        }
        else if (temp.size() == 1)
        {

            if (ones == intervals - 1)
            {

                str[temp[0]] = '0';
            }
            else if (zeros == intervals - 1)
            {
                str[temp[0]] = '1';
            }

            else
            {
                ;
            }

            valid = true;
            break;
        }
        else

        {

            if (ones == intervals)
            {

                ;
            }
            else if (zeros == intervals)
            {
                ;
            }

            else
            {
                valid = true;
                break;
            }
        }
    }
    if (valid == false)
        cout << "No" << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '.')
                cout << '1';
            else
                cout << str[i];
        }
        line_break;
    }
}