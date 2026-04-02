#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


class BST {
private:
	struct TreeNode {
		int value;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
	};

	TreeNode* root;
	bool insert(int value, TreeNode*& node);
	bool search(int value, TreeNode* node);
	int count(TreeNode* node);
	int height(TreeNode* node);
	bool remove(int value, TreeNode*& node);
	void in_order_traversal(TreeNode* node);
	void pre_order_traversal(TreeNode* node);
	void post_order_traversal(TreeNode* node);
public:
	BST() : root(nullptr) {}
	bool insert(int value);
	bool search(int value);
	int count();
	int height();
	bool remove(int value);
	void in_order_traversal();
	void pre_order_traversal();
	void post_order_traversal();
	void level_order_traversal();
};

#endif