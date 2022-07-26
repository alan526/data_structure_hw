#include <iostream>
#include <cstdlib>
#include <fstream>
#include "BinaryTree.h"

using namespace std;

int main(void) {
	ifstream input;
	input.open("tree.txt");
	int value, choose, key;
	BinaryTree tree;

	if (!input) {
		cout << "File cannot open." << endl;
		exit(1);
	}
	else {
		while (input >> value) {
			tree.insertNode(value);
		}
	}
	tree.display();
	while(true) {
		cout << endl << "1: insert, 2: delete, 3: find, 4: display" << endl;
		cout << "Enter the number to choose function (if you want to finish enter -1) => ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter the key you want to insert => ";
			cin >> key;
			tree.insertNode(key);
			break;
		case 2:
			cout << "Enter the key you want to delete => ";
			cin >> key;
			tree.deleteNode(key);
			break;
		case 3:
			cout << "Enter the key you want to find => ";
			cin >> key;
			tree.find(key);
			break;
		case 4:
			cout << endl << "Tree" << endl;
			tree.display();
			cout << endl;
			break;
		case -1:
			input.close();
			system("pause");
			return(0);
		default:
			char discard;
			do{
				discard = getchar();
			}while (discard != '\n');
			cout << "Please enter correct choose number ^_^" << endl;
		}
	}
}