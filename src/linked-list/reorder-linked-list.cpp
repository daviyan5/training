/*
Reorder Linked List

You are given the head of a singly linked-list.

The positions of a linked list of length = 7 for example, can intially be represented as:

[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:

[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.

Example 1:

Input: head = [2,4,6,8]

Output: [2,8,4,6]

Example 2:

Input: head = [2,4,6,8,10]

Output: [2,10,4,8,6]

Constraints:

    1 <= Length of the list <= 1000.
    1 <= Node.val <= 1000

*/
#include <cstdint>
#include <tuple>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        void reorderList(ListNode* head) {
            auto [reversed, n] = reverse(head);
            uint32_t iter = 0;

            ListNode *reordered = new ListNode(0);
            ListNode *reordered_head = reordered;

            while (iter < n) {
                if (iter % 2 == 0) {
                    reordered->next = head;
                    head = head->next;
                } else {
                    reordered->next = reversed;
                    reversed = reversed->next;
                }
                reordered = reordered->next;
                iter += 1;
            }
            reordered->next = nullptr;
            head = reordered_head->next;
        }
        std::tuple<ListNode*, std::size_t> reverse(ListNode* head) {
            ListNode *reversed { nullptr };
            ListNode *parent { nullptr };

            std::size_t n = 0;
            while (head) {
                if (!reversed) {
                    reversed = new ListNode(head->val);
                } else {
                    parent = new ListNode(head->val);
                    parent->next = reversed;
                    reversed = parent;
                }
                head = head->next;
                n += 1;
            }
            return std::make_tuple(reversed, n);
        }
};