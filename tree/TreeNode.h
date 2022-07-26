#ifndef TreeNode


class TreeNode {
private:
	TreeNode *leftchild;
	TreeNode *rightchild;
	int data;
public:
	TreeNode();
	TreeNode(int newdata);

	friend class BinaryTree;
};
#endif // !TreeNode
#pragma once
