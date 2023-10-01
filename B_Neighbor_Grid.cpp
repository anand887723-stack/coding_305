#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        bool ok = true;

        vector<vector<int>> a(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];

                // corner case
                if ((i == 1 && j == 1) ||
                    (i == 1 && j == m) ||
                    (i == n && j == 1) ||
                    (i == n && j == m))
                {
                    if (a[i][j] > 2)
                        ok = false;
                    else
                    {
                        a[i][j] = 2;
                    }
                }

                // left right up and down
                else if (i == 1 || j == 1 || i == n || j == m)
                {
                    if (a[i][j] > 3)
                        ok = false;
                    else
                        a[i][j] = 3;
                }

                // beech wala case
                else
                {
                    if (a[i][j] > 4)
                        ok = false;
                    else
                        a[i][j] = 4;
                }
            }
        }
        if (!ok)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}


// make all to the maximum capacity