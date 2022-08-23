#include<iostream>
using namespace std;

class Node{
    int flag;
    Node* next;
    union
    {
        char data;
        Node* down;
    }s;
    
    public:
        Node(){
            flag = -1;
            next = NULL;
            s.data = '\0';
            s.down = NULL;
        }

    friend class gll;
};

class gll{
    Node* head = new Node();

    public:
        void create(Node* current){
            int choice2;
            while (1)
            {
                cout<<"\n1.Add Node"<<endl;
                cout<<"2.Add Sub Node"<<endl;
                cout<<"3.Exit"<<endl;

                cout<<"\nEnter your Choice : ";
                cin>>choice2;

                if(choice2 == 1){
                    cout<<"\nEnter Data : ";
                    if(current->flag == -1){
                        current->flag = 0;
                        cin>>current->s.data;
                    }
                    else{
                        Node* new_node = new Node();
                        new_node->flag = 0;
                        cin>>new_node->s.data;
                        current->next = new_node;
                        current = new_node;
                    }
                }

                else if(choice2 == 2){
                    if(current->flag == 0){
                        Node* new_node = new Node();
                        new_node->flag = 1;
                        current->next = new_node;
                        current = new_node;
                    }
                    else if(current->flag == -1){
                        current->flag = 1;
                    }
                    Node* temp = new Node();
                    current->s.down = temp;
                    create(temp);
                }

                else{
                    return;
                }
            }
        }

        void display(Node* h){
            cout<<"(";
            while (h != NULL)
            {
                if(h->flag == 0){
                    cout<<" "<<h->s.data<<" ";
                }
                else if(h->flag == 1){
                    display(h->s.down);
                }
                h = h->next;
            }
            cout<<" )";
            return;
        }

        Node* get_head(){
            return head;
        }

        void set_head(){
            head = new Node();
        }
};

int main(){
    int choice1;
    gll g;

    while (1)
    {
        cout<<"\n1.Create GLL"<<endl;
        cout<<"2.Display GLL"<<endl;
        cout<<"3.Exit"<<endl;

        cout<<"\nEnter your Choice : ";
        cin>>choice1;

        if(choice1 == 1){
            g.set_head();
            cout<<"\n\nEnter Generalized Linked List : "<<endl;
            g.create(g.get_head());
        }
        else if(choice1 == 2){
            cout<<"\nGeneralized Linked List is : ";
            g.display(g.get_head());
            cout<<endl;
        }
        else{
            cout<<"Thank You"<<endl;
            break;
        }
    }
    
    return 0;
}