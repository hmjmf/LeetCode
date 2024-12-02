#include <vector>
#include <assert.h>
#include "helper.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        auto l = head;
        int overflow = 0;
        while (l1 || l2) {
            l->next = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + overflow);
            overflow = 0;
            if (l->next->val >= 10) {
                overflow = l->next->val / 10;
                l->next->val = l->next->val % 10;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            l = l->next;
        }
        if (overflow) {
            l->next = new ListNode(overflow);
        }
        auto ret = head->next;
        delete head;
        return ret;
    }
};

int main()
{
    Solution s;
    ListNode::print_list(s.addTwoNumbers(ListNode::make_list({2, 4, 3}), ListNode::make_list({5, 6, 4})));
    ListNode::print_list(s.addTwoNumbers(ListNode::make_list({9,9,9,9,9,9,9}), ListNode::make_list({9,9,9,9})));


}
