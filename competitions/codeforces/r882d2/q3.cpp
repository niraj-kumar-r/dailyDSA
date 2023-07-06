#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define INT_SIZE 32

struct Node
{
    int v;
    Node *c[2];
};

Node *nN()
{
    Node *t = new Node;
    t->v = 0;
    t->c[0] = t->c[1] = NULL;
    return t;
}

void ins(Node *r, int p)
{
    Node *t = r;
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        bool b = p & (1 << i);

        if (t->c[b] == NULL)
            t->c[b] = nN();

        t = t->c[b];
    }
    t->v = p;
}

int qry(Node *r, int p)
{
    Node *t = r;
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        bool b = p & (1 << i);
        if (t->c[1 - b] != NULL)
            t = t->c[1 - b];
        else if (t->c[b] != NULL)
            t = t->c[b];
    }
    return p ^ (t->v);
}

int gMX(int a[], int n)
{
    Node *r = nN();
    ins(r, 0);

    int res = INT_MIN, pX = 0;

    for (int i = 0; i < n; i++)
    {
        pX = pX ^ a[i];
        ins(r, pX);
        res = max(res, qry(r, pX));
    }
    return res;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << gMX(a, n) << endl;
    }
}
