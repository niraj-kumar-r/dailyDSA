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
        ListNode *merged = nullptr;
        ListNode *head = nullptr;
        while (list1 != nullptr && list2 != nullptr) {
            ListNode *a = new ListNode();
            a->next = nullptr;
            if (list1->val < list2->val) {
                a->val = list1->val;
                list1 = list1->next;
            } else {
                a->val = list2->val;
                list2 = list2->next;
            }
            if (head == nullptr) {
                head = a;
                merged = a;
                continue;
            }
            merged->next = a;
            merged = merged->next;
        }

        if(list1 != nullptr) {
            if (head == nullptr) {
                merged = list1;
                head = merged;
            } else {
                merged->next = list1;
            }
        }

        if(list2 != nullptr) {
            if (head == nullptr) {
                merged = list2;
                head = merged;
            } else {
                merged->next = list2;
            }
        }

        return head;

    }
};

#endif //DAILYDSA_MERGETWOLISTS_H
