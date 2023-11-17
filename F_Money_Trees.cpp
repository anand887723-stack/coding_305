// JAI BAJARANG BALI

// manitianajay45

// give me some  sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya h....

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {

        ll n, k;
        cin >> n >> k;
        ll arr[n + 1];
        arr[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        ll hrr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> hrr[i];
        }

        ll l = 1, r = n;
        ll ans = 0;

        if (arr[1] <= k)
        {
            ans = 1;
        }
        while (r >= l)
        {
            ll mid = (r + l) / 2;

            ll prev = 0;

            ll val = k + 1;

            for (ll i = 1; i < n; i++)
            {
                if (hrr[i - 1] % hrr[i] != 0)
                {
                    prev = i;
                }

                ll len = (i - prev + 1);

                if (len >= mid)
                {
                    val = min(val, arr[i + 1] - arr[i - mid + 1]);
                }
            }

            if (val <= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}