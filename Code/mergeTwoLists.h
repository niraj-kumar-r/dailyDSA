//
// Created by Niraj on 05-11-2022.
//

#ifndef DAILYDSA_MERGETWOLISTS_H
#define DAILYDSA_MERGETWOLISTS_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class mergeTwoLists {
public:
    ListNode *mergeTwoListsFunc(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }
        ListNode *merged = nullptr, *head = nullptr;
        while (list1 != nullptr && list2 != nullptr) {
            int a;
            if (list1->val < list2->val) {
                a = list1->val;
                list1 = list1->next;
            } else {
                a = list2->val;
                list2 = list2->next;
            }
            ListNode *b = new ListNode(a);
            if (head == nullptr) {
                head = b;
                merged = b;
                continue;
            }
            merged->next = b;
            merged = merged->next;
        }

        if (list1) {
            merged->next = list1;
        }

        if (list2) {
            merged->next = list2;
        }

        return head;

    }

};

#endif //DAILYDSA_MERGETWOLISTS_H
