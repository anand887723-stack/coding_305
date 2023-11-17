#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#
using namespace std;

// Define a structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Define a comparison function for sorting edges
bool compareEdges(Edge a, Edge b)
{
    return a.weight > b.weight;
}   

class Graph
{
public:
    // Constructor
    Graph(vector<Edge> edges, int numVertices);

    // Function to find the minimum spanning tree using Prim's Algorithm
    void primMST();

private:
    int numVertices;
    vector<vector<pair<int, int>>> adjacencyList; // Adjacency list to represent the graph
};

// Constructor to initialize the graph
Graph::Graph(vector<Edge> edges, int numVertices)
{
    this->numVertices = numVertices;
    adjacencyList.resize(numVertices);

    // Add edges to the adjacency list
    for (const auto &edge : edges)
    {
        adjacencyList[edge.src].emplace_back(edge.dest, edge.weight);
        adjacencyList[edge.dest].emplace_back(edge.src, edge.weight);
    }
}

// Prim's Algorithm to find the minimum spanning tree
void Graph::primMST()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Priority queue to store vertices with their key values
    vector<int> key(numVertices, INT_MAX);  // Key values used to pick the minimum weight edge
    vector<bool> inMST(numVertices, false); // To represent whether a vertex is included in MST

    // Start from vertex 0 (assuming the algorithm starts from V1)
    int src = 0;
    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto &neighbor : adjacencyList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    int totalCost = 0;
    for (int i = 1; i < numVertices; ++i)
    {
        cout << "Edge: " << i << " - " << i + 1 << " (Weight: " << key[i] << ")" << endl;
        totalCost += key[i];
    }

    cout << "Total Cost of Minimum Spanning Tree: " << totalCost << endl;
}

int main()
{
    // Define the edges of the graph
    vector<Edge> edges = {
        {0, 1, 23}, {0, 3, 9}, {0, 4, 5}, {1, 2, 31}, {1, 8, 12}, {2, 5, 21}, {3, 4, 13}, {3, 7, 6}, {4, 5, 18}, {4, 6, 99}, {4, 7, 19}, {5, 9, 7}, {7, 8, 3}, {8, 9, 7}};

    int numVertices = 10; // Number of vertices in the graph

    // Create a graph and find the minimum spanning tree using Prim's Algorithm
    Graph graph(edges, numVertices);
    graph.primMST();

    return 0;
}
