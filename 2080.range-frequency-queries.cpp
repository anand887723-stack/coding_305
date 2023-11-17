/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */

// @lc code=start
class RangeFreqQuery {
public:
    int n ;

    unordered_map<int , vector<int>> pos;

    RangeFreqQuery(vector<int>& arr) {
         n = arr.size();
        for ( int i =0; i< n ; i ++)
        {
            pos[arr[i]].push_back( i );
        }
        
    }
    
    int query(int left, int right, int val) {


        // now find the lower and the upper bound index and then hit the game 
        auto it = lower_bound ( pos[val].begin(),pos[val].end(),left);
        if ( it ==pos[val].end())return 0  ;
        int first = it-pos[val].begin();
        auto it2= upper_bound ( pos[val].begin(), pos[val].end(),right);
        it2--;
        int second= it2-pos[val].begin();
        return second-first+1;


    
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

