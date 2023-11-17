/*
 * @lc app=leetcode id=2746 lang=cpp
 *
 * [2746] Decremental String Concatenation
 */

// @lc code=start
class Solution
{
public:

    string shortner ( string & str)
    {

        if ( str.size()==1)return str; 
        string temp =str[0];
        temp+=str[str.size()-1];
        return temp;
       
    }

    bool concat ( string & str1, string  & str2)
    {

      // here we have some cases 
     return str1[str1.size()-1]==str2[0];
      
    }



    int rec(int size, vector<string> &words, int index, string &curr,
            unordered_map<string, unordered_map<int, int>> &dp, int totalsize)

    {
        if (index == size)
            return totalsize;
        if (dp.find(curr) != dp.end() && dp[curr].find(index) != dp[curr].end())
            return dp[curr][index];
        string t1 = shortner ( curr+ words[index]);
        string t2= shortner( words[index]+ curr);
        int n1 = concat(curr, words[index]) ? totalsize + words[index].size() - 1 : totalsize + words[index].size();
        int n2 = concat ( words[index], curr )? totalsize+ words[index].size()-1:totalsize+ words[index].size();
     
       
     
      
        int length = min(rec(size, words, index + 1, t1, dp,n1), rec(size, words, index + 1, t2, dp,n2));
        return dp[curr][index] = length;
    }
    int minimizeConcatenatedLength(vector<string> &words)
    {
        

        
        int n = words.size();
        string str2 = shortner ( words[0]);
      

        unordered_map<string, unordered_map<int, int>> dp;
        int currsize= words[0].size();
    
      

        return rec( n , words, 1 , str2, dp , currsize)
       
    }
};
// @lc code=end

// i just need to save the first and last character of the resulting string 
