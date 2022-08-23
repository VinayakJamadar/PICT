/* Problem Statement :
A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting
keywords, updating values of any entry. Provide facility to display whole data sorted in
Ascending / Descending order. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation. */

#include<bits/stdc++.h>
using namespace std;

// class Node
class Node{
    Node* left;
    Node* right;
    string keyword;
    string meaning;

    public:
        Node(){
            left = NULL;
            right = NULL;
            keyword = "";
            meaning = "";
        }

        friend class Dictionary;
};

class Dictionary{

    Node* root;

    public:

        // This is constructor of class Dictionary
        // Here root is set to NULL
        Dictionary(){
            root = NULL;
        }

        // This will return address of root node
        Node* get_root(){
            return root;
        }

        // Creating new node i.e keyword in Dictionary
        Node* create_keyword(string k){
            Node* new_node = new Node();
            new_node->keyword = k;
            cout<<"Enter Meaning : ";
            string meaning;
            cin.ignore();
            getline(cin, new_node->meaning);
            return new_node;
        }

        // Adding new keyword in Dictionary
        bool add_keyword(string k){
            if(root == NULL){
                root = create_keyword(k);
                return true;
            }
            else{
                Node *current = root;
                while (1)
                {
                    // Keyword is not Present Dictionary and It will be Added in Dictionary
                    if(current->keyword != k){
                        // Adding new keyword to left child of current node
                        if(current->keyword > k){
                            if(current->left == NULL){
                                current->left = create_keyword(k);
                                return true;
                            }
                            current = current->left;
                        }
                        // Adding new keyword to right child of current node
                        else{
                            if(current->right == NULL){
                                current->right = create_keyword(k);
                                return true;
                            }
                            current = current->right;
                        }
                    }
                    // Keyword already Present in Dictionary
                    else return false;
                }
            }
        }

