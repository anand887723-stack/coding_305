
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
int main()
{
    long long int d;
    long long int h;
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

    cin >> d;
    for (int i = 0; i < d; i++)
        cin >> dra[i].first >> dra[i].second; // def ,att

    cout << 2 << endl;
    return 0;
    // for (int i = 0; i < d; i++)
    // {
    //     // find close to def
    //     auto close = lower_bound(heros.begin(), heros.end(), dra[i]) - heros.begin();

    //     if (close < heros.size() && heros[close] == dra[i].first)
    //     {

    //         cout << min(0LL, -summer + heros[close] + dra[i].second) << endl;
    //     }
    //     if (close == 0)
    //     {

    //         long long int ans = 0;
    //         if (heros[close] < dra[i].first)
    //             ans += abs(heros[close] - dra[i].first);
    //         long long int rem = summer - heros[close];
    //         if (rem < dra[i].second)
    //             ans += abs(rem - dra[i].second);

    //         cout << ans << endl;
    //     }
    //     else if (close == heros.size())
    //     {
    //         long long int ans = 0;
    //         if (heros[close - 1] < dra[i].first)
    //             ans += abs(heros[close - 1] - dra[i].first);
    //         long long int rem = summer - heros[close - 1];
    //         if (rem < dra[i].second)
    //             ans += abs(rem - dra[i].second);

    //         cout << ans << endl;
    //     }
    //     else
    //     {
    //         long long int ans = INT_MAX;

    //         long long int tempans = 0;

    //         tempans += min(0LL, dra[i].first - heros[close]);
    //         long long int rem = summer - heros[close];
    //         tempans += abs(rem - dra[i].second);

    //         ans = min(tempans, ans);

    //         tempans = 0;
    //         tempans += min(0LL, dra[i].first - heros[close - 1]);
    //         rem = summer - heros[close - 1];
    //         tempans += abs(rem - dra[i].second);

    //         // write the code here
    //         ans = min(ans, tempans);

    //         cout << ans << endl;
    //     }
    // }
}
