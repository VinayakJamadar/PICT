/* Problem Statement :
	Create an inordered threaded binary tree and perform inorder, preorder traversals and deletion. Analyze
 	time and space complexity of the algorithm. */

#include <iostream>
using namespace std;

// class Node
class Node{

	Node *left;
	Node *right;
	int data;
	bool lbit, rbit;

public:
	Node(){
		left = right = NULL;
		data = 0;
		lbit = rbit = 0;
	}

	friend class TBT;
};


// class TBT --> Threaded Binary Tree
class TBT{

	Node *head, *root;

public:
	TBT(){
		head = root = NULL;
	}

	bool status(){
		return head->lbit;
	}

	void set(){ // This will set the head and root to NULL
		head = NULL;
		root = NULL;
	}

	void create(Node *current = NULL){ // Creating Tree
		int choice;
		if (root == NULL)
		{ // Reading Root Element of Tree
			cout << "\n1.Add Root Element of Tree" << endl;
			cout << "2.Exit" << endl;
			cout << "\nEnter your Choice : ";
			cin >> choice;

			if (choice == 1)
			{
				head = new Node();
				root = new Node();

				head->lbit = 1;
				head->rbit = 1;
				head->right = head;
				head->left = root;
				root->left = root->right = head;
				cout << "Enter Root Element of Tree : ";
				cin >> root->data;
				current = root;
			}
			else return;
		}

		while (current->lbit == 0 || current->rbit == 0){
			cout << "\nYour are at Element : " << current->data << endl;
			cout << "1.Add Left Element." << endl;
			cout << "2.Add Right Element." << endl;
			cout << "3.Exit" << endl;

			cout << "\nEnter your Choice : ";
			cin >> choice;

			if (choice == 1){
				if (current->lbit){ // Left element is already added
					cout << "Left Element of " << current->data << " is already Added." << endl;
				}
				else{ // Reading Left element of Current Node
					Node *new_node = new Node();
					cout << "Enter Left Element of " << current->data << " : ";
					cin >> new_node->data;
					new_node->left = current->left;
					new_node->right = current;
					current->lbit = 1;
					current->left = new_node;
					create(current->left);
				}
			}

			else if (choice == 2){
				if (current->rbit){ // Right element is already added
					cout << "Right Element of " << current->data << " is already Added." << endl;
				}
				else{ // Reading Right element of Current Node
					Node *new_node = new Node();
					cout << "Enter Right Element of " << current->data << " : ";
					cin >> new_node->data;
					new_node->left = current;
					new_node->right = current->right;
					current->rbit = 1;
					current->right = new_node;
					create(current->right);
				}
			}

			else if (choice == 3) break;

			else cout << "Enter a valid choice" << endl;
		}
	}

	// This is preorder traversal of TBT
	void inorder(){
		Node *current = head->left;
		do{
			while (current->lbit){
				current = current->left;
			}
			cout << current->data << " ";

			while (current->rbit == 0){
				current = current->right;
				if (current == head) return;
				cout << current->data << " ";
			}
			current = current->right;

		} while (current != head);
	}

	// This is preorder traversal of TBT
	void preorder(){
		Node *current = head->left;
		do{
			while (current->lbit){
				cout << current->data << " ";
				current = current->left;
			}
			cout << current->data << " ";

			while (current->rbit == 0){
				current = current->right;
				if (current == head) return;
			}
			current = current->right;

		} while (current != head);
		cout << endl;
	}

	bool deletion(int d){
		Node *current = root, *parent = head;

		// Traversing to left most element of TBT
		while (current->lbit){
			if(current->data == d) break;
			parent = current;
			current = current->left;
		}
		
		while (current != head){
			if (current->data == d){

				// Deleting internal node
				if (current->lbit and current->rbit){
					Node *replacing_node = current;
					parent = current;
					current = current->right;

					// If deleting node's right don't have left element
					// Then replace deleting node with its right child
					if(current->lbit == 0){
						if(current->rbit == 0){
							replacing_node->data = current->data;
							replacing_node->right = current->right;
						}
						else{
							current->right->left = current->left;
							replacing_node->data = current->data;
							replacing_node->right = current->right;
						}
					}

					// For this we are traversing in right sub tree of deleting node to replace deleting node with lowest value of right sub tree of current
					else{
						while (current->lbit){
							parent = current;
							current = current->left;
						}

						int new_data = current->data;
						parent->left = current->left;
						parent->lbit = current->lbit;
						replacing_node->data = new_data;
					}

					delete current;
				}
				// Deleting non leaf node having either left or right node but not both
				else if (current->lbit or current->rbit){
					Node *next = current;
					// Checking if non leaf node have either left or right node
					if (current->lbit){
						next = current->left;
						next->right = current->right;
						next->rbit = current->rbit;
					}
					else{
						next = current->right;
						next->left = current->left;
						next->lbit = current->lbit;
					}

					// Pointing next node to parent current node
					if (parent->left == current){
						parent->left = next;
					}
					else{
						parent->right = next;
					}

					delete current;
				}
				// Deleting leaf node
				else{
					if (parent->left == current){
						parent->left = current->left;
						parent->lbit = 0;
					}
					else{
						parent->right = current->right;
						parent->rbit = 0;
					}
					delete current;
				}

				// Element deleted from TBT
				return true;
			}
			else{
				parent = current;
				current = current->right;
			}
		}

		// Element is not found in TBT
		return false;
	}
};

int main(){
	TBT t;

	t.create(); // Creating TBT

	// Menu for Operations of Dictionary
	while (1)
	{
		cout << "\n1. Add Element." << endl;
		cout << "2. Delete Element." << endl;
		cout << "3. Inorder Traversal." << endl;
		cout << "4. Preorder Traversal." << endl;
		cout << "5. Exit.\n" << endl;

		int choice;
		// Reading choice from user
		cout << "Enter your choice from Above Menu : ";
		cin >> choice;

		// Creating New TBT
		if (choice == 1){
			t.set();
			t.create();
		}
		// Deletion of element from TBT
		else if (choice == 2){
			if (t.status()){
				int element;
				cout << "Enter Element to be Deleted from TBT: ";
				cin >> element;

				if (t.deletion(element))
					cout << element << " is Deleted from TBT." << endl;
				else
					cout << element << " is not present in TBT." << endl;
			}
			else
				cout << "Tree is not yet created." << endl;
		}
		// Inorder Traversal of TBT
		else if (choice == 3){
			if (t.status()){
				cout << "Inorder Traversal of TBT : [ ";
				t.inorder();
				cout << "]" << endl;
			}
			else
				cout << "Tree is not yet created." << endl;
		}
		// Preorder Traversal of TBT
		else if (choice == 4){
			if (t.status()){
				cout << "Preorder Traversal of TBT : [ ";
				t.preorder();
				cout << "]" << endl;
			}
			else
				cout << "Tree is not yet created." << endl;
		}
		else if (choice == 5){
			cout << "Program Exit." << endl;
			break;
		}
		else{ // Invalid Choice
			cout << "Enter a valid choice." << endl;
		}
	}

	return 0;
}