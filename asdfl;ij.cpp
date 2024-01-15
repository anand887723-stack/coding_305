#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> aindex;
        vector<int > bindex;

        if ( s.length()>=a.length())
        for ( int i = 0 ; i<=s.length()- a.length();i++)
        {

             cout<<"ok"<<endl;
            bool flag= true;
            for ( int j= 0 ; j<a.length();j++)
            {
                if (s[i+j]!=a[j])
                {
                    flag =false; break;
                }
            }

            if ( flag)
            {
                aindex.push_back(i);
            }
        }

          if ( s.length()>=b.length())

        for ( int i = 0 ; i<=s.length()- b.length();i++)
        {
            bool flag= true;
            for ( int j= 0 ; j<b.length();j++)
            {
                if (s[i+j]!=b[j])
                {
                    flag =false; break;
                }
            }

            if ( flag)
            {
                bindex.push_back(i);
            }
        }
        if ( aindex.size()==0 ||bindex.size()==0)
        {
            return {};
        }

        // already they are sorted , now i need to travserse the array 1 and find the
        vector<int> ans;
        unordered_set<int>exist;
        for ( int i =0 ; i<aindex.size();i++)
        {

            int first= aindex[i];
            int firstindex= lower_bound ( bindex.begin(), bindex.end() , first) -bindex.begin();
            if ( firstindex!=bindex.size()&&firstindex>=0)
            {
                if ( bindex[firstindex]<=aindex[i]+k)
                {
                    ans.push_back(aindex[i]);
                    exist.insert(aindex[i]);
                }
            }


            int secondindex= lower_bound ( bindex.begin(), bindex.end() , first-k) -bindex.begin();
            if ( secondindex!=bindex.size()&&firstindex>=0)
            {
                if ( bindex[secondindex]+k<=a[i])
                {
                    if ( exist.find (aindex[i])==exist.end())
                    {

                        ans.push_back(aindex[i]);
                      exist.insert(aindex[i]);
                    }
                }
            }
        }

        sort (ans.begin() , ans.end());
         cout<<"---"<<endl;
        for ( auto i:ans)cout<<i<<" ";cout<<endl;

        cout<<"---"<<endl;

        return ans;    
    }
};


int main()
{

    Solution sol;
  string  s = "wl", a = "xjigt", b = "wl"; int  k = 2;
    sol.beautifulIndices(s,a,b,k);
}



// "wl"
// "xjigt"
// "wl"
// 2
