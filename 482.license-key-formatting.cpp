/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        // first find the first dash and add the answer till that 
        // after it add all those and apply into groups 

        string ans ="";
        int n =s.size();
        int currk=0;
        int i =0;
        for (  ; i< s.size();i++)
        {
            if ( s[i]=='-')break;
            ans+=s[i];
            
            // i am not going to include them at any cost since I think that those are not the times
            // everyone asks that they are not since that is not what I have been aiming to hit the 
            // game as per the market has been concerned to be precise which are again the real 
            // game changer scenario to be precise as well as the real contest which are again the 
            // overall structure of the game at the general level 
        }
        ans+='-';
        for ( int j =i+1;i<n;i++)
        {
            if ( s[i]=='-')continue;
            else 
            {
                ans+=toupper(s[i]);
                currk++;
                if ( currk==k)
                {
                    ans+='-';
                    currk =0 ; 
                }
            }
        }

        if ( ans[ans.size()-1]=='-')ans.pop_back();
// bro the soulful music really fascinates me , and fascinates me at the level which  is not tiring at all 
// so I think that I must learn one of the instrucments in the general level, because imagine that 

// today i have to do some of the dp questions and I think that those are the really imporatant
// questions which are again the real game changer to be precsie 
// and in genral these are the real game changer to be preicse which are again the overall
// structure of the game to be precise whichare


        return ans; 
        
    }
};
// @lc code=end

string licenseKeyFormatting(string S, int K)
{
    string res;
    for (auto i = S.rbegin(); i < S.rend(); i++)
        if (*i != '-')
        { // ignore '-' in original string
            if (res.size() % (K + 1) == K)
                res += '-'; // every (K+1)th char is '-' from tail
            res += toupper(*i);
        }

    reverse(res.begin(), res.end());
    return res;
}


// so the agenda for today is to do that from that point to
// do 2 questions and then go for the dinner and that is it