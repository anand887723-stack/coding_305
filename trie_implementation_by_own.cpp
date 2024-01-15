

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << "=" << x << endl;

struct node
{
    // in case of struct everything is public
    node *links[26] = {NULL};
    bool flag = false;
};

class trie
{
public:
    struct node root;
    void insert(string &word)
    {
        node *temp = &root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->links[word[i] - 'a'] != NULL)
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
            {
                node *newnode = new node;
                temp->links[word[i] - 'a'] = newnode;
                temp = temp->links[word[i] - 'a'];
            }
        }
        temp->flag = true;
    }

    bool search(string &word)
    {
        node *temp = &root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->links[word[i] - 'a'] != NULL)
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
            {
                return false;
            }
        }
        return temp->flag;
    }

    bool searchprefix(string &word)
    {
        node *temp = &root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->links[word[i] - 'a'] != NULL)
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    trie mytrie;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            mytrie.insert(value[i]);
        }
        else if (type[i] == 2)
        {
            if (mytrie.search(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
        else
        {
            if (mytrie.searchprefix(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
    }
}