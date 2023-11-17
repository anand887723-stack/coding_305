/*
 * @lc app=leetcode id=2829 lang=cpp
 *
 * [2829] Determine the Minimum Sum of a k-avoiding Array
 */

// @lc code=start
class Solution {
public:
    int minimumSum(int n, int k) {

        // first of n/2 elements then from that

        // please keep in mind these test cases what if 
        // n is less than k and all 
        if ( n <=k/2)
        {
            long long int sum = 0;

            sum += ((n ) * (n  + 1)) / 2;
            return sum ;
        } 
        

        long long int sum =0 ; 
        sum += ( (k/2)*(k/2+1))/2;

        cout<<sum<<endl;
        sum += ((n + k - k / 2 -1+1) * (n + k - k / 2 - 1)) / 2;
        // nothing to do just the formula finding that is it bro 
        cout << sum << endl;
        sum -= ((k - 1) * (k)) / 2;
        cout << sum << endl;
        return sum; 
        
    }
};
// @lc code=end

