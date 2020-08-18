class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto *current = new TreeNode;
        if (root != nullptr) {
            current = root;
        }
        else {
            root = new TreeNode;
            root->val = val;
            return root;
        }

        while (true) {
            if (current->val > val) {
                if (current->left == nullptr) {
                    current->left = new TreeNode;
                    current = current->left;
                    current->val = val;
                    break;
                }
                else {
                    current = current->left;
                }

            }
            else if (current->val < val) {
                if (current->right == nullptr) {
                    current->right = new TreeNode;
                    current = current->right;
                    current->val = val;
                    break;
                }
                current = current->right;
            }
        }
        return root;
    }
};
