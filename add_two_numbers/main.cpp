#include "solution.cpp"
#include <iostream>

using std::cout;
using std::endl;




int main () {
    Solution solution;

    /// create l1 and l2 (input data)

    auto* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    auto* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    /// run the function that we're testing rn:

    ListNode* l3 = solution.addTwoNumbers(l1, l2);

    /// compare the outputted value with the predicted value.
    /// (in this case, manually)

    while (l3 != nullptr) {
        cout << l3->val;

        if (l3->next != nullptr)
            cout << " -> ";

        l3 = l3->next;
    }

    cout << endl;

    return 0;
}
