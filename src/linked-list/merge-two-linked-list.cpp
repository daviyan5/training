/*
Merge Two Sorted Linked Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted linked list and return the head of the new sorted linked list.

The new list should be made up of nodes from list1 and list2.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,5]

Output: [1,1,2,3,4,5]

Example 2:

Input: list1 = [], list2 = [1,2]

Output: [1,2]

Example 3:

Input: list1 = [], list2 = []

Output: []

Constraints:

    0 <= The length of the each list <= 100.
    -100 <= Node.val <= 100

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *merged { new ListNode(0) };
            ListNode *merged_head = merged;
            while (list1 && list2) {
                if (list1->val < list2->val) {
                    merged->next = new ListNode(list1->val);
                    list1 = list1->next;
                } else {
                    merged->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                
                merged = merged->next;
            }
            while (list1) {
                merged->next = new ListNode(list1->val);
                list1 = list1->next;
                merged = merged->next;
            }
            while (list2) {
                merged->next = new ListNode(list2->val);
                list2 = list2->next;
                merged = merged->next;
            }
            return merged_head->next;
        }
};
    