class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> results;

        for (const auto &query : queries)
        {
            const string &dividend = query[0];
            const string &divisor = query[1];

            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
            {
                results.push_back(-1.0);
            }
            else
            {
                results.push_back(bfs(dividend, divisor, graph));
            }
        }

        return results;
    }

private:
    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>> &equations, const vector<double> &values)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        // see this is how we make 2d vector of unordered map
        // here each of the key has a value as a container which is unordered map container 
        // so feel like if key is ands, then ands will have a value as unordered map conatiner, similarly if key is ands2 , then it will again 
        // have a container as value , as graph[ands]["pra"] ands graph[ands][pra2] are valid as well  

        for (int i = 0; i < equations.size(); i++)
        {
            const string &dividend = equations[i][0];
            const string &divisor = equations[i][1];
            double value = values[i];

            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value;
        }

        return graph;
    }

    double bfs(const string &start, const string &end, unordered_map<string, unordered_map<string, double>> &graph)
    {
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({start, 1.0});

        while (!q.empty())
        {
            string node = q.front().first;
            double value = q.front().second;
            q.pop();

            if (node == end)
            {
                return value;
            }

            visited.insert(node);

            for (const auto &neighbor : graph[node])
            {
                const string &neighborNode = neighbor.first;
                double neighborValue = neighbor.second;

                // feel at each node  , since we can't go back to the source and report the child values , so we are just storing
                // the cost of coming to this child, and if i am able to find that child node  , we will simply return the value ,
                // FEEL : THE POINT IS , ONCE WE TRAVERSE TO THE NODE THROUGH BFS, WE HAVE TO STORE THE PREVIOUS PATH DATA

                if (visited.find(neighborNode) == visited.end())
                {
                    q.push({neighborNode, value * neighborValue});
                }
            }
        }

        return -1.0;
    }
};

// dfs solution ( mine  )

class Solution
{
public:
    double dfs(int start, int dest, vector<vector<pair<int, double>>> &graph, vector<bool> &visited)
    {

        // so in these case of dfs , where there you have to again traverse the traversed path
        // we need to release the visited points which are on the wrong path while backtracking
        // here if a path returns true then we have to return true, ,so in these cases , we have to return true in the for loop itself
        // if the path is valid
        // if the path is invalid then we will return the false or anything for the end of for loop but  before it release the visited arary
        // NOTE :  at the last point of path, do not do any calcualtion , just return the true thing
        if (dest == start)
            return 1;
        visited[start] = true;
        for (auto i : graph[start])
        {
            int v = i.first;
            double edge = i.second;

            if (visited[i.first] == false)
            {
                double val = dfs(v, dest, graph, visited);
                if (val != -1)
                    return val * i.second;
            }
        }
        visited[start] = false;
        return -1;
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

            // i was not including this second equation variable
            // this was because of lack of concentration
            if (mp.find(equations[i][1]) == mp.end())
            {

                mp[equations[i][1]] = counter;
                counter++;
            }
        }
        // one mistake is in matching template brakcets of vector

        // in caes of graph with edges, do not panic, just think instead of neighbour vector of int , we are making neighbour vector of pair
        // and at the time of retrival , please bifrecate vertex and edge weight and then do the calcualation , that will make things simple.

        vector<vector<pair<int, double>>> graph(counter);
        for (int i = 0; i < equations.size(); i++)
        {
            int v1 = mp[equations[i][0]];
            int v2 = mp[equations[i][1]];
            double edge = values[i];
            graph[v1].push_back({v2, edge});
            if (edge != 0.0)
                graph[v2].push_back({v1, 1.0 / edge});
        }

        vector<double> finalans;
        for (int i = 0; i < queries.size(); i++)
        {
            vector<bool> visited(counter, false);
            if (mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end())
            {
                finalans.push_back(-1);
                continue;
            }

            finalans.push_back(dfs(mp[queries[i][0]], mp[queries[i][1]], graph, visited));
        }

        return finalans;
    }
};