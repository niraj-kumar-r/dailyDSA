#include <unordered_map>
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> m;
        Node *oCurr = head;

        while (oCurr)
        {
            m[oCurr] = new Node(oCurr->val);
            oCurr = oCurr->next;
        }
        oCurr = head;
        Node *newHead = m[oCurr];
        while (oCurr)
        {
            newHead->next = m[oCurr->next];
            newHead->random = m[oCurr->random];
            oCurr = oCurr->next;
            newHead = newHead->next;
        }
        return m[head];
    }
};

int main()
{
    Node *head = new Node(7);
    Node *n1 = new Node(13);
    Node *n2 = new Node(11);
    Node *n3 = new Node(10);
    Node *n4 = new Node(1);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n1->random = head;
    n2->random = n4;
    n3->random = n2;
    n4->random = head;
    Solution s;
    Node *h = s.copyRandomList(head);
    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }
    return 0;
}