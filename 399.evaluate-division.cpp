/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution
{
public:
    double dfs(int  start, int dest,  vector < vector<pair<int, double>> & graph,  vector<bool> & visited )
    {
        if ( dest==start)return 1; 
        visited[start]=true ;
        for ( auto i : graph[start])
        {
            int v=i,first; double  edge=i.second; 
            double returned ; 
            if ( visited[i.first]==false ) returned= dfs( v, dest, graph, visited);
            if ( returned!=-1)
             return returned * i.second;            
        }
      visited[start]=false;
      return -1 ; 

    }
        vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        unordered_map<string, int> mp;
        int counter = 0;
        for (int i = 0; i < equations.size(); i++)
        {
            if (mp.find(equations[i][0]) == mp.end())
            {

                mp[equations[i][0]] = counter;
                counter++;
            }
        }

        vector < vector<pair<int, double>> graph(counter);
        for (int i = 0; i < equations.size(); i++)
        {
            int v1 = mp[equations[i][0]];
            int v2= mp[equations[i][1]];
            double edge = values[i];
            graph[v1].push_back({v2,edge});
            if ( edge!=0.0)
            graph[v2].push_back({v1, 1.0/edge});
        }
        
        vector<double > finalans;
        for ( int i =0 ; i <queries.size();i++)
        {
            vector<bool> visited(counter, false);

            finalans.push_back(dfs(mp[queries[i][0]], mp[queries[i][1]], graph, visited));

        }


        return finalans;
    }
};
// @lc code=end
