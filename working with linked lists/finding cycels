class Solution {
public:
   bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        if (head->next == nullptr)
            return false;
        vector<ListNode*> visited;
        ListNode *current = new ListNode;
        current = head;

        while (true) {
            if (visited.empty()) {
                visited.push_back(current);
                current = current->next;
                continue;
            }
            for (const auto &el : visited) {
                if (el == current)
                    return true;
            }
            visited.push_back(current);
            if (current->next == nullptr)
                return false;
            else
                current = current->next;
        }
    }
};
