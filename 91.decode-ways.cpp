/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start

class Solution {
public:


    unordered_map<string , bool> numbers;

    int rec( int i, string & s, vector<int > & dp )
    {

    // bro see what I want is to have a hobby , so that whenever I feel low or wherever I feel lonely or even i would say that 
    // whenever I am alone and try to enjoy that loneliness , I think in that moment of time , this music that I will be learning
    // in that time will be useful to be precsie 


        if( i==s.size())return  1; 

        if ( dp[i]!=-1)return dp [i];
        string curr ="";
        int counter =0 ; 
        for ( int index =i ; index<min( i+2, ( int )s.size());index++)
        {
            curr +=s[index];
            if ( numbers.find( curr )!= numbers.end())
            {
                counter +=rec( index +1, s, dp);
            }
            
            
        }

        return dp[i]= counter;


    }

    int numDecodings(string s) {



        // so this is again a one d valid partitionm kind of question to be precise 
        vector<int> dp ( s.size(),-1);

        for ( int i =1 ;i<=26;i++ )
        {
            numbers[ to_string (i)]=true ; 
        }
        // remove the leading zeroes 
        return rec( 0 , s, dp);


        
    }
};
// @lc code=end



// these small functions are really important like stoi , atoi etc to be precise 