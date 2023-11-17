#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;

    graph["ands"]["pra"] = 2;
    graph["ands"]["pra2"] = 3;
    graph["ands2"]["pra"] = 4;

    // Iterate through the outer unordered_map
    for (const auto &outerPair : graph)
    {
        const std::string &outerKey = outerPair.first;

        // Iterate through the inner unordered_map
        for (const auto &innerPair : outerPair.second)
        {
            const std::string &innerKey = innerPair.first;
            const double innerValue = innerPair.second;

            // Print key-value pairs
            std::cout << "graph[" << outerKey << "][" << innerKey << "] = " << innerValue << std::endl;
        }
    }
    // see here under ands key there is an unodered map stored as their value
    //  that ands unordered map can store anything 
    // similarly under the ands2 , there is an unordered map stored which again 
    // can store different set values that an unroderd map can store 

    return 0;
}
