//
// Created by Niraj on 05-11-2022.
//

#ifndef DAILYDSA_FINDINTERSECTIONINLINKEDLIST_H
#define DAILYDSA_FINDINTERSECTIONINLINKEDLIST_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (headA == headB || headA == headB->next) {
            return headA;
        } else if (headB == headA->next) {
            return headB;
        }

        ListNode *turtle = headA, *hare = headA, *terminal1 = nullptr, *terminal2 = nullptr;
        do {
            if (!hare->next) {
                hare->next = headB;
                if (!terminal1) {
                    terminal1 = hare;
                } else {
                    terminal2 = hare;
                }
            }
            hare = hare->next;
            if (!hare->next) {
                hare->next = headB;
                if (!terminal1) {
                    terminal1 = hare;
                } else {
                    terminal2 = hare;
                }
            }
            hare = hare->next;
            turtle = turtle->next;
        } while (turtle != hare);

        turtle = headA;
        while (turtle != hare) {
            if (!hare->next) {
                hare->next = headB;
                if (!terminal1) {
                    terminal1 = hare;
                } else {
                    terminal2 = hare;
                }
            }
            hare = hare->next;
            turtle = turtle->next;
        }
        if (terminal2) {
            terminal1->next = nullptr;
            terminal2->next = nullptr;
            return nullptr;
        } else {
            terminal1->next = nullptr;
            return turtle;
        }

    }

};

#endif //DAILYDSA_FINDINTERSECTIONINLINKEDLIST_H
