/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
    class NumMatrix {
    public:

    vector<vector<long long int>> psum ;
        NumMatrix(vector<vector<int>>& matrix) {    
            int row = matrix. size( ); 
            int col = matrix[0].size();

            psum.resize( row+1 , vector<long long int> ( col+1, 0 )); 
            for ( int i =0 ; i< row ; i++)
            {
                for ( int j=0 ; j< col;j++)
                {

                    psum[i + 1][j + 1] = matrix[i][j] + psum[i - 1][j] + psum[i - 1][j] - psum[i - 1][j - 1];
                }
            }
            
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            // now we need to retri
            inr sum  = psum[row2+1][col2+1]+ psum[row1][col1]-psum[row2][col1]-psum[row1][col2];

            return sum ; 
            
        }
    };

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end


// this is a classy dp problem actually kind of the prefix sum problem but since we are 
// deriving the current values from the past 2 3 values , so we can term as dp for hawabaazi