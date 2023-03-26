// Problem Statement:

// Beginning with an empty binary tree, Construct binary tree by inserting the values in the order given. 
// After constructing a binary tree perform following operations on it -

// + Perform inorder_rec, preorder_rec and postorder_rec traversal (Recursive Method).
// + Perform inorder_itr, preorder_itr and postorder_itr traversal (Iterative Method).
// + Change a tree so that the roles of the left and right pointers are swapped at every node (Recursive Method).
// + Find the height of tree (Recursive Method).
// + Copy this tree to another tree [operator=] (Recursive Method).
// + Count number of leaves, number of internal nodes (Recursive Method).
// + Erase all nodes in a binary tree (Recursive Method).

#include<bits/stdc++.h>
using namespace std;


// Node for Binary Tree
class Node_for_Tree{

    int data;
    Node_for_Tree *left, *right;

    public:

        Node_for_Tree(){
            data = 0;
            left = NULL;
            right = NULL;
        }

        // Making class Binary_Tree and Stack as Friend Class
        friend class Binary_Tree;
        friend class Stack;
};


// Node for creating Stack
class Node_for_Stack{

    Node_for_Tree* data;
    Node_for_Stack* link;

    public:

        Node_for_Stack(){
            data = NULL;
            link = NULL;
        }

        // Making class Binary_Tree and Stack as Friend Class
        friend class Binary_Tree;
        friend class Stack;
};

// Creating Stack
class Stack{
    
    Node_for_Stack *top;

    public:
        Stack(){
            top = NULL;
        }

        bool is_empty(){ // This will check whether Stack is Empty
            if(top == NULL){
                return 1;
            }
            else{
                return 0;
            }
        }

        void push(Node_for_Tree* d){ // This will push element in Stack
            if(is_empty()){
                top = new Node_for_Stack();
                top->data = d;
            }
            else{
                Node_for_Stack *new_node = new Node_for_Stack();
                new_node->data = d;
                new_node->link = top;
                top = new_node;
            }
        }

        Node_for_Tree* pop(){ // This will pop element form Stack
            Node_for_Tree* p = top->data;
            top = top->link;
            return p;
        }

        Node_for_Stack* get_top(){ // This will return top address of Stack
            return top;
        }
};


// Binary Tree
class Binary_Tree{
    Node_for_Tree *root;
    int leaf, internal;

    public:

        Binary_Tree(){
            root = NULL;
            leaf = 0;
            internal = 0;
        }

        void create(Node_for_Tree* current = NULL){  // Creating Tree
            int choice, element;
            if(root == NULL){  // Reading Root Element of Tree 
                cout<<"\n1.Add Root Element of Tree"<<endl;
                cout<<"2.Exit"<<endl;
                cout<<"\nEnter your Choice : ";
                cin>>choice;

                if(choice == 1){
                    root = new Node_for_Tree();
                    cout<<"Enter Root Element of Tree : ";
                    cin>>root->data;
                    current = root;
                }
                else{
                    return;
                }
            }

            while (current->left == NULL || current->right == NULL)
            {
                cout<<"\nYour are at Element : "<<current->data<<endl;
                cout<<"1.Add Left Element."<<endl;
                cout<<"2.Add Right Element."<<endl;
                cout<<"3.Exit"<<endl;

                cout<<"\nEnter your Choice : ";
                cin>>choice;

                if(choice == 1){
                    if(current->left != NULL){  // Left element is already added
                        cout<<"Left Element of "<<current->data<<" is already Added."<<endl;
                    }
                    else{  // Reading Left element of Current Node
                        Node_for_Tree* new_Node_for_Tree = new Node_for_Tree();
                        cout<<"Enter Left Element of "<<current->data<<" : ";
                        cin>>new_Node_for_Tree->data;
                        current->left = new_Node_for_Tree;
                        create(current->left);
                    }
                }

                else if(choice == 2){  // Right element is already added
                    if(current->right != NULL){
                        cout<<"Right Element of "<<current->data<<" is already Added."<<endl;
                    }
                    else{  // Reading Right element of Current Node
                        Node_for_Tree* new_Node_for_Tree = new Node_for_Tree();
                        cout<<"Enter Right Element of "<<current->data<<" : ";
                        cin>>new_Node_for_Tree->data;
                        current->right = new_Node_for_Tree;
                        create(current->right);
                    }
                }

                else if(choice == 3){
                    return;
                }

                else{
                    cout<<"Enter a valid choice"<<endl;
                }
            }
            
        }

