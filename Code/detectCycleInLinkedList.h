//
// Created by Niraj on 05-11-2022.
//

#ifndef DAILYDSA_DETECTCYCLEINLINKEDLIST_H
#define DAILYDSA_DETECTCYCLEINLINKEDLIST_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
//    Detect cycle in O(1) space complexity, and O(n) time complexity
//    But destroys the linked list data-structure

    bool hasCycle(ListNode *head) {
        ListNode *a = new ListNode(0);
        return hasCycleHelper(head, a);
    }

    bool hasCycleHelper(ListNode *head, ListNode *a) {
        if (!head) {
            return false;
        } else if (head->next == a) {
            return true;
        }
        ListNode *temp = head->next;
        head->next = a;
        return hasCycleHelper(temp, a);
    }
};

#endif //DAILYDSA_DETECTCYCLEINLINKEDLIST_H
