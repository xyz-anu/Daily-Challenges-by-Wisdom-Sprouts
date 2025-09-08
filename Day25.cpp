#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

TreeNode* buildTreeFromLevelOrder(const string& input) {
    if (input.empty()) return nullptr;
    stringstream ss(input);
    string item;
    vector<string> nodes;
    while (ss >> item) {
        nodes.push_back(item);
    }
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < nodes.size() && nodes[i] != "null") {
            node->left = new TreeNode(stoi(nodes[i]));
            q.push(node->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null") {
            node->right = new TreeNode(stoi(nodes[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}
int main() {
    cout << "Enter tree nodes in level order (space separated, use 'null' for missing):\n";
    string input;
    getline(cin, input);
    TreeNode* root = buildTreeFromLevelOrder(input);
    bool result = isValidBST(root, LLONG_MIN, LLONG_MAX);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