        void display(Node_for_Tree* current){  // This will display elements of Tree by all three method of traversals
            int choice;
            
            if(current == NULL){
                cout<<"\nTree is not yet created"<<endl;
                return;
            }

            while (1)
            {
                cout<<"\n1.Inorder Traversal."<<endl;
                cout<<"2.Preorder Travesal."<<endl;
                cout<<"3.Postorder Travesal."<<endl;
                cout<<"4.Exit"<<endl;

                cout<<"\nEnter your Choice : ";
                cin>>choice;

                if(choice == 1){  // Calling Recursive and Iterative Inorder Traversal
                    cout<<"\n\nRecursive Inorder Traversal of Binary Tree : "<<endl;
                    inorder_rec(get_root());
                    cout<<endl;
                    cout<<"\n\nIterative Inorder Traversal of Binary Tree : "<<endl;
                    inorder_itr(get_root());
                    cout<<endl;
                }
                else if(choice == 2){  // Calling Recursive and Iterative Preorder Traversal
                    cout<<"\n\nRecursive Preorder Traversal of Binary Tree : "<<endl;
                    preorder_rec(get_root());
                    cout<<endl;
                    cout<<"\n\nIterative Preorder Traversal of Binary Tree : "<<endl;
                    preorder_itr(get_root());
                    cout<<endl;
                }
                else if(choice == 3){  // Calling Recursive and Iterative Postorder Traversal
                    cout<<"\n\nRecursive Postorder Traversal of Binary Tree : "<<endl;
                    postorder_rec(get_root());
                    cout<<endl;
                    cout<<"\n\nIterative Postorder Traversal of Binary Tree : "<<endl;
                    postorder_itr(get_root());
                    cout<<endl;
                }
                else if(choice == 4){
                    break;
                }
                else{
                    cout<<"Enter a valid choice"<<endl;
                }
            }
            
        }

        void inorder_rec(Node_for_Tree* current){  // Inorder Traversal by Recursive Method
            if(current != NULL){
                inorder_rec(current->left);
                cout<<current->data<<" ";
                inorder_rec(current->right);
            }
        }

        void preorder_rec(Node_for_Tree* current){  // Preorder Traversal by Recursive Method
            if(current != NULL){
                cout<<current->data<<" ";
                preorder_rec(current->left);
                preorder_rec(current->right);
            }
        }

        void postorder_rec(Node_for_Tree* current){  // Postorder Traversal by Recursive Method
            if(current != NULL){
                postorder_rec(current->left);
                postorder_rec(current->right);
                cout<<current->data<<" ";
            }
        }

        void inorder_itr(Node_for_Tree* current){  // Inorder Traversal by Iterative Method
            Stack s;
            while (current != NULL || !s.is_empty())
            {
                while(current != NULL){
                    s.push(current);
                    current = current->left;
                }
                
                current = s.pop();
                cout<<current->data<<" ";
                current = current->right;
            }
        }

        void preorder_itr(Node_for_Tree* current){  // Preorder Traversal by Iterative Method
            Stack s;
            while (1)
            {
                while(current != NULL){
                    cout<<current->data<<" ";
                    if(current->right != NULL){
                        s.push(current->right);
                    }
                    current = current->left;
                }
                
                if(s.is_empty()){
                    return;
                }
                current = s.pop();
            }
        }

        void postorder_itr(Node_for_Tree* current){  // Postorder Traversal by Iterative Method
            Stack s1, s2;
            s1.push(current);
            Node_for_Tree *t = NULL;
            while (!s1.is_empty())
            {
                t = s1.get_top()->data;
                s1.pop();
                s2.push(t);

                if(t->left){
                    s1.push(t->left);
                }
                if(t->right){
                    s1.push(t->right);
                }
            }

            while (!s2.is_empty())
            {
                t = s2.get_top()->data;
                s2.pop();
                cout<<t->data<<" ";
            }
        }

