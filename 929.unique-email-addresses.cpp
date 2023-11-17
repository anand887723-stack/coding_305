/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
class Solution {
public:

    string cleaned ( string  & str)
    {

        // so from behind first find the @ , find the + from last then add that stting 
       
        int lastat;

        for ( int i = str.size()-1;i>=0;i--)
        {
            lastat=i ; 
            if ( str[i]=='@')break; 
           
        }
        int firstplus  =-1 ; 

       for ( int i =0; i< lastat;i++)
       {
          
            if (str[i] == '+')
              {  firstplus = i ;break;}
       }
       // now start doing in between 
       for ( int i =0 ; i< firstplus;i++)
       {ans+=str[i];}
       for ( int  i = index;i<str.size();i++)
       ans+=str[i];

        return ans ; 
    }
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> finalemails;
        for ( auto i: emails)
        {

            finalemails.insert(cleaned  ( i));



        }

        return finalemails.size();

        
    }
};
// @lc code=end

