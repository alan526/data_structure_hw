#ifndef BinaryTree
#include "TreeNode.h"

class BinaryTree {
public :
	BinaryTree();
	void display() const;
	void inorder(TreeNode* current) const;
	void preorder(TreeNode* current) const;
	void insertNode(int key);
	void deleteNode(int key);
	void find(int key) const;
	int rank(int key, TreeNode* current) const;
	TreeNode* successor(TreeNode* current) const;
private:
	TreeNode *root;
};
#endif // !BinaryTree
#pragma once