        void swap_tree(Node_for_Tree* current){  // Swapping of Nodes
            Node_for_Tree* temp;
            if(current != NULL){
                swap_tree(current->left);
                swap_tree(current->right);

                // Swapping nodes of current node
                temp = current->left;
                current->left = current->right;
                current->right = temp;
            }
        }

        int height_of_tree(Node_for_Tree *current){  // Calculating Height of Tree
            if(current == NULL){
                return 0;
            }
            else{
                int LeftHeight = height_of_tree(current->left);
                int RightHeight = height_of_tree(current->right);
                return max(LeftHeight, RightHeight) + 1;
            }
        }

        void copy_tree(Node_for_Tree* current){
            Node_for_Tree* copy = current; // Coping Tree "current" in Tree "copy"
            cout<<"\nTree is Copied."<<endl;

            cout<<"Displaying Copied Tree"<<endl;
            display(copy); // Displaying copied tree
        }

        void nodes_calculation(Node_for_Tree* current){  // This will Calculate the Leaf and Internal Nodes of Tree
            if(current != NULL){
                nodes_calculation(current->left);
                if(current->left == NULL && current->right == NULL){
                    // if current left and right element are NULL then it is Leaf Node
                    leaf++;
                }
                else{
                    // Else it is Internal Node
                    internal++;
                }
                nodes_calculation(current->right);
            }
        }

        int leaf_nodes(){  // This will return the Number of Leaf Nodes
            return leaf;
        }

        int internal_nodes(){  // This will return the Number of Internal Nodes
            return internal;
        }

        void delete_nodes(Node_for_Tree* current){  // Deleting Nodes by Post Order Traversal
            if(current != NULL){
                delete_nodes(current->left);
                delete_nodes(current->right);
                cout<<"Deleted node is : "<<current->data<<endl;
                delete current;
            }
        }

        Node_for_Tree* get_root(){  // This will return root address of Tree
            return root;
        }

        void set_root(){  // This will set the root to NULL
            root = NULL;
            leaf = 0;
            internal = 0;
        }
};



int main(){
    int choice;
    Binary_Tree BT;

    cout<<"\nCreate a Binary Tree."<<endl;
    BT.create();
    
    while (1)
    {

        // Menu
        cout<<"\n1.Create New Binary Tree."<<endl;
        cout<<"2.Display Binary Tree."<<endl;
        cout<<"3.Height Binary Tree."<<endl;
        cout<<"4.Copy Tree in another Tree."<<endl;
        cout<<"5.Swapping of Tree Nodes."<<endl;
        cout<<"6.Leaf and Internal Nodes."<<endl;
        cout<<"7.Delete all Nodes."<<endl;
        cout<<"8.Exit."<<endl;

        cout<<"\nEnter your Choice : ";
        cin>>choice;

        if(choice == 1){ // Creating New Tree
            BT.set_root();
            BT.create();
        }
        else if(choice == 2){ // Displaying Tree
            BT.display(BT.get_root());
        }
        else if(choice == 3){ // Height of Tree
            cout<<"\nHeight of tree is : "<<BT.height_of_tree(BT.get_root())<<endl;
        }
        else if(choice == 4){ // Copying Tree
            BT.copy_tree(BT.get_root());
        }
        else if(choice == 5){ // Swapping of Nodes
            BT.swap_tree(BT.get_root());
            cout<<"\nTree is Swapped."<<endl;
            BT.display(BT.get_root());
        }
        else if(choice == 6){ // Leaf and Internal Node
            BT.nodes_calculation(BT.get_root());
            cout<<"\nTotal Number of nodes in Tree : "<<BT.leaf_nodes() + BT.internal_nodes()<<endl;
            cout<<"Number of leaf nodes in Tree : "<<BT.leaf_nodes()<<endl;
            cout<<"Number of internal nodes in Tree : "<<BT.internal_nodes()<<endl;
        }
        else if(choice == 7){ // Deleting all Nodes
            cout<<"Order of Deleting Nodes\n"<<endl;
            BT.delete_nodes(BT.get_root());
            BT.set_root();
        }
        else if(choice == 8){ // Exit the Program
            cout<<"\nProgram Exit"<<endl;
            break;
        }
        else{ // Invalid Choice
            cout<<"Enter a valid choice"<<endl;
        }
    }
    
    return 0;
}