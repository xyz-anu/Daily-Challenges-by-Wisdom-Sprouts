#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q)
        return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right)
        return root;
    
    return left ? left : right;
}
TreeNode* buildTree() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    if (n == 0) return nullptr;
    cout << "Enter node values in level-order (-1 for NULL):\n";
    int val;
    cin >> val;
    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    for (int i = 1; i < n; ) {
        TreeNode* current = q.front();
        q.pop();

        cin >> val;
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }
        i++;
        if (i >= n) break;
        cin >> val;
        if (val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int value) {
    if (!root) return nullptr;
    if (root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left) return left;
    return findNode(root->right, value);
}
int main() {
    TreeNode* root = buildTree();
    int p_val, q_val;
    cout << "Enter value of node p: ";
    cin >> p_val;
    cout << "Enter value of node q: ";
    cin >> q_val;

    TreeNode* p = findNode(root, p_val);
    TreeNode* q = findNode(root, q_val);
    if (!p || !q) {
        cout << "One or both nodes not found in the tree.\n";
        return 0;
    }
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->val << endl;
    return 0;
}
