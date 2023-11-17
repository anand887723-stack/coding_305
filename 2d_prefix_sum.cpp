
#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<vector<long long int>> psum;
    solution(vector<vector<int>> &matrix)
    {

        cout << "ok1" << endl;
        int row = matrix.size();
        int col = matrix[0].size();

        psum.resize(row + 1, vector<long long int>(col + 1, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // cout << i << " " << j << endl;

                psum[i + 1][j + 1] += matrix[i][j];
                psum[i + 1][j + 1] += psum[i][j + 1];
                psum[i + 1][j + 1] += psum[i + 1][j];
                psum[i + 1][j + 1] -= psum[i][j];
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // cout << i << " " << j << endl;

                cout << psum[i + 1][j + 1] << " ";
            }

            cout << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {

        cout << "ok2" << endl;
        int sum = psum[row2 + 1][col2 + 1] + psum[row1][col1] - psum[row2][col1] - psum[row1][col2];

        return sum;
    }
};
int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};
    solution sol(matrix);

    // cout << sol.sumRegion(1, 1, 2, 2);
}