        // This will add new keyword in dictionary
        // This will update meaning of keyword
        bool update_meaning(string k){
            Node* current = root;
            while (current != NULL)
            {
                // Keyword is Searched in Dictionary
                // And its meaning will be Updated
                if(current->keyword == k){
                    cout<<"Keyword \""<<k<<"\" with Meaning \""<<current->meaning<<"\" is Present in Dictionary."<<endl;

                    cout<<"Enter Updating Meaning of Keyword \""<<k<<" : ";
                    cin.ignore();
                    getline(cin, current->meaning);

                    return true;
                }

                // Keyword is not yet Searched in Dictionary
                // This will traverse till current becomes equal to NULL
                else{
                    if(current->keyword > k){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
            }

            // Required Keyword is not Present in Dictionary
            return false;
        }

        Node* findMinimum(Node* current)
        {
            while(current->left != NULL) {
                current = current->left;
            }
            return current;
        }

        // This will delete keyword from dictionary
        bool delete_keyword(string k){
            Node *current = root, *parent = root, *next = root;
            while (current != NULL)
            {
                if(current->keyword == k){

                    // This means deleting node is leaf node i.e don't have left and right node
                    // So, simply delete current
                    if(current->left == NULL && current->right == NULL){
                        if(parent->left == current){
                            parent->left = NULL;
                        }
                        else{
                            parent->right = NULL;
                        }
                        delete current;
                    }

                    // VIMP NOTE
                    // This means deleting node is non leaf node having both left and right node
                    // For this we are traversing in right sub tree of deleting node to replace deleting node with lowest value of right sub tree of current
                    else if(current->left != NULL && current->right != NULL){
                        Node* successor  = findMinimum(current->right);

                        string keyword = successor->keyword;
                        string meaning = successor->meaning;

                        delete_keyword(successor->keyword);

                        current->keyword = keyword;
                        current->meaning = meaning;
                    }

                    //This means deleting node is non leaf node having either left or right node but not both
                    // So, simply point next node to parent current node
                    else{

                        // Checking if non leaf node have either left or right node
                        if(current->left != NULL){
                            next = current->left;
                        }
                        else{
                            next = current->right;
                        }

                        // Pointing next node to parent current node
                        if(parent->left == current){
                            parent->left = next;
                        }
                        else{
                            parent->right = next;
                        }
                        delete current;
                    }

                    return true;
                }

                // Keyword is not yet Searched in Dictionary
                // This will traverse till current becomes equal to NULL
                else{
                    parent = current;
                    if(current->keyword > k){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
            }

            // Required Keyword is not Present in Dictionary
            return false;
        }

        // This will read keyword from dictionary
        // If keyword is present in dictionary --> return number of comparisons required to find or read keyword
        // Else --> return 0
        int search_keyword(string k){
            Node* current = root;

            // This variable will calculate number of comparison required to Search the keyword in Dictionary
            int comparison = 0;
            while (current != NULL)
            {
                comparison++;
                // Keyword is Searched in Dictionary
                if(current->keyword == k){
                    return comparison;
                }

                // Keyword is not yet Searched in Dictionary
                // This will traverse till current becomes equal to NULL
                else{
                    if(current->keyword > k){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
            }

            // Required Keyword is not Present in Dictionary
            return 0;
        }

        // This will display keywords in ascending order of keywords
        // This is simple inorder traversal of BST
        void ascending_keywords(Node* current){
            if(current != NULL){
                ascending_keywords(current->left);
                cout<<current->keyword<<" ---> "<<current->meaning<<endl;
                ascending_keywords(current->right);
            }
        }

        // This will display keywords in descending order of keywords
        // This is simple inorder traversal of swapped node BST
        void descending_keywords(Node* current){
            swapping_nodes(current);
            ascending_keywords(current);
            swapping_nodes(current);
        }

        // This will swap the left child and right child node of parent node
        void swapping_nodes(Node* current){
            Node* temp;
            if(current != NULL){
                swapping_nodes(current->left);
                swapping_nodes(current->right);

                // Swapping nodes of current node
                temp = current->left;
                current->left = current->right;
                current->right = temp;
            }
        }
};

int main(){
    Dictionary D;
    string keyword;

    // Menu for Operations of Dictionary
    while (1)
    {
        cout<<"\n1. Add New Keyword."<<endl;
        cout<<"2. Search Keyword."<<endl;
        cout<<"3. Update Meaning of Keyword."<<endl;
        cout<<"4. Delete Keyword."<<endl;
        cout<<"5. Display of Keywords in Ascending Order."<<endl;
        cout<<"6. Display of Keywords in Descending Order."<<endl;
        cout<<"7. Exit.\n"<<endl;

        int choice;
        // Reading choice from user
        cout<<"Enter your choice from Above Menu : ";
        cin>>choice;

        if(choice >= 1 && choice <= 4){
            cout<<"Enter Keyword : ";
            cin>>keyword;
            int len = keyword.length();

            // Converting keyword to lowercase
            for (int i = 0; i < len; i++)
            {
                keyword[i] = tolower(keyword[i]);
            }

            if(choice == 1){
                if(D.add_keyword(keyword)) cout<<"Keyword \""<<keyword<<"\" is Added inside Dictionary."<<endl;
                else cout<<"Keyword \""<<keyword<<"\" is Not Present in Dictionary."<<endl;
            }

            else if(choice == 2){
                if(D.search_keyword(keyword)) {
                    cout<<"Keyword \""<<keyword<<"\" is Present in Dictionary."<<endl;
                    cout<<D.search_keyword(keyword)<<" Comparison are required to Find keyword \""<<keyword<<"\" from Dictionary."<<endl;
                }
                else cout<<"Keyword \""<<keyword<<"\" is Not Present in Dictionary."<<endl;
            }

            else if(choice == 3){
                if(D.update_meaning(keyword)) cout<<"Meaning of Keyword \""<<keyword<<"\" is Updated Successfully."<<endl;
                else cout<<"Keyword \""<<keyword<<"\" is Not Present in Dictionary."<<endl;
            }

            else{
                if(D.delete_keyword(keyword)) cout<<"Keyword \""<<keyword<<"\" is Deleted form Dictionary."<<endl;
                else cout<<"Keyword \""<<keyword<<"\" is Not Present in Dictionary."<<endl;
            }
        }
        else if(choice == 5){
            cout<<"\nKeywords and their meaning in Ascending Order : "<<endl;
            D.ascending_keywords(D.get_root());
        }
        else if(choice == 6){
            cout<<"\nKeywords and their meaning in Descending Order : "<<endl;
            D.descending_keywords(D.get_root());
        }
        else if(choice == 7){
            cout<<"Program Exit."<<endl;
            break;
        }
        else{ // Invalid Choice
            cout<<"Enter a valid choice."<<endl;
        }
    }

    return 0;
}