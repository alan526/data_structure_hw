#include "BinaryTree.h"
#include <iostream>

using namespace std;

/* constructor */
BinaryTree::BinaryTree():root(nullptr){

}


void BinaryTree::insertNode(int key) {
	if (root == nullptr) {
		root = new TreeNode(key);
	}
	else {
		TreeNode *current = root;
		/* whether key exist and insert the key */
		while (true) {
			/* the key has existed */
			if (key == current->data) {
				cout << "The data is repeat." << endl;
				break;
			}
			/* key is bigger */
			else if (key > current->data) {
				if (current->rightchild == nullptr) {
					current->rightchild = new TreeNode(key);
					break;
				}
				else {
					current = current->rightchild;
					continue;
				}
			}
			/* key is smaller */
			else {
				if (current->leftchild == nullptr) {
					current->leftchild = new TreeNode(key);
					break;
				}
				else {
					current = current->leftchild;
					continue;
				}
			}
		}
	}
}

void BinaryTree::find(int key) const{
	TreeNode *current = root;
	if (root == nullptr) {
		cout << "The tree is empty." << endl;
	}
	else {
		while (current != nullptr && key != current->data) {
			if (key > current->data) {
				current = current->rightchild;
			}
			else {
				current = current->leftchild;
			}
		}
		if (current == nullptr) {
			cout << "The key is not exist." << endl;
		}
		else if (current->data == key) {
			int rk = rank(key, root);
			cout << "The key is No." << rk << " small" << endl;
		}
		else {
			cout << "The key is not exist ." << endl;
		}
	}
}

int BinaryTree::rank(int key, TreeNode* current) const{
	if (current) {
		int size;
		if (key >= current->data) {
			size = 1;
		}
		else {
			size = 0;
		}
		return(size + rank(key, current->leftchild) + rank(key, current->rightchild));
	}
	else {
		return(0);
	}
}

void BinaryTree::inorder(TreeNode* current) const{
	if (current) {
		inorder(current->leftchild);
		cout << current->data << " ";
		inorder(current->rightchild);
	}
}

void BinaryTree::preorder(TreeNode* current) const {
	if (current) {
		cout << current->data << " ";
		preorder(current->leftchild);
		preorder(current->rightchild);
	}
}

void BinaryTree::display() const{
	if (root == nullptr) {
		cout << "The binary tree is empty." << endl;
	}
	else {
		TreeNode *current = root;
		cout << "Inorder => ";
		inorder(root);
		cout << endl << "Preorder => ";
		preorder(root);
		cout << endl;
	}
}

TreeNode* BinaryTree::successor(TreeNode *current) const{
	while (current->leftchild!=nullptr){
		current = current->leftchild;
	}
	return(current);
	
}

void BinaryTree::deleteNode(int key) {
	TreeNode *beforeCurrent = nullptr, *current;
	current = root;
	if (current == nullptr) {
		cout << "The tree is empty." << endl;
	}
	else {
		while (current != nullptr && key != current->data) {
			beforeCurrent = current;
			if (key > current->data) {
				current = current->rightchild;
			}
			else {
				current = current->leftchild;
			}
		}
		/* The key has not been found */
		if (current == nullptr) {
			cout << "The key is not exist." << endl;
		}
		/* delete the key */
		else if (current->data == key) {
			/* case 1: no child */
			if (current->leftchild == nullptr&&current->rightchild == nullptr) {
				if (current != root) {
					if (beforeCurrent->leftchild == current) {
						beforeCurrent->leftchild = nullptr;
					}
					else {
						beforeCurrent->rightchild = nullptr;
					}
				}
				else {
					root = nullptr;
				}
				delete current;
			}
			/* case 2: two child */
			else if (current->leftchild != nullptr&&current->rightchild != nullptr) {
				/* use successor to instead */
				TreeNode *suc = successor(current->rightchild);
				int value = suc->data;
				deleteNode(suc->data);
				current->data = value;
			}
			/* case 3: one child */
			else {
				TreeNode *child;
				/* child in right or left */
				if (current->leftchild == nullptr) {
					child = current->rightchild;
				}
				else {
					child = current->leftchild;
				}

				if (current == root) {
					root = child;
				}
				else {
					if (current == beforeCurrent->leftchild) {
						beforeCurrent->leftchild = child;
					}
					else {
						beforeCurrent->rightchild = child;
					}
				}
			}
		}
	}

}

