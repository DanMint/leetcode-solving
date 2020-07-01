class Solution {
public:
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr;
        ListNode* head = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            auto *newNode = new ListNode();

            if (l3 == nullptr)
                head = l3 = newNode;

            else
                l3 = l3->next = newNode;

            const int num =
                (l1 != nullptr ? l1->val : 0) +
                (l2 != nullptr ? l2->val : 0) +
                carry;

            l3->val = num % 10;
            carry = num / 10;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (carry != 0) {
            auto *lastNode = new ListNode();
            l3 = l3->next = lastNode;
            l3->val = carry;
        }

        return head;
    }
};
