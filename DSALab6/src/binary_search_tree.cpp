#include "../include/binary_search_tree.h"

bool BST::insert(int value, TreeNode*& node) {
	if (node == nullptr) {
		node = new TreeNode(value);
		return true;
	}

	if (node->value > value) return insert(value, node->left);
	else if (node->value < value) return insert(value, node->right);
	return false; // node->value == value
}

bool BST::insert(int value) {
	return insert(value, root);
}

bool BST::search(int value, TreeNode* node) {
	if (node == nullptr) return false;
	if (node->value == value) return true;
	else if (node->value > value) return search(value, node->left);
	else return search(value, node->right); // node->value > value
}

bool BST::search(int value) {
	return search(value, root);
}

int BST::count(TreeNode* node) {
	if (node == nullptr) return 0;
	return 1 + count(node->left) + count(node->right);
}
	
int BST::count() {
	return count(root);
}
	
int BST::height(TreeNode* node) {
	if (node == nullptr) return -1;

	int left_height = height(node->left);
	int right_height = height(node->right);
	return 1 + (left_height > right_height ? left_height : right_height);
}

int BST::height() {
	return height(root);
}

bool BST::remove(int value, TreeNode*& node) {
	if (node == nullptr) return false;

	if (node->value > value) return remove(value, node->left);
	else if (node->value < value) return remove(value, node->right);
	else { // node to delete found
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
			return true;
		}
		else if (node->left == nullptr) {
			TreeNode* temp = node;
			node = node->right;
			delete temp;
			return true;
		}
		else if (node->right == nullptr) {
			TreeNode* temp = node;
			node = node->left;
			delete temp;
			return true;
		}
		else { // two children
			TreeNode* successor = node->right;

			while (successor->left != nullptr)
				successor = successor->left;

			node->value = successor->value;
			return remove(successor->value, node->right);
		}
	}
}

bool BST::remove(int value) {
	return remove(value, root);
}