/* 
 * LeetCode 450 Delete NOde in a BST
 * Medium
 * Jiawei Wang
 * 2021.11.22
 */

#include <vector>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
	if (!root) return nullptr;
	if (root->val == key) {
	    if (!root->right) {
		TreeNode* left = root->left;
		delete root;
		return left;
	    }
	    else {
		TreeNode* right = root->right;
		// find right min
		while (right->left) 
		    right = right->left;
		swap(root->val, right->val);
	    }
	}
	root->left = deleteNode(root->left, key);
	root->right = deleteNode(root->right, key);
	return root;
    }
};
