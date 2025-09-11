#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int NULL_NODE = -999;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }
};
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nodes[0]);
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != NULL_NODE) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != NULL_NODE) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
int main() {
    Solution solution;
    vector<int> nodes;
    int n;
    cout << "Enter the number of elements in the tree: ";
    cin >> n;
    cout << "Enter the elements level by level (use -999 for null nodes):" << endl;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nodes.push_back(val);
    }
    TreeNode* root = buildTree(nodes);
    bool result = solution.isSymmetric(root);
    cout << "" << (result ? "true" : "false") << endl;
    return 0;
}
