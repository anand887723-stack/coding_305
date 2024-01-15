#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << "=" << x << endl;

class ll
{
public:
    int x;
    ll *next;
    ll(int x)
    {
        this->x = x;
        next = NULL;
    }
    ll()
    {
        x = 0;
        next = NULL;
    }
    ll(int x, ll *next)
    {
        this->x = x;
        this->next = next;
    }
    void addnode(ll *node)
    {
        // go to the last and then add them
        ll *temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        // this is change done, the pointer internal
        // members are accessed.
    }

    void print()
    {
        ll *temp = this;
        while (temp != NULL)
        {
            cout << temp->x << " ->";
            temp = temp->next;
        }

        cout << endl;
    }
};
int main()
{

    ll head(1);
    ll node2(3);

    for (int i = 2; i <= 5; i++)
    {
        ll *it = new ll(i);
        head.addnode(it);
    }

    head.print();
}