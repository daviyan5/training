/*
Remove Node From End of Linked List

You are given the beginning of a linked list head, and an integer n.

Remove the nth node from the end of the list and return the beginning of the list.

Example 1:

Input: head = [1,2,3,4], n = 2

Output: [1,2,4]

Example 2:

Input: head = [5], n = 1

Output: []

Example 3:

Input: head = [1,2], n = 2

Output: [2]

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz


*/

#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *sentry = new ListNode(0, head);
            ListNode *temp = head;
    
            size_t size = 0;
            while (temp) {
                temp = temp->next;
                size += 1;
            }
            temp = sentry;
            
            for (size_t i = 0; i < size - n; i++) {
                temp = temp->next;
            }
            
            temp->next = temp->next->next;
            return sentry->next;
        }
};
    